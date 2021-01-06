#include "/home/project/areas/courthouse/path.h"
main (string str)
{
    object ob;

   if (str)
    if(ob=find_player(str))
    {
	tell_object (ob, "You have beed summoned by the God of "
	+ "Justice to follow the proceedings that are of consequence to "
	+ "you.\n");
	message("standard",capitalize(str)+" is "
        + "summoned to the Divine Court.\n",environment(ob),ob);
	write(capitalize(str)+" summoned!\n");
	message("announce",capitalize(str)+" has been summoned by "
	+capitalize(THIS->query_name())+"!\n",users());
	ob->move_player(ROOM_PATH+"court.c");
	return 1;
    }
    else
    {
	notify_fail ("No such living thing.\n");
	return 0;
    }
    else
    {
	message("0","Hearye hearye! All the players in the realms are "
	+ "hereby summoned to attend to the proceedings of the Divine "
	+ "court, and are forced to leave whatever they are doing!\n",
	users());
	users()->move_player(ROOM_PATH+"court.c");
    }
}

