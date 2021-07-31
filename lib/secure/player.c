#include <security.h>
#include <message.h>

inherit "/inherit/living";                    /* living object              */
inherit "/inherit/living/chook";              /* command hook               */
inherit "/inherit/living/receive";            /* receive() function         */
inherit "/inherit/player/quest";              /* quest system               */
inherit "/inherit/living/eq_system";          /* equipment system           */
inherit "/inherit/player/truename";           /* true names                 */

inherit "/inherit/player/effect";
inherit "/inherit/player/money";
inherit "/inherit/player/explore";
inherit "/inherit/player/clpp";               /* command line preparser     */
inherit "/inherit/player/guilds";
inherit "/inherit/player/divine";
inherit "/inherit/player/introduce";

/* definations */

#define AUTOSAVE        2000
#define VERS            20    // Changing this will force all users with

#define GOOD            501
#define EVIL            -501
#define LAW             501
#define CHAOS           -501

/* saveable variables */

string plan;

string current_language;
string password;
string email;
string cwd;
string start;
string real_name;
string surname;
string title;
string status;
string last_host;
string ident_user;
string prompt;
string spouse;
string eyetype;
string eyecolor;
string complexion;
string hairtype;
string haircolor;

string *father;
string *mother;
string *shrine;

int married;

int thirst = 10000;
int hunger = 20000;

int true_age;
int save_age;
int creation_date;
int creation_time;
int last_date;
int version;
int debug_level;
int term;
int sclear;
int client;
int loan;
int reward;
int killed;
int experience;

int hairlength;
int beardlength;

int rows = 24;
int columns = 80;

private int security;

mapping kills = ([ ]);
mapping channels = ([ ]);
mapping religions = ([ ]);
mapping saved_items = ([ ]);

/* experience */

mapping kexp = ([ ]); /* experience gained from killing */
int     dexp = 0;     /* experience gained from death   */
int     eexp = 0;     /* experience gained from explore */

/* non-saveable variables */

static int tick;
static int autosave;
static int auth;

static mapping last_info = ([ "say"     : ({ }),
  "shout"   : ({ }),
  "whisper" : ({ }),
  "tell"    : ({ }), ]);

/* function prototypes (no applies) */

int query_married();
int set_married(int);
int satiate_me(int);
int hydrate_me(int);
string set_spouse(string);
string query_spouse();
varargs void setup (string);
string stat_me ();
int force_us (string);
mixed query_channel (string);
int enable_channel (string);
int disable_channel (string);
string * query_last (string);
int add_last (string, string);
// string short (object);
string long ();
string query_cwd ();
int newuser (string);
nomask int query_security ();
void save_me ();
int set_ident (string);
string query_ident ();

int
query_level ()
{
  return THOB->query_experience() / 1000 < 1 ? 1 : THOB->query_experience() / 1000;
}

int
query_shrine (string str)
{
  if (!shrine)
    return 0;

  if (member_array(str, shrine) > -1)
    return 1;
  else
    return 0;
}

string *
add_shrine (string str)
{
  if (!shrine)
    return shrine = ({ str });
  else
    return shrine += ({ str });
}

int
query_experience ()
{
return THOB->query_explore()*25 + 
       THOB->query_kexp()*2 +
       (THOB->query_age() - THOB->query_idle_time()) / 2500 +
       THOB->query_dexp()*-100;
}

int
query_eexp ()
{
  return eexp;
}

int
add_eexp (int i)
{
  return eexp += i;
}

int
query_dexp ()
{
  return dexp;
}

int
add_dexp (int i)
{
  dexp += i;
}

int
query_kexp ()
{
  int i;
  string *k;

  if (kexp)
    k = keys (kexp);

  if (k)
    {
      for (int j=0;j<sizeof(k);j++)
        {
          if (sizeof(kexp[k[j]]) > 1)
            i += kexp[k[j]][1];
        }
    }

  return i;
}

mapping
query_kexp_map ()
{
  return kexp;
}

int
add_kexp (int i, string race)
{
  if (!race || !i || !intp(i))
    return 0;

  if (!kexp) {
    kexp = ([ ]);
    kexp[race] = ({ 1, i });
  } else {
    if (sizeof(kexp[race]) < 1)
      kexp[race] = ({ 1, i });
    else if (sizeof(kexp[race]) < 2)
      kexp[race] = ({ kexp[race][0]+=1, i });
    else
      kexp[race] = ({ kexp[race][0]+=1, kexp[race][1]+=i });
  }

  return i;
}

