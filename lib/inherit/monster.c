/*
 *    file                    /inherit/monster.c
 *    description             base object for all monsters 
 *    coders                  dazzt, namhas
 * 
 * */

inherit "/inherit/living";
inherit "/inherit/living/chook";
inherit "/inherit/living/receive";
inherit "/inherit/living/money";
inherit "/inherit/living/eq_system";

#define RACE_FILE "/data/monster/races"
#define PREV previous_object()

#define WANDER_NO    0
#define WANDER_AREA  1
#define WANDER_DIST  2
#define WANDER_PATH  3

#define HBOFF_DELAY    120

/*        -- --  variables  -- --                                         */

/* FLAGS */

int undead;                  /* is monster undead? */

object switch_object;     

int sclear;                  /* what's this? */

int wander;                  /* 0 : no wander
			      * 1 : wander randomly in area
			      * 2 : wander max 'wander_distance' rooms from
			      *     starting location
			      * 3 : wander with specific path */
int wander_delay;
static int wander_counter;

int wander_distance;         /* how far it can wander */
string *wander_path;         /* array for storing paths */

int pick;                    /* chance to pick / drop objects in 100 */
int drop;

static string *aggressive_list;     /* list of ppl monster is aggressive */
int aggressive;              /* will monster attack players? */

int wimpy_when;              /* when to check wimpy? (%:s of hp left) */
int wimpy_chance;            /* chance of wimpying when ^^ */

string *talk;
static string prev_talk;
string *emote;
static string prev_emote;

int talk_delay;
int emote_delay;
static int talk_counter = 30 + random(30);
static int emote_counter = 30 + random(30);

static int hboff_counter;

/*        -- --  function prototypes  -- --                               */

string set_name(mixed);

////  monster ability/creation related

int set_levels(mapping levels);
string set_race(string);

//// EQ

void add_object(object);
void add_weapon(object);
void add_armour(object);

//// behaviour 

varargs int set_wander(int, int, mixed);
void set_talk(mixed);
int set_language(string);   /* if language is not defined, monster speaks common */      
void set_emote(mixed);

int set_talk_delay(int);
int set_emote_delay(int);

int set_move(int delay);
int set_pick(int);
int set_drop(int);
int set_aggressive();
void set_wimpy(int, int);

int add_aggressive(string name);
//// misc 

void rehash_hpspep();
string stat_me();

/* * * * * * * 
 * 
 *  MONSTER CREATION CODE
 * 
 * * * * * * * * * * * * * * * * * * * * */

//  create()                          driver apply, called when cloning
//  coder                             dazzt, namhas

void create()
{
    ::create();

    /* initialize hit locations */

    THOB->init_location ("humanoid");

    /* default stats */	

    THOB->set_height(1);
    THOB->set_hp(50);
    THOB->set_max_hp(50);
    THOB->set_ep(50);
    THOB->set_sp(50);

    THOB->set_str (10);
    THOB->set_dex (10);
    THOB->set_agi (10);
    THOB->set_con (10);
    THOB->set_stu (10);
    THOB->set_siz (10);
    THOB->set_int (10);
    THOB->set_wis (10);
    THOB->set_pow (10);
    THOB->set_cha (10);

    /* monsters speak common unless otherwise defined */

    THOB->set_skill_chance("sartog", 100);
    THOB->set_current_language("sartog");

	THOB->set_race("human");
    THOB->create_monster();        
    enable_commands();
    is_npc = 1;
    add_action("commandHook", "", 1);

    aggressive_list = ({ });
}

//  init()                            driver apply
//  coder                             namhas

void start_hb()
{
    set_heart_beat(1);
}

void init(object from)
{
    THOB->init_monster();
	if (name)
		set_living_name(name);
    THOB->start_hb();
    if (aggressive && interactive(PREV) && PREV != THOB)
	add_aggressive(PREV->query_name());
    if (member_array(PREV->query_name(), aggressive_list) >= 0)
    {                                 /* start battle */
        command("say Prepare to meet your doom, " + PREV->query_cap_name() +"!");
        THOB->begin_battle(PREV);
    }
}

//  setup()                           driver apply
//  coder                             namhas

void setup()
{
    set_living_name(name);
    enable_commands();
    set_heart_beat(1);
    add_action("commandHook", "", 1);
}

//  set_name(string | string * )      define monster names  
//  coder                             dazzt   

string set_name(mixed s)
{
    ::set_name(s);
    set_living_name(name);
}

//  add_object(string file)           adds an object into monster inventory
//  coder                             namhas

add_object(string str)
{
    object ob;

    if (ob = clone_object(str))
	ob->move(THOB);
}

