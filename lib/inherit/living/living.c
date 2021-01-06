#pragma strict_types

// FILE NAME     : /inherit/living.c
// DESCRIPTION   : living inheritable - inherited to every living object
// CODER         : namhas, dazzt
// LAST MODIFIED : Thu Nov 20 18:15:00 EET DST - Ondoval

inherit BASE;
//inherit "/inherit/living/hitloc";
inherit "/inherit/living/battle";
inherit "/inherit/living/skill_system";

// global definations :

#define pline(x)        message ("0", x, THOB)
#define room(x)         message ("3", x, ENV(THOB) ? ENV(THOB) : THOB, THOB)

#define S_STR           0
#define S_DEX           1
#define S_AGI           2
#define S_CON           3
#define S_INT           4
#define S_WIS           5
#define S_POW           6
#define S_CHA           7
#define S_SIZ           8
#define S_STU           9

// saveable variables :

string race;             // true race
string subrace;          // subrace

int gender;              // 0 = neuter, 1 = male, 2 = female

int hp;                  // current hit points
int sp;                  // current spell points
int ep;                  // current endurance points

int is_uncon;            // 1 if unconscious, 0 otherwise
int is_dead;             // 1 if dead, 0 if not.

int r_spl;		 // spells learn rate
int r_arc;		 // arcane skills learn rate
int r_com;		 // combat skills learn rate
int r_mec;		 // mechanical skills learn rate
int r_soc;		 // social skills learn rate
int r_edu;		 // educational skills learn rate
int r_gen;		 // general skills learn rate

int min_sight;           // minimum light level
int max_sight;           // maximum light level

int age;                 // age in heart beats
int max_age;             // maximum age in game years

int beat;                // how fast the living regens, smaller number
// means faster regen if 0 the default 15
// is set

int alx;                 // alignment x: good, neutral or evil
int aly;                 // alignment y: lawful, neutral or chaotic

int is_npc;              // flag to determine is the living object npc or pc

int brief;               // for dazzt

int *current_stats;      // array of current stats
int *maximum_stats;      // array of maximum stats

int *grid_xy;            // gridmap coordinates

string *ms;              // array of various messages

string current_language; // language living is currently speaking

// non-saveable variables :

static int light;        // the amount of light living carries
static int tick;
static int clean_up;
static int resting;     //resting status

// function prototypes (no applies) :

int move_player (mixed, string);

// DESCRIPTION : initializes object
// CODER       : dazzt, namhas

void
create ()
{
    ms = allocate(4);
    clean_up = 0;

    ms[0] = "arrives";
    ms[1] = "leaves";
    ms[2] = "arrives in a puff of smoke";
    ms[3] = "leaves in a puff of smoke";

    race  = "raceless";

    current_stats = allocate(10);
    maximum_stats = allocate(10);
    THOB->set_bodytype("humanoid");
    THOB->initialize_skillmap();
    set_heart_beat (1);
}

int *
query_gridmap ()
{
    if (!grid_xy)
	grid_xy = ({ 1 + random(3), 1 + random(3) });

    return grid_xy;
}

int *
set_gridmap (int x, int y)
{
    if (x < 0)
	x = 0;

    if (y < 0)
	y = 0;

    if (y > 5)
	y = 5;

    if (x > 8)
	x = 8; 

    return grid_xy = ({ x, y });
}

// DESCRIPTION : moves player to another location
// CODER       : dazzt, namhas