int
query_rows ()
{
  if (rows < 1)
    return 24;

  return rows;
}

int
query_columns ()
{
  if (columns < 1)
    return 80;

  return columns;
}

int
add_killed (int i)
{
  return killed += i;
}

int
query_killed (int i)
{
  return killed;
}

// DESCRIPTION : driver apply: called when player object is cloned
// CODER       : namhas

void
create (int arg)
{
    living::create();

    if (age < (((60*24*28*8)*17)/3*5))
    {
	age     = ((60*24*28*8)*17)/3*5;
	max_age = ((60*24*28*8)*80)/3*5;
    }

    set_max_sight (3);
    set_min_sight (1);

    if (arg)
	return;

    version  = VERS;

    hunger = THOB->query_max_hunger();
    thirst = THOB->query_max_thirst();
    shrine = 0;
    married = 0;

    THOB->set_position (POS_STANDING); 

    if (name)
      return;

    security = SEC0;
    name     = "(null)";
    true_age = 1;
    THOB->initialize_magical_true_names();

    init_armour_slots("humanoid");

    enable_channel("ooc");
    enable_channel("announce");
}

// DESCRIPTION : driver apply: called every heartbeat (3s)
// CODER       : namhas

void
heart_beat ()
{
    living::heart_beat();

    if (0)
    {
      thirst--;
      hunger--;
    }

    if (thirst < 0)
      thirst = 100 + random(200);

    if (hunger < 0)
      hunger = 100 + random(200);

    autosave++;
    age++;

    true_age += 2;

    // if (thirst % 300 == 0) /* once in a 2.5 minute */
   if (0)
      {
        switch (thirst*100/THOB->query_max_thirst())
          {
            case 25..20:
              tell_object (THOB, "You feel like you could go for a drink.\n");
              break;
            case 19..10:
              tell_object (THOB, "You feel you better drink something.\n");
              break;
            case 9..1:
              tell_object (THOB, "You are thirsty.\n");
              THOB->add_hp (-random(2));
              THOB->add_ep (-random(3));
              THOB->add_sp (-random(2));
              break;
            case 0:
              tell_object (THOB, "You are DEHYDRATING rapidly.\n");
              THOB->add_hp (-random(10));
              THOB->add_ep (-random(50));
              THOB->add_sp (-random(10));
              break;
          }
      }

    if (autosave > AUTOSAVE)
    {
	autosave = 0;
	THOB->save_me ();
    }
}

// DESCRIPTION : driver apply: called when interactive's has died
// CODER       : namhas

void
net_dead ()
{
    object ob, *arr;

    ob = clone_object ("/obj/statue");
    ob->set_player_name (name);
    ob->set_query_race (race);
    ob->move (environment(THOB));

    start = file_name(environment(THOB));

    arr = all_inventory(environment(THOB));
    arr += ({ THOB });

    message ("announce",
      "Info: ^c1" + capitalize(name) + "^c0 turns into a statue.\n",
      users(), arr);

    o_room (THOB->query_cap_name() + " turns into a life-sized statue.");
    move ("/world/misc/void");
    THOB->save_me ();
}

// DESCRIPTION : driver apply: called when interactive reconnects
// CODER       : namhas

void
reconnect ()
{
    object *ob, *arr;
    o_line ("Reconnected.\n");

    THOB->save_me ();

    if (start)
      {
        if (catch(move(start)))
          {
            move ("/world/hilltop/rooms/room1");
          }
      }
    else
	move ("/world/hilltop/rooms/room1");

    command ("look");

    ob = all_inventory(environment(THOB));

    arr = all_inventory(environment(THOB));
    arr += ({ THOB });

    message ("announce",
      "Info: ^c1" + capitalize (name) + "^c0 becomes alive.\n",
      users(), arr);

    for (int i=0;i<sizeof(ob);i++)
    {
	if (ob[i]->query_player_name() == name) {
	    o_room (capitalize(ob[i]->short())+" becomes alive!");
	    destruct (ob[i]);
	}
    }
}