//  add_armour(string file)           adds armour to monster
//  coder                             dazzt

add_armour(string file)
{
    object ob;

    if (ob = clone_object(file))
    {
	ob->move(THOB);
	wear_eq(ob);
    }
}

//  add_weapon(string file)           adds weapon to monster
//  coder                             dazzt

add_weapon(string file)
{
    object ob;

    if (ob = clone_object(file))
    {
	ob->move(THOB);
	wield_eq(ob);
    }
}

//  set_talk(string | string *)       loads monster chat
//  coder                             namhas

set_talk(mixed str)
{
    if (!arrayp(str))
	talk = ({ str });
    else
	talk = str;
    if (!talk_delay)
	talk_delay = 60 + random(60);
}

//  set_talk_delay(int)               defines delay between talks
//  coder                             dazzt

int set_talk_delay(int i)
{
    return talk_delay = i;
}

//  set_language(string)              defines alternative language 
//  coder                             dazzt

int set_language(string s)
{
    if (set_current_language(s) == 1)
    {
	THOB->set_skill_chance(s, 100);
	return 1;
    }
    else 
	return 0;
}

//  set_move(int delay)               set wandering delay
//  coder                             dazzt

int set_move(int delay)
{
    wander_delay = delay;
}

//  set_emote(string | string *)      loads monster emotes
//  coder                             namhas

set_emote(mixed str)
{
    if (!arrayp(str))
	emote = ({ str });
    else
	emote = str;
    if (!emote_delay)
	emote_delay = 60 + random(60);
}

//  set_emote_delay(int)              defines delay between emotes
//  coder                             dazzt

int set_emote_delay(int i)
{
    return emote_delay = i;
}

//  set_wander(int, int, int | string *)   allows monster to wander
//  coder                                  dazzt
//
//  set_wander(0);                - no wander
//  set_wander(1, delay);         - wander area with random 'delay'
//  set_wander(2, delay, dist)    - wanders max. 'dist' rooms away
//  set_wander(3, delay, dirs)    - performs commands in 'dirs' array

varargs int set_wander(int wtype, int wdelay, mixed wdata)
{
    if (!wtype)
    {
	wander = 0;
	return 0;
    }

    wander = wtype;
    wander_delay = wdelay;
    wander_counter = random(wander_delay - wander_delay * 4 / 5) + wander_delay * 4 / 5;

    if (wander == 2)
	wander_distance = wdata;

    if (wander == 3)
    {
	if (!arrayp(wdata))
	    return 0;
	wander_path = wdata;
	wander_distance = 0;
    }
    return 1;
}

//  set_levels(mapping)                  set monster level
//  coder                                dazzt

#define M_STR 0
#define M_DEX 1
#define M_AGI 2
#define M_CON 3
#define M_INT 4
#define M_WIS 5
#define M_POW 6
#define M_CHA 7
#define M_SIZ 8
#define M_STU 9

private float frand(float r) { return (random(r * 32768) / 32768.0); }

int set_levels(mapping levels)
{
    float *modifiers = allocate(10);
    string type;
    float tmp;
    int level, i, sz;

    if (!levels)
	return 0;

    for (i = 0; i < sizeof(modifiers); i++)
	modifiers[i] = 1.0;

    for (i = 0, sz = sizeof(keys(levels)); i < sz; i++)
    {
	type = keys(levels)[i];
	level = levels[type];

	switch (lower_case(type))
	{                             /* maybe these should be read from file? */
	case "fighter" : 
	    tmp = level * 0.05 * 7.0 / 10.0 + frand(level * 0.03 * 4 / 10);
	    modifiers[M_STR] += tmp;
	    modifiers[M_AGI] += tmp;
	    modifiers[M_STU] += tmp / 2;
	    modifiers[M_DEX] += tmp / 3;
	    modifiers[M_POW] += tmp / 2;
		set_skill_chance("combat", level);
		set_skill_chance("dodge", level);
	    break;

	case "caster" : 
	    tmp = level * 0.05 * 7.0 / 10.0 + frand(level * 0.03 * 4 / 10);
	    modifiers[M_INT] += tmp;
	    modifiers[M_WIS] += tmp;
	    modifiers[M_POW] += tmp;
	    modifiers[M_DEX] += tmp / 2;
	    break;

	default : return 0;
	}
    }

    for (i = 0; i < sizeof(modifiers); i++)
	maximum_stats[i] = (current_stats[i] *= modifiers[i]);

    rehash_hpspep();

    return 1;
}

//  set_race(string)                        set monster race
//  coder                                   dazzt