int
move_player (mixed target, string direction)
{
    int is_light;
    string reverse, file;
    object *inv;

    if(resting && direction)
    {
	pline("You can't move while resting. Stand up first.\n");
	return 1;
    }
    if (objectp (target))
    {
	if (!invis || !sneak)
	    if (!direction)
		room (cap_name + " " + ms[3] + ".\n");
	    else
		room (cap_name + " " + ms[1] + " " + direction + ".\n");

	move (target);
	return 1;
    }

    switch (direction)
    {
    case "north" : reverse = "south"; break;
    case "west"  : reverse = "east";  break;
    case "south" : reverse = "north"; break;
    case "east"  : reverse = "west";  break;

    case "northwest" : reverse = "southeast"; break;
    case "northeast" : reverse = "southwest"; break;
    case "southwest" : reverse = "northeast"; break;
    case "southeast" : reverse = "northwest"; break;

    case "up"   : reverse = "down"; break;
    case "down" : reverse = "up";   break;

    case "enter" : reverse = "outside"; break;
    case "out"   : reverse = "inside";  break;
    }

    if (target && target[<2..] != ".c")
	file = target + ".c";
    else
	file = target;

    if (sizeof(file) && file_size (file) < 0 && !target->query_terrain ())
    {
	if (!direction)
	    pline ("A strong force stops your movement.\n");
	else
	    pline ("A strong force stops you from going " + direction + ".\n");

	return 1;
    }

    if (ENV(THOB))
    {
	is_light = ENV(THOB)->query_light_level();

	if (is_light > 0)
	{
	    if (!invis || !sneak)
		if (!direction)
		    room (cap_name + " " + ms[3] + ".\n");
		else
		    room (cap_name + " " + ms[1] + " " + direction + ".\n");
	}
	else
	if (!invis || !sneak)
	    room ("You see someone moving in the shadows.\n");
    }

    move (target);

    if (!ENV(THOB))
    {
	pline ("You are nowhere.\n");
	return 1;
    }

    if (!virtualp (ENV(THOB)))
	THOB->add_explore (EXPLORE_D->query_number (file_name (ENV(THOB))));

    is_light = ENV(THOB)->query_light_level();

    if (is_light > 0)
    {
	if (!invis || !sneak)
	    if (!direction)
		room (cap_name + " " + ms[2] + ".\n");
	    else if (reverse)
		room (cap_name + " " + ms[0] + " from " + reverse + ".\n");
	    else
		room (cap_name + " " + ms[0] + ".\n");
    }
    else if (!invis || !sneak)
	room ("You see someone moving in the shadows.\n");

    inv = all_inventory(ENV(THOB));

    for (int i=0;i<sizeof(inv);i++) {
	if (inv[i]->query_known())
	{
	    if (member_array(name, inv[i]->query_known()) == -1)
		inv[i]->add_known(name);
	}
    }

    if (THOB->query("brief"))
	"/command/mortal/blook"->main();
    else
	"/command/mortal/look"->main();


    if(!interactive(THOB))
    {
	object *obs=all_inventory(ENV(THOB));
	string *aggressive_list;
	for (int i=0; i<sizeof(obs); i++)
	{
	    if (!obs[i])
		continue;
	    if (THIS->query_aggressive() && interactive(obs[i]))
		THIS->add_aggressive(obs[i]->query_name() );
	    aggressive_list=THOB->query_aggressive_list();

	    if (member_array(obs[i]->query_name(), aggressive_list) >= 0)
	    { /* start battle */
		command("say Prepare to meet your doom, " + obs[i]->query_cap_name() + "!");
		THOB->begin_battle(obs[i]);
		break;
	    }
	}
    }
    return 1;
}

// DESCRIPTION: rest/stand
// CODER      : dranil

int set_resting() { return resting=1; }
int set_standing() { return resting=0; }
int query_resting() { return resting; }

// DESCRIPTION : various query_*(), add_*() and set_*() functions
// CODER       : dazzt, namhas

string query_pronoun()
{
    return (gender == 2) ? "she" : (gender == 1) ? "he" : "it";
}

string query_possessive()
{
    return (gender == 2) ? "her" : (gender == 1) ? "his" : "its";
}

string query_objective()
{
    return (gender == 2) ? "her" : (gender == 1) ? "him" : "it";
}

string set_race(string s) { return race = s; }
string set_subrace(string s) { return subrace = s; }
int set_gender(int i)     { return gender = i; }

int set_hp(int i)     { return hp = i; }
int set_sp(int i)     { return sp = i; }
int set_ep(int i)     { return ep = i; }

int set_r_spl(int i)     { return r_spl = i; }
int set_r_arc(int i)     { return r_arc = i; }
int set_r_com(int i)     { return r_com = i; }
int set_r_mec(int i)     { return r_mec = i; }
int set_r_soc(int i)     { return r_soc = i; }
int set_r_edu(int i)     { return r_edu = i; }
int set_r_gen(int i)     { return r_gen = i; }