// DESCRIPTION : driver apply: called when asked for standard input
// CODER       : namhas

void
write_prompt ()
{
    string str;
    int max_ep, max_sp, max_hp;

    if (prompt) {
	str = prompt;

	/* to avoid division by zero -- namhas */

	max_ep = THOB->query_max_ep();
	max_sp = THOB->query_max_sp();
	max_hp = THOB->query_max_hp();

	if (!max_ep)
	    max_ep = 1;
	if (!max_hp)
	    max_hp = 1;
	if (!max_sp)
	    max_sp = 1;

	/*
		str = replace_string (str, "<hp>", "" + hp);
		str = replace_string (str, "<sp>", "" + sp);
		str = replace_string (str, "<ep>", "" + ep);
		str = replace_string (str, "<maxhp>", "" + max_hp);
		str = replace_string (str, "<maxsp>", "" + max_sp);
		str = replace_string (str, "<maxep>", "" + max_ep);
	*/
	str = replace_string (str, "<hp>", "" + hp * 100 / max_hp);
	str = replace_string (str, "<sp>", "" + sp * 100 / max_sp);
	str = replace_string (str, "<ep>", "" + ep * 100 / max_ep);
	str = replace_string (str, "<money>", "" + query_money());
	str = replace_string (str, "<lf>", "\n");
	str = replace_string (str, "<cr>", "\r");
	str = replace_string (str, "<explore>", "" + query_explore_percent());
	str = replace_string (str, "<rooms>", "" + query_explore());
	str = replace_string (str, "<time>", "" + ctime(time())[11..15]);

	if (security)
	    str = replace_string (str, "<cwd>", "" + cwd);

	o_prompt (str);
    }
    else
    {
	if (cwd) {
	    o_prompt ("^c0^c1majik^c0: ^c1"+cwd+"^c0 > ");
	}
	else {
	    o_prompt ("^c0^c1majik^c0> ");
	}
    }
}

// DESCRIPTION : initialize player object, called from login object
// CODER       : namhas

varargs void
setup (string str)
{
    int diff, oid;
    string tmp, base, *k;
    object ob;

    if (!restore_object ("/data/player/" + str[0..0] + "/" + str))
	o_fatal ("Could not restore object from save file.\n");

    if (file_size("/data/config/news") > 0)
      cat ("/data/config/news");

    if (name)
		set_living_name (name);

    if (!name)
		name = str;

    if (file_size("/log/"+name+".rep") > 1)
		efun::write(read_file("/log/"+name+".rep"));

	
    if (save_age) {
	diff = TIME_D->gtime() - save_age;
	age += diff/3*5;
    }

    last_date = time();
    last_host = query_ip_name();

    if (start)
    {
	switch (diff/3*5)
	{
	case 0..10:
	    tmp = "a few minutes long";
	    break;
	case 11..60:
	    tmp = "a less than hour long";
	    break;
	case 61..120:
	    tmp = "a few hours long";
	    break;
	case 121..719:
	    tmp = "an almost half day long";
	    break;
	case 720..1439:
	    tmp = "an over half day long";
	    break;
	case 1440..2000:
	    tmp = "an over one day long";
	    break;
	default:
	    tmp = "a too long";
	    break;
	}

	efun::write ("Good "+TIME_D->query_time_of_day()[6..<2]+", "+THOB->query_cap_name()+"! You wake up from "+tmp+" sleep.\n");
    }

    if (version < VERS)
    {
	efun::write ("Your player object is too old, moving to reincarnation...\n");
    }

    enable_commands ();

    if (!cwd && security > 0)
	cwd = "/home/"+name+"/";

    if (version < VERS)
    {
	THOB->create (0);
	version = VERS;
	move ("/world/misc/race");
	"/world/misc/race"->init(THOB);
    }
    else if (start)
      {
        if (catch(move(start)))
          move ("/world/misc/race");
        else
	  move (start);
      }
    else {
	move ("/world/misc/race");
	"/world/misc/race"->init(THOB);
    }

    if (start)
    {
	message ("9", "Info: ^c1" + THOB->query_cap_name() + "^c0 wakes up.\n",
	  users(), all_inventory(environment(THOB)));
	o_room (THOB->query_cap_name() + " wakes up from "+tmp+" sleep.");
    }
    else
    {
	message ("9", "Info: ^c1" + THOB->query_cap_name() + "^c0 is a new player.\n",
	  users(), all_inventory(environment(THOB)));
	o_room (THOB->query_cap_name() + " wakes up and seems to be rather confused.");
    }

    if (security >= SEC1)
	{
		set_author (name);
	    if (file_size("/home/"+name+"/"+name+".rep") > 1)
			efun::write(read_file("/home/"+name+"/"+name+".rep"));
	}
	else
		set_author ("mortal");

    if (saved_items)
      {
        k = keys (saved_items);

        for (int i=0;i<sizeof(k);i++)
          {
            if (file_size (base_name(k[i]) + ".c") < 1)
              continue;

            ob = clone_object (base_name(k[i]));
            ob->restore_map (saved_items[k[i]]);
            ob->create_item();
            ob->move (THOB);

            if (ob)
              {
                ob->init (0);
                THOB->init (0);
              }
          }
      }

    saved_items = ([ ]);

    THOB->update_worn_armour();
    THOB->update_wielded_weapon();

    call_out ("do_auth", 0);
    add_action ("commandHook", "", 1);
}

