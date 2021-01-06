/****
*  *    Name                    explore_plaque.c
* *     Description             Shows top explorers in game
**      Coder                   Dazzt
*/

#include <level.h>
inherit BASE;


#define SAVEFILE        "/data/plaque/explore"
#define NUM_PLAYERS             100
#define UPDATE_TIME             5 * 60
#define CLEANUP_TIME            14 * (60 * 60 * 24)

mapping players = ([ ]);       /* list of players and e%:s */

static string *order;   /* names of best players */



create()
{
    restore_object(SAVEFILE);

    if (!players)
	players = ([ ]);

    set_name ("plaque");
    set_short("a massive golden plaque labeled \"top explorers\"");

    call_out("update_eplaque", UPDATE_TIME);
}

sort_eplaque()
{
    int i;
    mixed *p = values(players);
    string *s = keys(players);
    int *count = allocate(101);
    int *idxcount = allocate(101);
    int *counters = allocate(101);
    int cnt, val;

    order = allocate(sizeof(players));

    for (i = 0; i < sizeof(p); i++)
	count[p[i][0]]++;

    for (i = 0; i < 101; i++)
    {
	idxcount[i] = cnt;
	cnt += count[i];
    }

    for (i = 0; i < sizeof(players); i++)
    {
	val = p[i][0];
	order[idxcount[val] + counters[val]] = s[i];
	counters[val]++;
    }
}



update_eplaque()
{
    int i;
    object *u = users();
//  int *p = values(players);
    string *s = keys(players);

    /*   Update plaque for current players in game
    */

    for (i = 0; i < sizeof(u); i++)
	if (u[i]->query_security() < 2)
	    players[u[i]->query_name()] = ({ u[i]->query_explore_percent(), time() });

	/*   Do simple bucket sort on player e%:s.
	*/
    sort_eplaque();

    /*   Remove players who haven't been on for a while or have wizzed from plaque.
    */

    for (i = 0; i < sizeof(s); i++)
    {
	if ((players[s[i]][1] - time()) > CLEANUP_TIME)
	{
	    map_delete(players, s[i]);
	    continue;
	}
	if (s[i])
	{
	    if (find_player(s[i]))
	    {
		if (find_player(s[i])->query_security() >= 2)
		    map_delete(players, s[i]);
	    }
	}
    }

    /*   Save our plaque
    */
    save_object(SAVEFILE);

    /*   and call us again ..
    */
    call_out("update_eplaque", UPDATE_TIME);

    return 1;
}


long()
{
    int i, l, min;

    remove_call_out("update_eplaque");
    update_eplaque();

    write("This ancient plaque has been shaped from a single piece of gold.\n");
    write("Only the names of the most experienced explorers have their name \n");
    write("carved into this plaque. \n\n");

    write(" -=-=-=-=-=-=( Top Explorers )=-=-=-=-=-=-\n\n");

    l = sizeof(order);
    if (l > NUM_PLAYERS)
	l = NUM_PLAYERS;

    if ((l - 1) > 10)
	min = l - 10;
    else
	min = 0;

    for (i = l - 1; i >= min; i--)
	if (order[i])
	    write(sprintf(" %3d. %-30s %5d%%\n", l - i, capitalize(order[i]),
		players[order[i]][0]));

    write("\n");
}

get()
{
    write("It's firmly attached into the ground.\n");
    return 0;
}