int set_str(int i) { return current_stats[S_STR] = i; }
int set_dex(int i) { return current_stats[S_DEX] = i; }
int set_agi(int i) { return current_stats[S_AGI] = i; }
int set_con(int i) { return current_stats[S_CON] = i; }
int set_int(int i) { return current_stats[S_INT] = i; }
int set_pow(int i) { return current_stats[S_POW] = i; }
int set_wis(int i) { return current_stats[S_WIS] = i; }
int set_cha(int i) { return current_stats[S_CHA] = i; }
int set_siz(int i) { return current_stats[S_SIZ] = i; }
int set_stu(int i) { return current_stats[S_STU] = i; }

int set_max_str(int i) { return maximum_stats[S_STR] = i; }
int set_max_dex(int i) { return maximum_stats[S_DEX] = i; }
int set_max_agi(int i) { return maximum_stats[S_AGI] = i; }
int set_max_con(int i) { return maximum_stats[S_CON] = i; }
int set_max_int(int i) { return maximum_stats[S_INT] = i; }
int set_max_pow(int i) { return maximum_stats[S_POW] = i; }
int set_max_wis(int i) { return maximum_stats[S_WIS] = i; }
int set_max_cha(int i) { return maximum_stats[S_CHA] = i; }
int set_max_siz(int i) { return maximum_stats[S_SIZ] = i; }
int set_max_stu(int i) { return maximum_stats[S_STU] = i; }

int set_age(int i) { return age = i; }
int set_max_age(int i) { return max_age = i; }

int set_alignx (int i) { return alx = i; }
int set_aligny (int i) { return aly = i; }

int add_alignx (int i) { return alx += i; }
int add_aligny (int i) { return aly += i; }

int set_npc (int i) { return is_npc = 1; }

string set_msgin(string s)   { return ms[0] = s; }
string set_mmsgin(string s)  { return ms[1] = s; }
string set_msgout(string s)  { return ms[2] = s; }
string set_mmsgout(string s) { return ms[3] = s; }

string query_race() { return race; }
string query_subrace() { return subrace; }
int query_gender()  { return gender; }

int query_hp()     { return hp; }
int query_sp()     { return sp; }
int query_ep()     { return ep; }
int query_max_hp();
int query_max_sp();
int query_max_ep();

int add_hp(int i)
{
    hp+=i;
    if(hp<0&&!is_uncon)
      {
	if(!is_dead)
	  {
	    is_uncon=1;
	    tell_object(THOB,"You fall unconscious.\n");
	    if(hp<-query_max_hp()/2)
	      {
		tell_object(THOB,"You die.\n");
		is_dead=1;
		is_uncon=0;
	      }
	  }
      }

    return hp;
}

int query_is_unconscious() { return is_uncon;}
int query_is_dead() { return is_dead;}

int add_sp(int i)
{
    int spmx;
    spmx=query_max_sp();
    sp+=i;
    if(sp>spmx)
	sp=spmx;
    else
    if(sp<0)
	sp=0;
    return sp;
}
int add_ep(int i)
{
    int epmx;
    epmx=query_max_ep();
    ep+=i;
    if(ep>epmx)
	ep=epmx;
    else
    if(ep<0)
	ep=0;
    return ep;
}

/* for ordinary human hp: 100 ep: 100 sp: 100 */

int query_max_hp() { return (THOB->query_stu() * 5) +
    (THOB->query_siz() * 2) +
    (THOB->query_con() * 1) +
    (THOB->query_pow() * 1) +
    (THOB->query_str() * 1) ; }


int query_max_sp() { return (THOB->query_pow() * 5) +
    (THOB->query_int() * 2) +
    (THOB->query_wis() * 2) +
    (THOB->query_con() * 1) ; }

int query_max_ep() { return (THOB->query_con() * 5) +
    (THOB->query_str() * 2) +
    (THOB->query_pow() * 2) +
    (THOB->query_agi() * 1) ; }  

int query_r_spl()     { return r_spl; }
int query_r_arc()     { return r_arc; }
int query_r_com()     { return r_com; }
int query_r_mec()     { return r_mec; }
int query_r_soc()     { return r_soc; }
int query_r_edu()     { return r_edu; }
int query_r_gen()     { return r_gen; }