//DESCRIPTION : set spouse for player marriages
//CODER : Madrid
string 
set_spouse(string who)
{
    return spouse = who;
}

//DESCRIPTION : query spouse for player marriages
//CODER : Madrid
string 
query_spouse()
{
    return spouse;
}

//DESCRIPTION : for making player less hungry
//CODER : Madrid
int
satiate_me(int amount)
{
  return hunger += amount;
}

int
hydrate_me(int amount)
{
  return thirst += amount;
}

//DESCRIPTION : set if player is married
//CODER : Madrid
int
set_married(int i)
{
    return married = i;
}

//DESCRIPTION : query married status
//CODER : Madrid
int
query_married()
{
    return married;
}

// DESCRIPTION : query surname
// CODER: Dazzt

string query_surname()
{
    return surname;
} 

query_thirst ()
{
  return thirst;
}

query_hunger ()
{
  return hunger;
}

query_max_thirst ()
{
  if (!THOB->query_siz())
    return 4000;

  return THOB->query_siz()*1000;
}

query_max_hunger ()
{
  if (!THOB->query_siz())
    return 9000;

  return THOB->query_siz()*2000;
}

void
do_auth ()
{
    "/command/admin/ident"->main (name);
}

// DESCRIPTION : saves player object
// CODER       : namhas

void
save_me ()
{
    object o, *all;
    string path;

    all = all_inventory(THOB);

    saved_items = ([ ]);

    foreach (o in all) {
      if (!o->query_no_autoload())
        saved_items[file_name(o)] = o->save_map();
    }

    save_age = TIME_D->gtime();

    path = "/data/player/" + name[0..0];
    if (file_size(path) != -2)
        mkdir (path);
    save_object (path + "/" + name);
    saved_items = ([ ]);
}

// DESCRIPTION : called from /command/immortal/stat
// CODER       : namhas

string
stat_me ()
{
    return (string) living::stat_me() + "PLAYER OBJECT\n";
}

// DESCRIPTION : allow another objects to force a command
// CODER       : namhas

int
force_us (string str)
{
    return command (str);
}

// DESCRIPTION : query channel mapping
// CODER       : dazzt

mixed
query_channel (string chan)
{
    if (!channels)
	channels = allocate_mapping (10);

    return channels[chan];
}

// DESCRIPTION : enable channel in channel mapping
// CODER       : dazzt

int
enable_channel (string chan)
{
    return channels[chan] = 1;
}

// DESCRIPTION : disable channel in channel mapping
// CODER       : dazzt

int
disable_channel (string chan)
{
    return channels[chan] = 0;
}

// DESCRIPTION : returns an array of last messages on given channel
// CODER       : namhas

string *
query_last (string channel)
{
    return last_info[channel];
}

// DESCRIPTION : adds a message to last messages database on given channel
// CODER       : namhas

int
add_last (string channel, string str)
{
    if (sizeof (last_info[channel]) > 15)
	last_info[channel] -= ({ last_info[channel][0] });

    return (int) last_info[channel] += ({ str });
}

