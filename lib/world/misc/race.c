inherit ROOM;

#define STAT_TUNE       100 // generic human - 10 points/each

string *eyetype = ({ "", " adorable", " beautiful", " dashing",
  " penetrating", " keen" });

string *eyes = ({ "green", "deep green", "light green", "dark green",
  "emerald green", "blue", "deep blue", "light blue",
  "dark blue", "icy blue", "brown", "deep brown",
  "light brown", "dark brown", "hazel brown", "grey",
  "light grey", "amber", "purple" });

string *hairlength = ({ "very short", "short", "shoulder long", "long",
  "very long" });

string *hairtype = ({ "straight", "slightly wavy", "wavy",
  "slightly curly", "curly", "tangled" });

string *haircolor = ({ "brown", "hazel brown", "light brown",
  "deep brown", "black", "blonde", "golden blonde",
  "rich blonde", "red", "dark red", "fiery red", "dark gray",
  "silvery gray" });

string *male_class = ({ "a low ranked warrior", "a warrior",
  "a famous warrior", "a magician",
  "a famous magician", "a reknown archmage",
  "an infamous thief", "a seasoned scout", "a notorious assassin",
  "a skilled craftsman", "an entertainer", "a noble knight",
  "a royal knight", "a ranger", "a famous ranger",
  "a druid", "a famous druid", "an adventurer of some sort",
  "a legendary adventurer", "a priest", "a high priest",
  "a humble monk", "a expert thief", "a merchant",
  "a master merchant", "a popular healer", "a shaman",
  "a scribe", "a farmer", "a shopkeeper", "a hunter",
  "a sailor", "a shepherd", "a bard" });

string *fema_class = ({ "a low ranked warrior", "a warrior",
  "a notorious thief", "an experienced scout", "an assassin",
  "an entertainer", "a druid", "a reknown druid", 
  "a prominent adventurer", "a renowned adventurer",
  "a priestess", "a high priestess", "a meek nun",
  "a housewife", "a merchant", "a skilled thief", "a witch",
  "a healer", "a shaman", "a bard", "an adventurer",
  "a scribe", "an artisan", "a farmer", "a shopkeeper",
  "a shepherd" });

string *complexion = ({ "pale", "normal", "slightly tanned", "tanned" });

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

string *cur_stat = ({  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 });
string *mm1_stat = ({  5,  5,  5,  5,  5,  5,  5,  5,  5,  5 });
string *mm2_stat = ({ 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 });
string *max_stat = ({  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 });

int total, real_total, j;

do_pause ()
{
    if (THIS->query_race() == "elf")
    {
	write ("Moving you to the city of Tanir elves, the Sol'daran!\n");
	THIS->move_player("/world/welf/rooms/temple.c");
    }
    else if (THIS->query_race() == "human")
    {
        write ("Moving you to the City of Light and Justice, the Silvercreek!\n");
        THIS->move_player("/world/creek/rooms/temple.c");
    }
    else
    {
	write ("Your homeland is still under construction, moving you to Hilltop Village.\n");
	THIS->move_player("/world/hilltop/rooms/room1.c");
    }

    THIS->save_me();

    return 1;
}

create_room ()
{
    set_light (1);
    set_no_explore (1);
    set_no_monster (1);
    set_no_wrap (1);

    set_short ("Race selection room");
    set_long (wrap (
	"You are standing in the race selection room, where you need to "
	+ "select a race for your new character. Make sure to select your race "
	+ "carefully, because in the future, getting a reincarnation to a new one "
	+ "might be extremely difficult. Also, remember that your race affects "
	+ "a great many things in your life in this world, for example your starting "
	+ "location is configured by the race you select.\n"
      + "\nAvailable commands are:\n"
      + "   races              - displays all available races\n"
      + "   info <race>        - gives you a long description of a race\n"
      + "   select <race>      - selects the race\n"));
}

init_room ()
{
    add_action ("do_races", "races");
    add_action ("do_info", "info");
    add_action ("do_select", "select");
    add_action ("do_kill", "kill");
}

do_kill()
{
    message("0","You don't feel like attacking here.\n",THIS);
    return 1;
}

do_races ()
{
    this_player()->more_file("/data/race/racelist");
    return 1;
}
#define PRILANG 100
#define SECLANG 80
#define TERLANG 40

do_info (string str)
{
    string info;

    if (!str)
    {
	notify_fail ("Usage: info <race>\n");
	return 0;
    }

    if (file_size ("/data/race/"+str) > 0)
    {
	write ("-- "+upper_case(str)+" "+repeat_string("-", 74-strlen(str))+"\n\n");
	info = read_file ("/data/race/"+str);
	info = replace_string (info, "\n", " ");
	info = replace_string (info, "\r", "");
	write ("   " + wrap(info, 70, 3) + "\n\n");
	write (repeat_string("-", 78) + "\n");
    }
    else
	write (wrap("You selected race ("+str+") which does not exist. " +
	    "Type \"races\" to see what races you can select.\n"));
    return 1;
}