int query_str() { return current_stats[S_STR]; }
int query_dex() { return current_stats[S_DEX]; }
int query_agi() { return current_stats[S_AGI]; }
int query_con() { return current_stats[S_CON]; }
int query_int() { return current_stats[S_INT]; }
int query_pow() { return current_stats[S_POW]; }
int query_wis() { return current_stats[S_WIS]; }
int query_cha() { return current_stats[S_CHA]; }
int query_siz() { return current_stats[S_SIZ]; }
int query_stu() { return current_stats[S_STU]; }
int query_stat(string arg)
{
    switch (arg)
    {
    case "str":
	return current_stats[S_STR];
    case "dex":
	return current_stats[S_DEX];
    case "agi":
	return current_stats[S_AGI];
    case "con":
	return current_stats[S_CON];
    case "int":
	return current_stats[S_INT];
    case "pow":
	return current_stats[S_POW];
    case "wis":
	return current_stats[S_WIS];
    case "cha":
	return current_stats[S_CHA];
    case "siz":
	return current_stats[S_SIZ];
    case "stu":
	return current_stats[S_STU];
    }
    return 0;
}

int query_max_str() { return maximum_stats[S_STR]; }
int query_max_dex() { return maximum_stats[S_DEX]; }
int query_max_agi() { return maximum_stats[S_AGI]; }
int query_max_con() { return maximum_stats[S_CON]; }
int query_max_int() { return maximum_stats[S_INT]; }
int query_max_pow() { return maximum_stats[S_POW]; }
int query_max_wis() { return maximum_stats[S_WIS]; }
int query_max_cha() { return maximum_stats[S_CHA]; }
int query_max_siz() { return maximum_stats[S_SIZ]; }
int query_max_stu() { return maximum_stats[S_STU]; }

int *query_stats () { return current_stats; }
int *query_max_stats () { return maximum_stats; }

int *set_stats (int *i) { return current_stats = i; }
int *set_max_stats (int *i) { return maximum_stats = i; }

int query_height() { return current_stats[S_SIZ]*15; }
int query_weight() {
    return (1024*to_int((((current_stats[S_STU] * 5) +
	    (current_stats[S_STR] * 5)) * 
	  ((current_stats[S_SIZ]*5-10)))/70)+20);
}

int query_age() { return age; }
int query_max_age () { return max_age; }

int query_alignx() { return alx; }
int query_aligny() { return aly; }

int query_npc()         { return is_npc; }

string query_cap_name() { return cap_name; }

string query_msgin()   { return ms[0]; }
string query_mmsgin()  { return ms[1]; }
string query_msgout()  { return ms[2]; }
string query_mmsgout() { return ms[3]; }

void set_sight(int min, int max)
{
    min_sight=min;
    max_sight=max;
    return;
}
int set_max_sight(int max)
{
    return max_sight=max;
}
int set_min_sight(int min)
{
    return min_sight=min;
}

int query_min_sight()
{
    return min_sight;
}
int query_max_sight()
{
    return max_sight;
}

int query_sight_clarity(int light_level)
{
    if(light_level<min_sight)
	return -1;
    if(light_level>max_sight)
	return -2;
    return 0;
}

int query_light() { return light;}

void check_light()
{
    object o, *all;
    int max, min, ll;

    max=0; min=0;
    all=all_inventory(THOB);
    foreach (o in all)
    {
	if(o->query_light())
	{
	    ll=o->query_light();
	    if(ll>max)
		max=ll;
	    if(ll<min)
		min=ll;
	}
    }
    if(max>2)
	max=2;
    if(min<-2)
	min=-2;
    light=max+min;
    return;
}

void do_regen()
{
    int tmp, heal;
    tmp=query_max_hp()-query_hp();
    if(tmp>0)
    {
	if(resting)
	    heal=(int)(query_stu()/2+random(query_stu()/2));
	else
	    heal=(int)(random(query_stu()/2));
	if(heal>tmp)
	    heal=tmp;
	add_hp(heal);
    }
    if(query_sp()<query_max_sp())
    {
	if(resting)
	    add_sp((int)(query_pow()/2+random(query_pow()/2)));
	else
	    add_sp((int)(random(query_pow()/2)));
    }
    if(query_ep()<query_max_ep())
    {
	if(resting)
	    add_ep((int)(query_con()/2+random(query_con()/2)));
	else
	    add_ep((int)(random(query_con()/2)));
    }
}