string
query_name (object o)
{
  if (o)
    {
      if (!THOB->test_known(o))
        return THOB->query_stranger_name();
    }

  return ::query_name();
}

// DESCRIPTION : return short description for player
// CODER       : namhas

string
short (object o)
{
  if (o)
    {
      if (!THOB->test_known(o))
        return THOB->query_stranger_short();
    }

    if (!race)
	race = "raceless";

    if(!surname||surname=="")
	short_desc = capitalize(name) + ", the " + race + " ";
    else
	short_desc = capitalize(name) + " " + capitalize(surname) + ", " +
	"the " + race + " ";

    if (!title && !security)
	title = "adventurer";
    else if (!title)
	title = "coder";

    short_desc += title;

    if (resting)
	short_desc += " (resting)";

    if (frozen)
	short_desc += " (frozen)";

    return short_desc;
}

// DESCRIPTION : return long description for player
// CODER       : namhas, some revisions by yorkaturr

string
long ()
{
    string buf = "";
    string ages;
    string gend;
    string races;
    string hairdesc;
    string build;
    string heights;
    string charisma;
    string eye1, eye2;
   
    string pfx;
    if (subrace)
	races = capitalize(subrace) + " " + race;
    else
	races = race;

    if (gender == 2)
	gend = "female";
    else if (gender)
	gend = "male";
    else
	gend = "neuter";
    
    switch (THOB->query_cha())
    {
    case -99999..3:
      charisma = "repulsive";
      break;
    case 4..8:
      charisma = "ugly";
      break;
    case 9..12:
      charisma = "common";
      break;
    case 13..14:
      charisma = "good";
      break;
    case 15..18:
      charisma = "adorable";
      break;
    default:
      charisma = "beautiful";
      break;
    }

    switch (THOB->query_stu() + THOB->query_str())
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
	build = "rather normal";
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
    case 40..5000:
	build = "large and heavily muscled";
	break;
    }

    if (THOB->query_alignx() > 500) /* good */
    {
      if (THOB->query_aligny() > 500)
        eye1 = "valiant";
      else if (THOB->query_aligny() < -500)
        eye1 = "fanatic";
      else
        eye1 = "understanding";
    }
    else if (THOB->query_alignx() < -500) /* evil */
    {
      if (THOB->query_aligny() > 500)
        eye1 = "deadly";
      else if (THOB->query_aligny() -500)
        eye1 = "murderous";
      else
        eye1 = "evil";
    }
    else /* neutral */
    {
      if (THOB->query_aligny() > 500)
        eye1 = "righteous";
      else if (THOB->query_aligny() < -500)
        eye1 = "arrogant";
      else
        eye1 = "nondescript";
    }

    if (THOB->query_pow() > THOB->query_cha())
    {
      switch (THOB->query_pow())
        {
          case -99999..3:
            eye2 = "darting";
            break;
          case 4..9:
            eye2 = "suspicious";
            break;
          case 10..12:
            eye2 = "common";
            break;
          case 13..15:
            eye2 = "keen";
            break;
          case 16..18:
            eye2 = "calculating";
            break; 
          default:
            eye2 = "adamant";
            break;
         }
      }
    else
      {
        switch (THOB->query_cha())
          {
          case -99999..3:
            eye2 = "repulsive";
            break;
          case 4..9:
            eye2 = "quite ugly";
            break;
          case 10..12:
            eye2 = "normal";
            break;
          case 13..15:
            eye2 = "charismatic";
            break;
          case 16..18:
            eye2 = "adorable";
            break;
          default:
            eye2 = "beautiful";
            break;
         }
      }

    switch (hairlength)
    {
    case 0:
	hairdesc = 0;
	break;
    case 1..19:
	hairdesc = "very short";
	break;
    case 20..39:
	hairdesc = "short";
	break;
    case 40..59:
	hairdesc = "shoulder long";
	break;
    case 60..79:
	hairdesc = "long";
	break;
    default:
	hairdesc = "very long";
	break;
    }

    switch ((age/100)*100/(max_age/100))
    {
      case 0:
        ages = "newborn baby";
        break;
      case 1..3:
        ages = "baby";
        break;
      case 4..20:
	ages = "very young";
	break;
      case 21..39:
	ages = "young";
	break;
      case 40..69:
	ages = "middle-aged";
	break;        
      case 70..79:
	ages = "rather old";
	break;
      case 80..89:
	ages = "old";
	break;
      case 90..99:
	ages = "very old";
	break;
      default:
	ages = "ancient";
	break;
    }

    buf += short(previous_object(1)) + ".\n";

    switch(ages)
    {
    case "ancient":
	pfx = "an";
	break;
    default:
	pfx = "a";
	break;
    }
    if (eyecolor)
    {
      buf += capitalize(query_pronoun()) + " is "+article(charisma)+" looking "+
        ages+" "+races+" "+gend+". "+capitalize(query_pronoun()) + " "+
        "is "+build+". ";

      if (!hairdesc)
        buf += capitalize(query_pronoun()) + " has no hair. ";
      else
        buf += capitalize(query_pronoun()) + " has "+hairdesc+" "+
        hairtype + " " + haircolor + " hair. ";

      buf += capitalize(query_possessive()) + " "+eyecolor+" eyes are "+
      eye1 + " and " + eye2 + ". ";
    }

    if (!current_stats[8])
	return wrap(buf)+"He is a formless idiot, carrying huge amount of bugs.\n";
    else if (frozen)
	return wrap(buf)+capitalize(query_pronoun())+" is a ice cube.\n";
    else {
	return wrap(buf)+"\n"+THOB->query_shapestring(1);
    }
}