string set_race(string arg)
{
    string *racefile;
    int *s = allocate(10);
    string raceline, r;
    int i, typ;

    if (file_size(RACE_FILE) < 0)
	return 0;

    racefile = explode(read_file(RACE_FILE), "\n");

    i = 0;

    do
    {
	if (racefile[i][0..0] != "#")
	{
	    r = racefile[i][0..22];
	    while (r[<1..<1] == " ")
		r = r[0..<2];

	    if (lower_case(arg) == lower_case(r))
	    {
		raceline = racefile[i][20..<1];
		race = r;
		break;
	    }
	}
	i++;
    } while (i < sizeof(racefile));

    if (i == sizeof(racefile))
	return 0;

    // race   str dex agi stu con int wis pow cha siz typ bal ext
    sscanf(raceline, "%s %d %d %d %d %d %d %d %d %d %d",
      arg, 
      s[M_STR], s[M_DEX], s[M_AGI], s[M_STU], s[M_CON], 
      s[M_INT], s[M_WIS], s[M_POW], s[M_CHA], s[M_SIZ], typ);

    if (typ == 4)
	THOB->init_location ("mammal");
    else
	THOB->init_location ("humanoid");

    for (i = 0; i < 10; i++)
	maximum_stats[i] = current_stats[i] = s[i];

    rehash_hpspep();

    return race;
}

//  set_undead()                       turns monster into undead one
//  coder                              dazzt

int set_undead()
{
    return undead = 1;
}

//  set_pick(int chance)               monster pick chance in %:s
//  coder                              dazzt

int set_pick(int chance)
{
    pick = chance;
}

//  set_drop(int chance)               chance to drop objects in %:s
//  coder                              dazzt

int set_drop(int chance)
{
    drop = chance;
}

//  set_aggressive()                   turns monster into aggressive
//  coder                              dazzt

int set_aggressive()
{
    aggressive = 1;
}

//  set_wimpy(int when, int chance)    set wimpy chance
//  coder                              dazzt

void set_wimpy(int when, int chance)
{
    wimpy_when = when;
    wimpy_chance = chance;
}

//  rehash_hpspep()                    recalculates hps, sps and eps
//  coder                              dazzt, formulas by ondoval

void rehash_hpspep()
{
/*
    max_hp = to_int((0.95 + frand(0.1)) * 
      (query_con() * 2.75 + query_stu() * 4 + query_str() * 2 + 
	query_pow() * 2 + query_weight() / 5 / 1000 + query_height() / 15));
    max_sp = to_int((0.95 + frand(0.1)) * 
      (query_pow() * 4 + query_wis() * 3 + query_int() * 3 + query_con()));
    max_ep = to_int((0.95 + frand(0.1)) *
      (query_con() * 3 + query_str() * 2 + query_pow() * 2 + query_agi() + 
	query_stu()));
    hp = max_hp;
    sp = max_sp;
    ep = max_ep;
*/
    hp=query_max_hp();
    sp=query_max_sp();
    ep=query_max_ep();
}

int query_aggressive()
{
    return aggressive;
}

string *query_aggressive_list()
{
    return aggressive_list;
}

int add_aggressive(string name)
{
    if(member_array(name, aggressive_list) == -1)
	aggressive_list += ({name});
    return 1;
}

/* * * * * * * * * * *
 * 
 *    'INTERACTIVE' CODE
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */

//  heart_beat()                      driver apply, called every hb
//  coders                            dazzt, namhas