void heart_beat()
{
    object bat;
    age++;
    tick++;

    if (beat == 0)
	beat = 15;
    bat=query_battle_object();
    if (tick > beat)
      {
	if(!bat)
	  {
	    do_regen();
	    regen_limbs();
	    skill_beat();
	  }
	tick = 0;
      }
    if(bat)
      {
	THOB->battle_beat();
      }
}

string
stat_me ()
{
    return base::stat_me()
    + "LIVING OBJECT\n"
    + "  attributes   : STR DEX AGI CON INT WIS POW CHA SIZ STU\n"
    + "  current ---> : "+sprintf("%3d %3d %3d %3d %3d %3d %3d %3d %3d %3d",
      current_stats[S_STR], current_stats[S_DEX], current_stats[S_AGI],
      current_stats[S_CON], current_stats[S_INT], current_stats[S_WIS],
      current_stats[S_POW], current_stats[S_CHA], current_stats[S_SIZ],
      current_stats[S_STU])
    + "\n"
    + "  maximum ---> : "+sprintf("%3d %3d %3d %3d %3d %3d %3d %3d %3d %3d",
      maximum_stats[S_STR], maximum_stats[S_DEX], maximum_stats[S_AGI],
      maximum_stats[S_CON], maximum_stats[S_INT], maximum_stats[S_WIS],
      maximum_stats[S_POW], maximum_stats[S_CHA], maximum_stats[S_SIZ],
      maximum_stats[S_STU])
    + "\n"
    + "  attributes   : AGE SIG HEI WEI HPS EPS SPS ALX ALY\n"
    + "  current ---> : "+sprintf("%3d %3d %3d %3d %3d %3d %3d %3d %3d",
      ((age*3/5)/(60*24*28*8)), min_sight, 0, 0, hp, ep, sp, alx, aly)
    + "\n"
    + "  maximum ---> : "+sprintf("%3d %3d %3d %3d %3d %3d %3d %3d %3d",
      ((max_age*3/5)/(60*24*28*8)), max_sight, 0, 0,query_max_hp(), query_max_ep(), query_max_sp(), 0, 0)
    //      ((max_age*3/5)/(60*24*28*8)), max_sight, height, weight/1000,max_hp, max_ep, max_sp, 0, 0)
    + "\n"
    + "  race         : "+race+" "+(subrace ? "("+subrace+")" : "")+"\n";
}

int query_no_clean_up()
{
    return clean_up;
}

int set_no_clean_up()
{
    return clean_up = 1;
}

int set_clean_up()
{
    return clean_up = 0;
}

// query_shapestring(int type) by dranil
// returns the shape of the creature
// type 0: "monster_name is in...", type 1: "monster_gender is in..."

string query_shapestring(int type)
{
    string buf;

    if(type==0)
	buf=capitalize(THOB->query_name());
    else
	buf=capitalize(THOB->query_pronoun());

    switch (THOB->query_hp()*100 / THOB->query_max_hp())
    {
    case -100000..11:
	buf+=" is dying at any second.\n";
	break;
    case 12..24:
	buf+=" is looking terribly hurt.\n";
	break;
    case 25..37:
	buf+=" is in bad shape.\n";
	break;
    case 38..50:
	buf+=" is heavily wounded.\n";
	break;
    case 51..63:
	buf+=" is visibly hurt.\n";
	break;
    case 64..76:
	buf+=" is slightly wounded.\n";
	break;
    case 77..89:
	buf+=" is in good shape.\n";
	break;
    default:
	buf+=" is in excellent shape.\n";
	break;
    }
    return buf;
}


// for languages, by madrid 

int set_current_language(string lang)
{
    string *langs = 
    ({ "alande", "kvanya", "uruzden", "draz", "ohrim", "sartog", "grahnik",
      "hgrzag", "palen", "choui", "yavahe", "ugal", "tzhimsal", "yiunda" });

    if (member_array(lang, langs) != -1)
    {
	current_language = lang;
	return 1;
    }
    return 0;
}

string query_current_language()
{
    return current_language;
}

void
fix_heart() 
{
    set_heart_beat(1);
}