// DESCRIPTION : sets a current working directory
// CODER       : namhas

string
set_cwd (string str)
{
    if (file_size(str) != -2)
	return 0;

    cwd = str;

    if (cwd[strlen(cwd)] != '/')
	cwd += "/";

    if (cwd[0] != '/')
	cwd = "/" + cwd;

    return cwd;
}

// DESCRIPTION : returns a current working directory
// CODER       : namhas

string
query_cwd ()
{
    if (!cwd || cwd == "")
	return "/";
    else
    {
	if (cwd[0] != '/')
	    cwd = "/" + cwd;

	if (cwd[<1] != '/')
	    cwd += "/";

	return cwd;
    }
}

// DESCRIPTION : security hole
// CODER       : namhas

nomask int
query_security ()
{
    return security;
}

// DESCRIPTION : obsolete
// CODER       : namhas

int
more_file (string str)
{
    "/command/immortal/more"->main (str);
    return 1;
}

int
more_string (string str)
{
    "/command/immortal/more"->main_string (str);
    return 1;
}

// DESCRIPTION : this function does something funny
// CODER       : namhas

mixed *
query_poks ()
{
    return commands ();
}

// DESCRIPTION : stuff for identd
// CODER       : namhas

int
set_ident (string str)
{
    ident_user = str;
    auth = 1;
}

string
query_ident ()
{
    return ident_user;
}

int
query_debug ()
{
    return debug_level;
}

int
query_criminal ()
{
    return reward;
}

int
add_crimes (int i)
{
    return reward += i;
}

int
add_religion (string rel, int pts)
{
    if (!religions)
	religions = ([ ]);

    if (religions[rel])
	religions[rel] = pts;
    else
	religions[rel] += pts;

    return religions[rel];
}

mapping
query_kills ()
{
    return kills;
}

/* cendor kludge(tm) commented out

nomask int set_security (int newi) {
  int old_level;
  old_level = security;
if(!THIS || !interactive(THIS)) return 0;
if(THIS->query_security() < 51) return 0;
if(THIS->query_security() < 71 && !old_level) return 0;
if(THIS->query_security() <= old_level) return 0;
if(newi >= THIS->query_security()) return 0;
if(newi > 100 || newi < 0) return 0;
if(THIS->query_security() < 71 && newi < 1) return 0;
security = newi;
if(newi > old_level)
  tell_object(THOB, "You raise " + (newi-old_level) + " levels.\n");
else
  tell_object(THOB, "You have been demoted " + (old_level-newi) +" levels.\n");
  tell_object(THOB, "You are now level " + newi + ".\n");
tell_object(THIS,"You have promoted " + THOB->query_name() + " to level " + newi + ".\n");
write_file("SECURITY",THIS->query_name() + " promoted " +
		      THOB->query_name() + " to level " +
		      newi + " at " + ctime(time()) + ".\n");
return security;
}
*/