do_select (string str)
{
    string gend = "", buf = "", father = "", mother = "", build = "", heights = "";
    int height, t, v;

    cur_stat   = ({  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 });
    mm1_stat   = ({  5,  5,  5,  5,  5,  5,  5,  5,  5,  5 });
    mm2_stat   = ({ 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 });
    max_stat   = ({  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 });

    THIS->initialise_skillmap();
    THIS->initialize_magical_true_names();
    THIS->initialize_guilds();
    THIS->initialize_guild_titles();
	THIS->init_armour_slots("humanoid");
    total      = STAT_TUNE;
    real_total = 0;
    j          = 0;

    THIS->set_str (0);
    THIS->set_con (0);
    THIS->set_stu (0);
    THIS->set_siz (0);
    THIS->set_int (0);
    THIS->set_pow (0);
    THIS->set_wis (0);
    THIS->set_dex (0);
    THIS->set_agi (0);
    THIS->set_cha (0);

    THIS->set_alignx (0);
    THIS->set_aligny (0);
    THIS->create();
    THIS->set_money (0);
    THIS->add_skill("social");
    THIS->add_skill("communication");
    THIS->add_skill("language");
    THIS->add_skill("martial_arts_attack");
    THIS->add_skill("martial_arts_parry");
    THIS->add_skill("dodge");
    THIS->add_skill("brawlers_punch");
    THIS->add_skill("lay_hands");
    THIS->set_maneuver("brawlers_punch");
    THIS->update_worn_armour();
    THIS->update_wielded_weapon();

    if (str == "ayura")
    {
	eyetype = ({ "" });

	eyes = ({ "green", "dark green",
	  "light grey", "dark grey", "grey" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "slightly wavy", "wavy",
	  "slightly curly", "curly", "tangled" });

	haircolor = ({ "black", "brown", "dark brown"
	  "dark brown", "deep brown", "black", "grey", "dark grey" });

	complexion = ({ "slightly tanned", "tanned" });

	mm2_stat[S_STR] += 2;
	mm2_stat[S_DEX] -= 2;
	mm2_stat[S_AGI] += 1;
	mm2_stat[S_CON] += 3;
	mm2_stat[S_STU] += 3;
	mm2_stat[S_SIZ] += 0;
	mm2_stat[S_INT] -= 1;
	mm2_stat[S_POW] += 2;
	mm2_stat[S_WIS] += 5;
	mm2_stat[S_CHA] -= 1;

	mm1_stat[S_POW] += 5;

	total += 12;

	THIS->set("race", "human");
	THIS->set("subrace", "ayura");
	THIS->set_skill_chance("tzhimsal",PRILANG);
	THIS->set_skill_chance("sartog", SECLANG);
	THIS->set_skill_change("yavahe", 40);
	THIS->set("max_age", (60*24*28*8)*(85+random(5))/3*5);
	THIS->set("age", (60*24*28*8)*(17+random(3))/3*5);
        THIS->set_height(150+random(20));
        THIS->set_weight(70+random(20));
    }
    else if (str == "innohu")
    {
	eyetype = ({ "" });

	eyes = ({ "green", "blue", "light blue", "deep blue",
	  "dark blue", "brown", "deep brown", "light brown", "dark brown",
	  "hazel brown", "grey", "light grey" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "slightly wavy", "wavy",
	  "slightly curly", "curly", "tangled" });

	haircolor = ({ "dark brown", "deep brown", "black",
	  "black", "dark grey" });

	complexion = ({ "slightly tanned", "tanned" });

	mm2_stat[S_STR] += 4;
	mm2_stat[S_DEX] += 3;
	mm2_stat[S_AGI] += 3;
	mm2_stat[S_CON] += 5;
	mm2_stat[S_STU] += 4;
	mm2_stat[S_SIZ] += 0;
	mm2_stat[S_INT] -= 1;
	mm2_stat[S_POW] -= 3;
	mm2_stat[S_WIS] -= 3;
	mm2_stat[S_CHA] -= 2;

	mm1_stat[S_CON] += 5;
	mm1_stat[S_STU] += 5;

	total += 18;

	THIS->set("max_age", (60*24*28*8)*(85+random(5))/3*5);
	THIS->set("age", (60*24*28*8)*(17+random(3))/3*5);
	THIS->set_skill_chance("yavahe",PRILANG);
	THIS->set_skill_chance("sartog",SECLANG);
	THIS->set_skill_chance("tzhimsal", 40);
	THIS->set("race", "human");
	THIS->set("subrace", "innohu");

        THIS->set_height(170 + random(40));
        THIS->set_weight(80 + random(40));
    }
    else if (str == "moraki")
    {
	eyetype = ({ "" });

	eyes = ({ "blue", "light blue", "dark blue", "deep blue",
	  "blue", "blue", "blue" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "straight", "slightly wavy", "wavy",
	  "slightly curly", "curly", "tangled" });

	haircolor = ({ "brown", "hazel brown", "light brown",
	  "blonde", "golden blonde", "rich blonde", "blonde", "golden blonde",
	  "rich blonde" });

	mm2_stat[S_STR] += 5;
	mm2_stat[S_DEX] += 2;
	mm2_stat[S_AGI] += 3;
	mm2_stat[S_CON] += 4;
	mm2_stat[S_STU] += 5;
	mm2_stat[S_SIZ] += 0;
	mm2_stat[S_INT] -= 3;
	mm2_stat[S_POW] += 0;
	mm2_stat[S_WIS] -= 1;
	mm2_stat[S_CHA] -= 1;

	mm1_stat[S_STR] += 5;
	mm1_stat[S_STU] += 5;

	total += 14;

	THIS->set("max_age", (60*24*28*8)*(55+random(5))/3*5);
	THIS->set("age", (60*24*28*8)*(16+random(3))/3*5);
	THIS->set_skill_chance("sartog",PRILANG);
	THIS->set("race", "human");
	THIS->set("subrace", "moraki");
        THIS->set_height(190 + random(40));
        THIS->set_weight(110 + random(40));
    }
    else if (str == "shaolu")
    {
	eyetype = ({ "" });

	eyes = ({ "emerald green", "deep green", "green" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "straight",
	  "straight", "straight", "straight", "slightly wavy", "wavy" "curly",
	  "tangled" });

	haircolor = ({ "black" });

	complexion = ({ "chocolate brown", "brown", "dark brown" });

	mm2_stat[S_STR] += 3;
	mm2_stat[S_DEX] += 4;
	mm2_stat[S_AGI] += 5;
	mm2_stat[S_CON] += 1;
	mm2_stat[S_STU] += 1;
	mm2_stat[S_SIZ] -= 1;
	mm2_stat[S_INT] += 0;
	mm2_stat[S_POW] += 1;
	mm2_stat[S_WIS] += 2;
	mm2_stat[S_CHA] -= 1;

	mm1_stat[S_DEX] += 2;
	mm1_stat[S_AGI] += 5;

	total += 15;

	THIS->set("max_age", (60*24*28*8)*(75+random(5))/3*5);
	THIS->set("age", (60*24*28*8)*(17+random(3))/3*5);
	THIS->set_skill_chance("ugal",PRILANG);
	THIS->set_skill_chance("sartog",SECLANG);
	THIS->set("race", "human");
	THIS->set("subrace", "shaolu");
        THIS->set_height(165 + random(30));
        THIS->set_weight(60 + random(30));
    }
    else if (str == "thari")
    {
	eyetype = ({ "", "", "", "", "", "", " adorable", " beautiful", "
  dashing" });

	eyes = ({ "green", "deep green", "light green", "dark green",
	  "emerald green", "blue", "deep blue", "light blue",
	  "dark blue", "icy blue", "brown", "deep brown",
	  "light brown", "dark brown", "hazel brown", "grey",
	  "light grey" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "slightly wavy", "wavy",
	  "slightly curly", "curly", "tangled" });

	haircolor = ({ "brown", "brown", "brown",
	  "hazel brown", "light brown", "hazel brown", "light brown",
	  "deep brown", "deep brown", "black", "black", "blonde", "golden blonde",
	  "rich blonde", "red", "dark red", "dark gray",
	  "silvery gray" });

	complexion += ({ "fair" });

	mm2_stat[S_STR] += 0;
	mm2_stat[S_DEX] += 0;
	mm2_stat[S_AGI] += 0;
	mm2_stat[S_CON] += 0;
	mm2_stat[S_STU] += 0;
	mm2_stat[S_SIZ] += 0;
	mm2_stat[S_INT] += 0;
	mm2_stat[S_POW] += 0;
	mm2_stat[S_WIS] += 0;
	mm2_stat[S_CHA] += 0;

	total += 0;

	THIS->set("max_age", (60*24*28*8)*(130+random(5))/3*5);
	THIS->set("age", (60*24*28*8)*(18+random(4))/3*5);
	THIS->set_skill_chance("sartog",PRILANG);
	THIS->set("race", "human");
	THIS->set("subrace", "thari");
        THIS->set_height(158+random(30));
        THIS->set_weight(50+random(30));
    }
    else if (str == "yangir")
    {
	eyetype = ({ "", "", "", "", "", "", " adorable", " beautiful", "
  dashing" });

	eyes = ({ "green", "deep green", "light green", "dark green",
	  "emerald green", "blue", "deep blue", "light blue",
	  "dark blue", "brown", "deep brown",
	  "light brown", "dark brown", "hazel brown", "grey",
	  "light grey" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "slightly wavy", "wavy",
	  "slightly curly", "curly", "tangled" });

	haircolor = ({ "brown", "brown", "brown",
	  "hazel brown", "light brown", "hazel brown", "light brown",
	  "deep brown", "deep brown", "black", "black", "blonde", "golden blonde",
	  "rich blonde", "red", "dark red", "dark gray",
	  "silvery gray" });

	mm2_stat[S_STR] += 0;
	mm2_stat[S_DEX] += 1;
	mm2_stat[S_AGI] += 3;
	mm2_stat[S_CON] += 1;
	mm2_stat[S_STU] += 1;
	mm2_stat[S_SIZ] -= 2;
	mm2_stat[S_INT] += 1;
	mm2_stat[S_POW] += 4;
	mm2_stat[S_WIS] += 2;
	mm2_stat[S_CHA] += 0;

	mm1_stat[S_POW] += 3;

	total += 11;

	THIS->set("max_age", (60*24*28*8)*(130+random(10))/3*5);
	THIS->set("age", (60*24*28*8)*(29+random(3))/3*5);
	THIS->set_skill_chance("choui",PRILANG);
	THIS->set_skill_chance("sartog",SECLANG);
	THIS->set("race", "human");
	THIS->set("subrace", "yangir");
        THIS->set_height(145 + random(20));
        THIS->set_weight(50 + random(20));
    }
    else if (str == "yamar")
    {
	eyetype = ({ "", "", "", " adorable", " beautiful", " dashing",
	  " penetrating" });

	eyes = ({ "green", "deep green", "light green", "dark green",
	  "blue", "deep blue", "light blue", "dark blue", "light brown", "purple"
	});

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "slightly wavy", "wavy",
	  "slightly curly", "curly", "tangled" });

	haircolor = ({ "brown", "hazel brown", "light brown",
	  "blonde", "golden blonde", "rich blonde" });

	complexion += ({ "fair", "fair", "fair" });

	mm2_stat[S_STR] -= 4;
	mm2_stat[S_DEX] += 2;
	mm2_stat[S_AGI] += 1;
	mm2_stat[S_CON] -= 3;
	mm2_stat[S_STU] -= 4;
	mm2_stat[S_SIZ] -= 3;
	mm2_stat[S_INT] += 9;
	mm2_stat[S_POW] += 5;
	mm2_stat[S_WIS] += 3;
	mm2_stat[S_CHA] += 3;

	mm1_stat[S_INT] += 9;

	total += 9;

	THIS->set("max_age", (60*24*28*8)*(180+random(15))/3*5);
	THIS->set("age", (60*24*28*8)*(39+random(5))/3*5);
	THIS->set_skill_chance("yiunda",PRILANG);
	THIS->set_skill_chance("sartog",PRILANG);
	THIS->set_skill_chance("alande",SECLANG);
	THIS->set("race", "half-elf");
	THIS->set("subrace", "yamar");
        THIS->set_height(145+random(20));
        THIS->set_weight(30+random(10));
    }
    else if (str == "tilan")
    {
	eyetype = ({ "", "", "", "", "", "", "", "", "", "", "", "", "",
	  "", "", "", "", " adorable", " beautiful", " dashing",
	  " penetrating" });

	eyes = ({ "blue", "deep blue", "light blue",
	  "dark blue", "grey", "light grey" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "slightly wavy", "wavy",
	  "slightly curly", "curly", "tangled" });

	haircolor = ({ "dark brown", "deep brown", "black",
	  "black", "black" });

	mm2_stat[S_STR] += 2;
	mm2_stat[S_DEX] += 2;
	mm2_stat[S_AGI] += 2;
	mm2_stat[S_CON] += 2;
	mm2_stat[S_STU] += 2;
	mm2_stat[S_SIZ] += 0;
	mm2_stat[S_INT] -= 2;
	mm2_stat[S_POW] += 2;
	mm2_stat[S_WIS] += 2;
	mm2_stat[S_CHA] -= 2;

	total += 18;

	THIS->set("max_age", (60*24*28*8)*(110+random(5))/3*5);
	THIS->set("age", (60*24*28*8)*(19+random(5))/3*5);
	THIS->set_skill_chance("sartog",PRILANG);
	THIS->set_skill_chance("alande",PRILANG);
	THIS->set("race", "half-elf");
	THIS->set("subrace", "tilan");
        THIS->set_height(180+random(20));
        THIS->set_weight(80+random(20));
    }
    else if (str == "tanir")
    {
	/* defaults */

	mm2_stat[S_STR] += 0;
	mm2_stat[S_DEX] += 3;
	mm2_stat[S_AGI] += 4;
	mm2_stat[S_CON] += 0;
	mm2_stat[S_STU] -= 1;
	mm2_stat[S_SIZ] -= 1;
	mm2_stat[S_INT] += 3;
	mm2_stat[S_POW] += 3;
	mm2_stat[S_WIS] += 3;
	mm2_stat[S_CHA] += 3;

	mm1_stat[S_AGI] += 9;
	mm1_stat[S_INT] += 4;
	mm1_stat[S_POW] += 4;
	mm1_stat[S_WIS] += 4;

	total += 17;

	THIS->set("max_age", (60*24*28*8)*(250+random(30))/3*5);
	THIS->set("age", (60*24*28*8)*(50+random(10))/3*5);
	THIS->set_skill_chance("sartog",SECLANG);
	THIS->set_skill_chance("alande",PRILANG);
	THIS->set("race", "elf");
	THIS->set("subrace", "tanir");
        if (THIS->query_gender() == 1)
          THIS->set_height(180+random(20));
        else
          THIS->set_height(170+random(20));
        
        THIS->set_weight(55+random(20));
    }
    else if (str == "dyanir")
    {
	eyetype = ({ "", "", "", "", "", " adorable", " beautiful", " dashing",
	  " penetrating" });

	eyes = ({ "green", "deep green", "light green", "dark green",
	  "emerald green", "blue", "deep blue", "light blue",
	  "dark blue", "icy blue", "brown", "deep brown",
	  "light brown", "dark brown", "hazel brown", "grey",
	  "light grey", "amber", "purple" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "slightly wavy", "wavy" });

	haircolor = ({ "coal black", "coal black", "coal black", "dark red" });

	complexion = ({ "white" });

	mm2_stat[S_STR] += 0;
	mm2_stat[S_DEX] += 1;
	mm2_stat[S_AGI] += 3;
	mm2_stat[S_CON] -= 1;
	mm2_stat[S_STU] -= 1;
	mm2_stat[S_SIZ] -= 1;
	mm2_stat[S_INT] += 4;
	mm2_stat[S_POW] += 7;
	mm2_stat[S_WIS] += 7;
	mm2_stat[S_CHA] -= 1;

	mm1_stat[S_POW] += 9;
	mm1_stat[S_WIS] += 9;
	mm1_stat[S_INT] += 5;

	total += 18;

	THIS->set("alx", -750);

	THIS->set("max_age", (60*24*28*8)*(290+random(30))/3*5);
	THIS->set("age", (60*24*28*8)*(61+random(5))/3*5);
	THIS->set_skill_chance("sartog",SECLANG);
	THIS->set_skill_chance("uruzden",PRILANG);
	THIS->set_skill_chance("alande",SECLANG);
	THIS->set_skill_chance("kvanya",40);
	THIS->set("race", "elf");
	THIS->set("subrace", "dyanir");
        THIS->set_height(185+random(20));
        THIS->set_weight(55+random(20));
    }
    else if (str == "aindar")
    {
	eyetype = ({ "", "", " adorable", " beautiful", " dashing",
	  " penetrating" });

	eyes = ({ "brown", "deep brown",
	  "light brown", "dark brown", "hazel brown", "black" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "slightly wavy", "wavy",
	  "slightly curly", "curly", "tangled" });

	haircolor = ({ "raven-black" });

	complexion = ({ "pale", "pale", "fair and pale", "fair" });

	mm2_stat[S_STR] += 3;
	mm2_stat[S_DEX] += 5;
	mm2_stat[S_AGI] += 5;
	mm2_stat[S_CON] += 3;
	mm2_stat[S_STU] += 2;
	mm2_stat[S_SIZ] -= 1;
	mm2_stat[S_INT] += 3;
	mm2_stat[S_POW] += 0;
	mm2_stat[S_WIS] -= 1;
	mm2_stat[S_CHA] += 3;

	mm1_stat[S_AGI] += 5;
	mm1_stat[S_DEX] += 5;

	total += 22;

	THIS->set("alx", 750);

	THIS->set("max_age", (60*24*28*8)*(350+random(50))/3*5);
	THIS->set("age", (60*24*28*8)*(81+random(9))/3*5);
	THIS->set_skill_chance("sartog",SECLANG);
	THIS->set_skill_chance("alande",PRILANG);
	THIS->set_skill_chance("kvanya",SECLANG);
	THIS->set("race", "elf");
	THIS->set("subrace", "aindar");
        THIS->set_height(195+random(20));
        THIS->set_weight(75+random(20));
    }
    else if (str == "lindor")
    {
	eyetype = ({ " beautiful", " adorable", " beautiful", " dashing" });

	eyes = ({ "green", "deep green", "light green", "dark green",
	  "emerald green", "blue", "deep blue", "light blue",
	  "dark blue", "icy blue", "brown", "deep brown",
	  "light brown", "dark brown", "hazel brown", "grey",
	  "light grey", "amber", "purple" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "slightly wavy", "wavy",
	  "slightly curly", "curly", "tangled" });

	haircolor = ({ "golden blonde" });

	complexion = ({ "fair and beautiful" });

	mm2_stat[S_STR] -= 2;
	mm2_stat[S_DEX] += 2;
	mm2_stat[S_AGI] += 0;
	mm2_stat[S_CON] -= 1;
	mm2_stat[S_STU] -= 2;
	mm2_stat[S_SIZ] -= 1;
	mm2_stat[S_INT] += 9;
	mm2_stat[S_POW] += 8;
	mm2_stat[S_WIS] += 5;
	mm2_stat[S_CHA] += 5;

	mm1_stat[S_INT] += 9;
	mm1_stat[S_POW] += 8;
	mm1_stat[S_WIS] += 7;
	mm1_stat[S_CHA] += 9;

	total += 23;

	THIS->set("alx", 750);

	THIS->set("max_age", (60*24*28*8)*(400+random(30))/3*5);
	THIS->set("age", (60*24*28*8)*(90+random(10))/3*5);
	THIS->set_skill_chance("sartog",SECLANG);
	THIS->set_skill_chance("alande",PRILANG);
	THIS->set_skill_chance("kvanya",PRILANG);
	THIS->set_skill_chance("uruzden",50);
	THIS->set("race", "elf");
	THIS->set("subrace", "lindor");
        THIS->set_height(185+random(20));
        THIS->set_weight(45+random(20));
    }
    else if (str == "faun")
    {
	mm2_stat[S_STR] += 4;
	mm2_stat[S_DEX] += 2;
	mm2_stat[S_AGI] += 5;
	mm2_stat[S_CON] += 4;
	mm2_stat[S_STU] += 5;
	mm2_stat[S_SIZ] -= 1;
	mm2_stat[S_INT] += 2;
	mm2_stat[S_POW] += 3;
	mm2_stat[S_WIS] += 2;
	mm2_stat[S_CHA] += 5;

	total += 31;

	THIS->set("max_age", (60*24*28*8)*(75+random(10))/3*5);
	THIS->set("age", (60*24*28*8)*(17+random(3))/3*5);

	if (THIS->query("gender") != 1)
	{
	    write ("You need to be male to select this race.\n");
	    return 1;
	}
	THIS->set_skill_chance("sartog",PRILANG);
	THIS->set("race", "faun");
	THIS->set("subrace", 0);
        THIS->set_height(175+random(20));
        THIS->set_weight(90+random(20));
    }
    else if (str == "troll")
    {
	eyetype = ({ "", "", "", " bloody", " abominable" });

	eyes = ({ "green", "deep green", "light green", "dark green",
	  "brown", "deep brown", "light brown", "dark brown", "hazel brown",
	  "grey", "light grey" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "slightly wavy", "wavy",
	  "slightly curly" });

	haircolor = ({ "green", "brown", "hazel brown", "light brown",
	  "deep brown", "black", "black", "blonde", "red", "dark red",
	  "fiery red", "dark gray" });

	complexion = ({ "crude and greenish" });

	mm2_stat[S_STR] += 9;
	mm2_stat[S_DEX] -= 2;
	mm2_stat[S_AGI] -= 2;
	mm2_stat[S_CON] += 6;
	mm2_stat[S_STU] += 8;
	mm2_stat[S_SIZ] += 3;
	mm2_stat[S_INT] -= 2;
	mm2_stat[S_POW] += 0;
	mm2_stat[S_WIS] -= 2;
	mm2_stat[S_CHA] -= 8;

	mm1_stat[S_STR] += 9;
	mm1_stat[S_CON] += 9;
	mm1_stat[S_STU] += 9;
	mm1_stat[S_CHA] -= 2;

	total += 11;

	THIS->set("beat", 10);

	THIS->set("alx", -750);

	THIS->set("max_age", (60*24*28*8)*(50+random(10))/3*5);
	THIS->set("age", (60*24*28*8)*(10+random(5))/3*5);
	THIS->set_skill_chance("sartog",40);
	THIS->set_skill_chance("hgrzag",PRILANG);
	THIS->set_skill_chance("grahnik",SECLANG);
	THIS->set("race", "troll");
	THIS->set("subrace", 0);
        THIS->set_height(240+random(30));
        THIS->set_weight(190+random(30));
    }
    else if (str == "orc")
    {
	eyetype = ({ "", "", " bloody", " abominable" });

	eyes = ({ "red", "fiery red", "dark red" });

	hairtype = ({ " " });

	haircolor = ({ " " });

	mm2_stat[S_STR] += 3;
	mm2_stat[S_DEX] += 2;
	mm2_stat[S_AGI] += 3;
	mm2_stat[S_CON] += 3;
	mm2_stat[S_STU] += 3;
	mm2_stat[S_SIZ] -= 1;
	mm2_stat[S_INT] -= 2;
	mm2_stat[S_POW] += 3;
	mm2_stat[S_WIS] += 2;
	mm2_stat[S_CHA] -= 6;

	total += 10;

	THIS->set("alx", -750);

	THIS->set("max_age", (60*24*28*8)*(60+random(10))/3*5);
	THIS->set("age", (60*24*28*8)*(13+random(5))/3*5);
	THIS->set_skill_chance("sartog",SECLANG);
	THIS->set_skill_chance("grahnik",PRILANG);
	THIS->set_skill_chance("hgrzag",50);
	THIS->set("race", "orc");
	THIS->set("subrace", 0);
        THIS->set_height(180+random(20));
        THIS->set_weight(95+random(20));
    }
    else if (str == "dwarf")
    {
	eyetype = ({ "" });

	eyes = ({ "brown", "deep brown",
	  "light brown", "dark brown", "hazel brown", "grey",
	  "light grey" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "slightly wavy", "wavy",
	  "slightly curly", "curly" });

	haircolor = ({ "brown", "hazel brown", "light brown",
	  "deep brown", "black", "dark gray" });

	mm2_stat[S_STR] += 3;
	mm2_stat[S_DEX] += 3;
	mm2_stat[S_AGI] += 3;
	mm2_stat[S_CON] += 9;
	mm2_stat[S_STU] += 9;
	mm2_stat[S_SIZ] -= 5;
	mm2_stat[S_INT] -= 1;
	mm2_stat[S_POW] += 1;
	mm2_stat[S_WIS] -= 1;
	mm2_stat[S_CHA] -= 1;

	mm1_stat[S_CON] += 9;
	mm1_stat[S_STU] += 9;

	total += 21;

	THIS->set("alx", 750);

	THIS->set("max_age", (60*24*28*8)*(200+random(30))/3*5);
	THIS->set("age", (60*24*28*8)*(40+random(10))/3*5);
	THIS->set_skill_chance("sartog",SECLANG);
	THIS->set_skill_chance("draz",PRILANG);
	THIS->set("race", "dwarf");
	THIS->set("subrace", 0);
        THIS->set_height(130+random(10));
        THIS->set_weight(60+random(20));
    }
    else if (str == "gnome")
    {
	eyetype = ({ "" });

	eyes = ({ "brown", "deep brown",
	  "light brown", "dark brown", "hazel brown", "grey",
	  "light grey" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "slightly wavy", "wavy",
	  "slightly curly", "curly" });

	haircolor = ({ "brown",
	  "deep brown", "gray", "dark gray", "silvery gray", "black" });

	mm2_stat[S_STR] -= 1;
	mm2_stat[S_DEX] += 5;
	mm2_stat[S_AGI] += 1;
	mm2_stat[S_CON] += 1;
	mm2_stat[S_STU] -= 1;
	mm2_stat[S_SIZ] -= 5;
	mm2_stat[S_INT] += 6;
	mm2_stat[S_POW] += 3;
	mm2_stat[S_WIS] += 3;
	mm2_stat[S_CHA] += 0;

	mm1_stat[S_INT] += 9;

	total += 12;

	THIS->set("beat", 12);

	THIS->set("max_age", (60*24*28*8)*(300+random(100))/3*5);
	THIS->set("age", (60*24*28*8)*(70+random(10))/3*5);
	THIS->set_skill_chance("sartog",SECLANG);
	THIS->set_skill_chance("ohrim",PRILANG);
	THIS->set("race", "gnome");
	THIS->set("subrace", 0);
        THIS->set_height(105+random(20));
        THIS->set_weight(30+random(20));
    }
    else if (str == "halfling")
    {
	eyetype = ({ "" });

	eyes = ({ "green", "deep green", "light green", "dark green",
	  "emerald green", "blue", "deep blue", "light blue",
	  "dark blue", "brown", "deep brown",
	  "light brown", "dark brown", "hazel brown", "grey",
	  "light grey" });

	hairlength = ({ "very short", "short", "shoulder long", "long",
	  "very long" });

	hairtype = ({ "straight", "slightly wavy", "wavy",
	  "slightly curly", "curly", "tangled" });

	haircolor = ({ "brown", "hazel brown", "light brown",
	  "deep brown", "black", "blonde", "golden blonde",
	  "rich blonde", "red" });

	mm2_stat[S_STR] -= 1;
	mm2_stat[S_DEX] += 9;
	mm2_stat[S_AGI] += 7;
	mm2_stat[S_CON] += 1;
	mm2_stat[S_STU] += 1;
	mm2_stat[S_SIZ] -= 5;
	mm2_stat[S_INT] -= 1;
	mm2_stat[S_POW] -= 2;
	mm2_stat[S_WIS] += 3;
	mm2_stat[S_CHA] += 1;

	mm1_stat[S_DEX] += 9;
	mm1_stat[S_AGI] += 9;

	total += 13;

	THIS->set("beat", 11);

	THIS->set("alx", 750);

	THIS->set("max_age", (60*24*28*8)*(87+random(5))/3*5);
	THIS->set("age", (60*24*28*8)*(18+random(2))/3*5);
	THIS->set_skill_chance("sartog",SECLANG);
	THIS->set_skill_chance("palen",PRILANG);
	THIS->set("race", "halfling");
	THIS->set("subrace", 0);
        THIS->set_height(105+random(20));
        THIS->set_weight(50+random(20));
    }
    else
    {
	write (wrap("You selected race ("+str+") which does not exist. \n" +
	    "Type 'races' to see what races you can select.\n"));
	return 1;
    }

    THIS->set_current_language("sartog");

    for (int i=0;i<sizeof(mm1_stat);i++) {
	mm1_stat[i] = mm2_stat[i]-10;

	if (mm1_stat[i] < 3)
	    mm1_stat[i] = 3;

	cur_stat[i] = mm1_stat[i];
	total -= mm1_stat[i];
    }

    if (total < 0)
	total = 10;

    for (int i=0;i<total;i++)
    {
	j = random(sizeof(cur_stat));

	if (cur_stat[j] >= mm2_stat[j]) {
	    i--;
	    continue;
	}

	cur_stat[j] += 1;
	real_total++;
    }

    for (int l=0;l<sizeof(cur_stat);l++)
	max_stat[l] = cur_stat[l] + (cur_stat[l] * 100 / real_total / 2);

    THIS->set_stats (cur_stat);
    THIS->set_max_stats (max_stat);

    heights = "formless";

    switch (THIS->query_height())
    {
    case 0..150:
	heights = "very short";
	break;
    case 151..175:
	heights = "short";
	break;
    case 176..180:
	
heights = "average height";
	break;
    case 181..199:
	heights = "tall";
	break;
    case 200..1000:
	heights = "very tall";
	break;
    }

    switch (THIS->query_stu() + THIS->query_str())
    {
    case 0..15:
	build = "sickly thin";
	break;
    case 16..17:
	build = "thin and weak";
	break;
    case 18..19:
	build = "thin";
	break;
    case 20..21:
	build = "thin but tightly muscled";
	break;
    case 22..23:
	build = "slender";
	break;
    case 24..25:
	build = "slender and tightly muscled";
	break;
    case 26..27:
	build = "average build";
	break;
    case 28..29:
	build = "well muscled";
	break;
    case 30..31:
	build = "stocky and a little fat";
	break;
    case 32..33:
	build = "stocky";
	break;
    case 34..35:
	build = "stocky and muscled";
	break;
    case 36..37:
	build = "stocky and well muscled";
	break;
    case 38..39:
	build = "large";
	break;
    case 40..1000:
	build = "large and heavily muscled";
	break;
    }

    if (THIS->query("gender") == 1)
	gend = "male";
    else if (THIS->query("gender") == 2)
	gend = "female";
    else
	gend = "neuter";

    if (THIS->query("subrace"))
	buf += "You are born "+gend+" "+capitalize(str)+" "+THIS->query_race();
    else
	buf += "You are born "+gend+" "+THIS->query_race();

    THIS->set("eyetype", eyetype[random(sizeof(eyetype))]);
    THIS->set("eyecolor", eyes[random(sizeof(eyes))]);
    THIS->set("hairtype", hairtype[random(sizeof(hairtype))]);
    THIS->set("haircolor", haircolor[random(sizeof(haircolor))]);
    THIS->set("complexion", complexion[random(sizeof(complexion))]);
    THIS->set("hairlength", random(100));

    buf += ". You have"+THIS->query("eyetype")+" "
    + THIS->query("eyecolor")+" eyes and "
    + hairlength[THIS->query("hairlength")/25]+" "
    + THIS->query("hairtype")+" "
    + THIS->query("haircolor")+" hair. ";

    buf += "You are "+build+", "+heights+" "+THIS->query_race()+" and have "+THIS->query("complexion")+" complexion.\n\n";

    if (THIS->query_race() == "gnome") 
    {
	father = capitalize(lower_case("/daemon/gname"->generate("high") +
	    "/daemon/gname"->generate("high")));
	mother = capitalize(lower_case("/daemon/gname"->generate("high") +
	    "/daemon/gname"->generate("high")));
    }
    else if (THIS->query_race() == "elf")
    {
	father = "/daemon/gname"->generate("high");
	mother = "/daemon/gname"->generate("high");
    }
    else if (THIS->query_race() == "dwarf")
    {
	father = "/daemon/gname"->generate("dwarven");
	mother = "/daemon/gname"->generate("dwarven");
    }
    else if (THIS->query_race() == "human")
    {
	father = "/daemon/gname"->generate("standard");
	mother = "/daemon/gname"->generate("standard");
    }
    else
    {
	father = "/daemon/gname"->generate("low");
	mother = "/daemon/gname"->generate("low");
    }

    THIS->set("father", ({ random(2), father, male_class[random(sizeof(male_class))] }));
    THIS->set("mother", ({ random(2), mother, fema_class[random(sizeof(fema_class))] }));

    buf += "Your father was "+father+", "+THIS->query("father")[2]+" and "
    + "your mother was "+mother+", "+THIS->query("mother")[2]+". ";

    if (THIS->query("father")[0] > 0 && THIS->query("mother")[0] > 0)
	buf += "Both of your parents are still alive and doing well. ";
    else if (THIS->query("father")[0] == 0 && THIS->query("mother")[0] == 0)
	buf += "Both of your parents are murdered. ";
    else if (THIS->query("father")[0] == 0)
	buf += father + " has died but your mother is still alive. ";
    else if (THIS->query("mother")[0] == 0)
	buf += mother + " has died but your father is still alive. ";
    else
	buf += "A nuclear bomb killed your both parents. ";

    t = random(3);
    v = random(3);

    if (t && v && !random(1))
	buf += "You have one brother and one sister. ";
    else if (t>1)
	buf += "You have two brothers. ";
    else if (v>1)
	buf += "You have two sisters. ";
    else if (t)
	buf += "You have one brother. ";
    else if (v)
	buf += "You have one sister. ";
    else 
	buf += "You were the only child of the family. ";

    buf += "\n\n";

    switch (random(5))
    {
    case 0:
	buf += "You spent your childhood watching your parents "
	+ "practice their professions and you have always wanted "
	+ "to be like your "+(random(1) ? "mother" : "father")+". "
	+ "Your family fared well and you had many friends. ";
	break;
    case 1:
	buf += "You spent your childhood mostly alone, travelling in the "
	+ "woods and watching animals. You have always felt one with "
	+ "the nature and appreciate solitude. ";
	break;
    case 2:
	buf += "You spent your childhood in the city and learned a lot "
	+ "from the local ruffians who taught you that it is ok to be "
	+ "dishonest now and then. ";
	THIS->add_aligny(-250);
	break;
    case 3:
	buf += "You have always wanted to be someone of importance and "
	+ "dream of heroic deeds and dangerous adventurers. You spent "
	+ "most of your childhood time listening old tales and "
	+ "legends. ";
	break;
    case 4:
	buf += "As a child you couldn't understand your parents and "
	+ "spent most of your time inside, reading books and "
	+ "writing poems. ";
	break;
    default:
	buf += "Your parents told you that you really are a real bug. ";
	break;
    }

    write (wrap(buf) + "\n");

    THIS->set_hp (THIS->query_max_hp());
    THIS->set_sp (THIS->query_max_sp());
    THIS->set_ep (THIS->query_max_ep());

    THIS->set_hunger_base (5000);
    THIS->set_thirst_base (5000);
    THIS->init_location ("humanoid");

    THIS->set_name(({ THIS->query_true_name(), THIS->query_race(),
      THIS->query_description_gender() }));

    write ("\n");
//    if (THIS->query("term") != 5) {
//      write ("\nPress ENTER to continue:\n");
//      input_to ("do_pause");
//    } else {
      do_pause();
//    }

    THIS->do_full_heal();
    return 1;
}