void heart_beat()
{
    object *inv;
    string *dest, *dir;
    int i, sz;

    living::heart_beat();

    // check if no interactives exist in the same room to turn hb off

    hboff_counter++;
    if (hboff_counter == HBOFF_DELAY && ENV(THOB))
    {
	inv = all_inventory(ENV(THOB));
	for (i = 0, sz = sizeof(inv); i < sz; i++)
	    if (interactive(inv[i]))
		break;
	if (i == sz)
	    set_heart_beat(0);
	hboff_counter = 0;
    }

    // check for wimpy (with chance=100%, mobs really _RUN_ :)
    if (sizeof(THOB->query_battle()) > 0 && (wimpy_when > (100 * hp / query_max_hp())))
    {
	if (random(100) < wimpy_chance)
	{
	    dir = ENV(THOB)->query_exit_dir();
	    if (dir != ({ }))
		command(dir[random(sizeof(dir))]);
	}
    }

    // chat a bit

    if (talk)
    {
	talk_counter--;
	if (talk_counter <= 0)
	{
	    i = random(sizeof(talk));
	    if (sizeof(talk) > 1)
		while (talk[i] == prev_talk)
		    i = random(sizeof(talk));
	    if (talk[i])
		"/command/mortal/say"->main(talk[i]);
	    talk_counter = random(talk_delay - talk_delay * 4 / 5) + talk_delay * 4 / 5;
	    prev_talk = talk[i];
	}
    }

    // do emotes

    if (emote)
    {
	emote_counter--;
	if (emote_counter <= 0)
	{
	    i = random(sizeof(emote));
	    if (sizeof(emote) > 1)
		while (emote[i] == prev_emote)
		    i = random(sizeof(emote));
	    if (emote[i])
		message("emote", emote[i] + "\n", all_inventory(ENV(THOB)));
	    emote_counter = random(emote_delay - emote_delay * 4 / 5) + emote_delay * 4 / 5;
	    prev_emote = emote[i];
	}
    }

    // pick objects

    if (pick && random(100) < pick)
    {
	if (ENV(THOB))
	{
	    inv = all_inventory(ENV(THOB));
	    if (arrayp(inv) && sizeof(inv) >= 1)
	    {
		i = random(sizeof(inv));
		if (i > -1 && inv[i])
		    "/command/mortal/get"->main(inv[i]->query_name());
	    }
	}
    }

    // drop objects

    if (drop && random(100) < drop)
    {
	if (ENV(THOB))
	{
	    inv = all_inventory(THOB);
	    if (arrayp(inv) && sizeof(inv) >= 1)
	    {
		i = random(sizeof(inv));
		if (i > -1 && inv[i])
		    "/command/mortal/drop"->main(inv[i]->query_name());
	    }
	}
    }

    // wander around

    if (wander && (sizeof(THOB->query_battle()) == 0))
    {
	wander_counter--;
	if (wander_counter <= 0)
	{
	    dir = ENV(THOB)->query_exit_dir();
	    dest = ENV(THOB)->query_exit_dest();

	    switch (wander)
	    {
	    case WANDER_AREA :     /* wander randomly in area */

		i = random(sizeof(dest));
		if (dest[i] && 
		  !dest[i]->query_no_monster() &&
		  (dest[i]->query_area() == ENV(THOB)->query_area()))
		    command(dir[i]);
		break;

	    case WANDER_DIST :     /* wander with specific distance */

		if (!wander_path)
		    wander_path = ({ });

		if (sizeof(wander_path) < wander_distance)
		{
		    i = random(sizeof(dest));
		    if (dest[i] && !dest[i]->query_no_monster())
		    {
			wander_path += ({ file_name(ENV(THOB)) });
			command(dir[i]);
		    }
		}
		else
		{
		    i = member_array(wander_path[sizeof(wander_path) - 1], dest);
		    if (i != -1)
		    {
			command(dir[i]);
			wander_path -= ({ file_name(ENV(THOB)) });
		    }
		    else
		    {
			i = member_array(wander_path[sizeof(wander_path) - 1] + ".c", dest);
			if (i != -1)
			{
			    command(dir[i]);
			    wander_path -= ({ file_name(ENV(THOB)) });
			}
			else
			    command("emote looks very confused");
		    }
		}
		break;

	    case WANDER_PATH :    /* wander along pre-set path */

		if (!wander_path)
		    break;

		command(wander_path[wander_distance]);

		wander_distance++;
		if (wander_distance >= sizeof(wander_path))
		    wander_distance = 0;

		break;
	    } // switch 
	    wander_counter = random(wander_delay - wander_delay * 4 / 5) + wander_delay * 4 / 5;
	} // wander_delay
    } // wander
} // hb

//  force_us(string)                  force function
//  coder                             namhas

force_us(string cmd)
{
    command(cmd);
}

//  string stat_me()                  some statistics
//  coder                             dazzt

string stat_me()
{
    string str;

    str = living::stat_me() + "MONSTER OBJECT\n";

    str += "  switch       : " + (switch_object ? switch_object->short() : "-") + "\n";
    str += "  wander       : ";
    switch (wander)
    {
    case 0 : str += "not wandering"; break;
    case 1 : str += "wandering at area '" + ENV(THOB)->query_area() + "'"; break;
    case 2 : str += "wandering " + wander_distance + " rooms from " + 
	(wander_path ? "'" + wander_path[sizeof(wander_path) - 1] +  "'" : "here"); break;
    case 3 : str += "wandering with path: '" + implode(wander_path, "', '") + "'"; break;
    default : str += "bugging"; break;
    }
    str += "\n";

    str += "  pick objects : " + pick + "%\n";
    str += "  drop objects : " + drop + "%\n";

    return str;
}

object query_switch_object()
{ 
    return switch_object; 
}

long()
{
    string buf = "";

    if (THIS->query_security())
	buf = "(" + file_name(THOB) + "):\n" + living::long();
    else
	buf = living::long() + "\n";

    return wrap(buf)+THOB->query_shapestring(1);
}
