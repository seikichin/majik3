#pragma strict_types

inherit BASE;

/* definations */

#define PREV		previous_object()
#define pline(x)	message ("0", x, THIS ? THIS : PREV);
#define room(x)		message ("3", x, THOB);

/* global saveable variables */

/* global non-saveable variables */

static mapping exits = ([ ]);
static mapping doors = ([ ]);
static mapping items = ([ ]);

static string * fob    = ({ });
static string * sounds = ({ });

static string area = "";

static int light;
static int outdoors;
static int sound_delay;

static int wzoney;
static int wzonex;

static int blood;

static int no_explore;
static int no_monster;
static int no_wrap;
static int no_clean_up;

static int water;

/* function prototypes */

void add_exit    (string, string);
void remove_exit (string);
void add_door    (string, string, string, string, string, int, int);
void remove_door (string);
void add_item    (mixed, string);
void remove_item (string);
void add_object  (string);

string convert_exit (string);
string long         ();
string short        ();
string show_exits   ();
string show_doors   ();
string show_blood   ();
string query_area   ();
string set_area     (string);

string * query_fob ();

mapping query_doors ();
mapping query_exits ();
mapping query_items ();

mapping set_doors (mapping);

int do_move           ();
int clean_up          (int);
int set_light         (int);
int set_outdoors      (int);
int set_sounds        (int, mixed);
int add_sound         (string);
int query_light       ();
int query_outdoors    ();
int set_no_explore    (int);
int set_no_monster    (int);
int set_no_wrap       (int);
int set_no_clean_up   (int);
int query_no_explore  ();
int query_no_monster  ();
int query_no_wrap     ();
int query_no_clean_up ();
int do_sound          ();
int query_light_level ();

/* obsolete */

mixed * query_exit_dir  ();
mixed * query_exit_dest ();

int
set_water (int i) /* water level in cm's */
{
  return water = i;
}

int
query_water (int i)
{
  return water;
}

void
create ()
{
  string o;

  THOB->create_room ();

  foreach (o in fob)
    {
      if (find_object(o))
        clone_object(o)->move (THOB);
      else
        load_object(o)->move (THOB);
    }
}

void
init ()
{
  string e, *k;

  k = keys(exits);

  add_action ("do_move", "north");
  add_action ("do_move", "south");
  add_action ("do_move", "east");
  add_action ("do_move", "west");

  add_action ("do_move", "northwest");
  add_action ("do_move", "northeast");
  add_action ("do_move", "southwest");
  add_action ("do_move", "southeast");

  foreach (e in k)
    {
      if (e != "north" && e != "south" && e != "west" && e != "east"
       && e != "northwest" && e != "northeast" && e != "southwest"
       && e != "southeast") 
         add_action ("do_move", e);
    }

  THOB->init_room ();

  remove_call_out ("do_sound");
  call_out ("do_sound", (sound_delay/2+random(sound_delay/2)));
}

int
is_room ()
{
  return 1;
}

int
clean_up (int i)
{
  object o, *inv;

  if (no_clean_up)
    return 0;

  inv = all_inventory(THOB);

  foreach (o in inv)
    if (interactive(o))
      return 1;

  destruct (THOB);
  return 1;
}

void
add_exit (string dir, string dest)
{
  exits[dir] = dest;
}

void
remove_exit (string dir)
{
  map_delete (exits, dir);
}

string
convert_exit (string str)
{
  switch (str)
    {
      case "north"     : return "n";
      case "west"      : return "w";
      case "south"     : return "s";
      case "east"      : return "e";
      case "northwest" : return "nw";
      case "northeast" : return "ne";
      case "southwest" : return "sw";
      case "southeast" : return "se";
      case "up"        : return "u";
      case "down"      : return "d";
      default          : return str;
    }
}

void
add_item (mixed key, string item)
{
  if (arrayp(key))
    items[implode(key, " ")] = item;
  else
    items[key] = item;
}

void
remove_item (string key)
{
  map_delete(items, key);
}

void
add_door (string dir, string dest, string id, string material, string key, int difficulty, int state)
{
  doors[dir] = ({ dest, id, material, key, difficulty, state });
    if (state == 0)
	add_exit(dir, dest);
}

void
remove_door (string dir)
{
  map_delete(doors, dir);
}

void
add_object (string ob)
{
  if (!fob)
    fob = ({ ob });
  else
    fob += ({ ob });
}

string
show_doors ()
{
    string m, *k, *n, s;
    int j;

    k = keys(doors);
    m = "";
    n = ({ "zero", "one", "two", "three", "four", "five", "six",
           "seven", "eight", "nine", "ten" });

    j = sizeof(k);

    if (j<1)
      return m;

    for (int i=0;i<j;i++)
      {
        if (j>1 && !i)
          m += "\nThere are "+n[j]+" doors. A ";
        else if (!i)
          m += "\nThere is a ";

        if (!doors[k[i]][5])
          s = 0;
        else if (doors[k[i]][5] == 1)
          s = "closed";
        else
          s = "locked";

        if (s)
        m += s+" "+doors[k[i]][2]+" "+doors[k[i]][1]+" leading "+k[i]+"";
        else
        m += doors[k[i]][2]+" "+doors[k[i]][1]+" leading "+k[i]+"";

        if (i==j-2)
          m += " and a ";
        else if (i==j-1)
          m += ".";
        else
          m += ", a ";

      }
    return m;
}


string
show_exits ()
{
  string buf = "", *k;
  int sz;

  k = keys (exits);
  sz = sizeof (exits);

  switch (sz)
    {
      case 0:
        return "There are no obvious exits.";
      case 1:
        return "Obvious exit is: ^c1"+k[0]+"^c0.";
      default:
        for (int i=0;i<sz;i++)
          {
            buf += "^c1" + convert_exit(k[i]);

            if (i==sz-2)
              buf += "^c0 and ";
            else if (i<sz-2)
              buf += "^c0, ";
          }

        return "Obvious exits are: "+buf+"^c0.";
    }
}

string
long ()
{
  string buf = "", meps, sh, col;

  int clarity;

  clarity=THIS->query_vision_clarity(query_light_level());

  if(clarity<0)
    {
      if(clarity==-1)
        return "It is too dark for you to see here.\n";
      else
        return "It is too bright for you to see here.\n";
    }

meps = THOB->extra_long();

  if (!meps)
  {

/*
  if (THIS->query_security())
    buf += "File name: ^cc[^c0 "+file_name()+" ^cc]^c0\n";
*/

  sh = base::short();
  if (sh[<1] != '.')
    sh += ".";

  buf += "^cG" + sh + "^c0\n";

  if (TIME_D->query_season() == "summer" || TIME_D->query_season() == "spring")
    col = "^cg";
  else
    col = "^cc";

  if (outdoors != 4)
    col = "^cy";

  if (query_light_level() <= 0)
    col = "^cL";

  if (!no_wrap) {
  buf += col+replace_string(base::long(), "\n", " ") + " " + show_doors() + show_blood() + "\n";
  }
  else
  buf += col+base::long() + " " + show_doors() + show_blood() + "\n";
  }
  else
  buf += meps;

  /* buf += "^c0" + show_exits();*/

  if (buf[<1] != ' ')
    buf += " ";

  return "^c0" + buf + "\n";
}

string
short ()
{
  string *k;
  int clarity;

  clarity=THIS->query_vision_clarity(query_light_level());

  if(clarity<0)
    {
      if(clarity==-1)
        return "It is too dark for you to see here.\n";
      else
        return "It is too bright for you to see here.\n";
    }

  k = keys(exits);

  for(int i=0;i<sizeof(k);i++)
    k[i] = convert_exit(k[i]);

  return "^cG" + base::short() + "^c0 (^c1" + implode(k, "^c0,^c1") + "^c0)";
}

int
slow_move (string s1, string s2)
{
  THIS->move_player(s1, s2);
  return 1;
}

int
do_move ()
{
  int x, y, k1, k2;
  string verb, terrain, *ex, *ey, *ox, *oy, suunta, *k;
  mapping vittu = ([ ]);
  object ob;

  verb = query_verb();

  if (THIS->query_position() < POS_STANDING)
    {
      switch (THIS->query_position())
        {
      case POS_DEAD:
        write ("You can't move while being dead.\n");
        break;
      case POS_STUNNED:
        write ("All you can do right now is think about the stars!\n");
        break;
      case POS_UNCONS:
        write ("You are in pretty bad shape, unable to do anything!\n");
        break;
      case POS_SLEEPING:
        write ("In your dreams, or what?\n");
        break;
      case POS_RESTING:
        write ("Nah... You feel too relaxed to do that..\n");
        break;
      case POS_SITTING:
        write ("Maybe you should get on your feet first?\n");
        break;
      case POS_FIGHTING:
        write ("No way! You're fighting for your life!\n");
        break;
       }
      return 1;
     }

  if (!exits[verb])
    write ("You can't go to that way.\n");

  if (exits[verb])
  {
    ob = load_object(exits[verb]);
    if (ob) terrain = ob->query_terrain();
  }
/*
    terrain = exits[verb]->query_terrain();
*/

  if (THIS && (THIS->query_ep() < -random(20) || THIS->query_hp() < -random(20)))
    {
      write ("You are too tired to move.\n");
      return 1;
    }

  if (THIS->query_security() < 51)
    {
      switch (terrain)
        {
          case "mountain":
            if (!present("climbing set", THIS))
              {
                write ("You need special equipment to scale mountains.\n");
                return 1;
              }
            else
              {
                write ("You use your climbing set to scale the mountain.\n");
                THIS->add_ep (-random(20));
                break;
              }
          case "volcano":
            write ("You can't move through volcanoes!\n");
            return 1;
          case "peak":
            write ("The peak is too high for you.\n");
            return 1;
        }
    }

  THIS->move_player (exits[verb], verb);

  if (exits[verb])
    exits[verb]->start_drown(THIS);

  if (terrain && terrain != "road")
    THIS->add_ep(-random(3));
  else if (terrain)
    THIS->add_ep(-random(2));
  else if (!random(100))
    THIS->add_ep(-random(2));

  if (THIS->query_ep() < 0)
    THIS->add_hp(-random(2));

/* 
  x = THIS->query_gridmap ()[0];
  y = THIS->query_gridmap ()[1];

  vittu = ([ "north"     : ({ ({ 3, 4, 5 }), ({ 0 }),
                              ({ 3, 4, 5 }), ({ 5 }) }),
             "south"     : ({ ({ 3, 4, 5 }), ({ 5 }),
                              ({ 3, 4, 5 }), ({ 0 }) }),
             "west"      : ({ ({ 0 }), ({ 2, 3 }),
                              ({ 8 }), ({ 2, 3 }) }),
             "east"      : ({ ({ 8 }), ({ 2, 3 }),
                              ({ 0 }), ({ 2, 3 }) }),
             "northwest" : ({ ({ 0, 1, 2 }), ({ 0, 1 }),
                              ({ 6, 7, 8 }), ({ 4, 5 }) }),
             "northeast" : ({ ({ 6, 7, 8 }), ({ 0, 1 }),
                              ({ 0, 1, 2 }), ({ 4, 5 }) }),
             "southwest" : ({ ({ 0, 1, 2 }), ({ 4, 5 }),
                              ({ 6, 7, 8 }), ({ 0, 1 }) }),
             "southeast" : ({ ({ 6, 7, 8 }), ({ 4, 5 }),
                              ({ 0, 1, 2 }), ({ 0, 1 }) })
           ]);

      if (!virtualp(ENV(THIS)))
        {
          if (verb == "north") {
            y--;
          }

          if (verb == "south") {
            y++;
          }

          if (verb == "west") {
            x--;
          }

          if (verb == "east") {
            x++;
          }

          if (verb == "northwest")
            {
              y--;
              x--;
            }

          if (verb == "northeast")
            {
              y--;
              x++;
            }

          if (verb == "southeast")
            {
              y++;
              x++;
            }

          if (verb == "southwest")
            {
              y++;
              x--;
            }

          k = keys(vittu);

          for (int i=0;i<sizeof(k);i++)
            {
              k1 = member_array(x, vittu[k[i]][0]);
              k2 = member_array(y, vittu[k[i]][1]);

              if (k1 > -1 && k2 > -1)
                {
                  suunta = k[i];
                  break;
                }
            }

          if (suunta)
            {
              if (!exits[suunta])
                write ("You can't go to that way.\n");
              else {
                THIS->set_gridmap (vittu[suunta][2][k1],
                                   vittu[suunta][3][k1]);                    

                THIS->move_player (exits[suunta], suunta);
              }
            }
          else if (y < 1 && x > 7)
            {
              y = 1;
              x = 7;
              write ("You can't move to that way.\n");
            }
          else if (y > 4 && x < 1)
            {
              y = 4;
              x = 1;
              write ("You can't move to that way.\n");
            }
          else if (y > 4 && x > 7)
            {
              y = 4;
              x = 7;
              write ("You can't move to that way.\n");
            }
          else if (y < 1 && x < 1)
            {
              x = 1;
              y = 1;
              write ("You can't move to that way.\n");
            }
          else if (y < 1)
            {
              y = 1;
              write ("You can't move to that way.\n");
            }
          else if (x > 7)
            {
              x = 7;
              write ("You can't move to that way.\n");
            }
          else if (y > 4)
            {
              y = 4;
              write ("You can't move to that way.\n");
            }
          else if (x < 1)
            {
              x = 1;
              write ("You can't move to that way.\n");
            }
          else
            {
              if (!ex || !ey)
                {
                  THIS->set_gridmap (4, 3);
                  THIS->move_player (exits[verb], verb);
                }
              else
                {
                  THIS->set_gridmap (x, y);
                  write ("You move to "+verb+" ["+x+","+y+"].\n");
                }
            }
        }
      else
        {
          if (!exits[verb])
            write ("You can't go to that way.\n");
          else
            THIS->move_player (exits[verb], verb);
        }
*/

  if (terrain && !THOB->query_no_clean_up())
    clean_up (0);

  return 1;
}

int
start_drown (object o)
{
  if (THOB->query_water())
    {
      if (THOB->query_water() < (o->query_height()-20))
        {
          emote ("$n {paddle} in the water.", o, 0, THOB);
          o->add_ep (-THOB->query_water()/5);
        }
      else
        {
          tell_object(o, "You are desperately fighting against drowning.\n");
          tell_room(THOB, o->query_cap_name()+ " is drowning and doesn't look good.\n",
            ({o}));
      
          call_out ("do_drown", random(5) + 1, o);
          o->add_ep (-THOB->query_water()/10);
        }
    }
}

int
do_drown (object o)
{
  if (!o)
    return 0;

  if (ENV(o) != THOB)
    return 0;

  if (o->query_ep() < 0)
    {
      tell_object (o, "You drown!\n");
      o->move_player ("/world/misc/underwater", "down");
      remove_call_out ("do_drown");
      return 1;
    }

  tell_object(THIS, "You are drowning in water.\n");
  tell_room(THOB, THIS->query_cap_name()+ " is drowning in water.\n",
    ({THIS}));

  o->add_hp (-random(10));
  o->add_ep (-(THOB->query_water()/5));

  call_out ("do_drown", random(5), o);

  return 1;
}

int
set_light (int i)
{
  return light = i;
}

int
set_outdoors (int i)
{
  return outdoors = i;
}

int
set_sounds (int i, mixed str)
{
  sound_delay = i;
  if (arrayp(str))
    sounds = str;
  else
    sounds = ({ str });

  return 1;
}

string *
query_sounds ()
{
  return sounds;
}

int
add_sound (string str)
{
  if (!sound_delay)
    sound_delay = 60;

  if (!sounds)
    sounds = ({ str });
  else
    sounds += ({ str });

  return 1;
}

int
query_light ()
{
  return light;
}

int
query_light_modifier ()
{
    int dark, bright, ll;
    object o, *all;

    all=all_inventory(this_object());
    foreach (o in all)
    {
        ll=o->query_light();
        if(ll)
        {
            if(ll<0&&dark>ll)
                dark=ll;
            else
            if(ll>0&&bright<ll)
                bright=ll;
        }
    }
    return dark+bright;
}

int
query_light_level ()
{
    int tmp;
    tmp=light+query_light_modifier();

    if(outdoors<2)
        return tmp;

    tmp+=TIME_D->query_sky_light();
    if(tmp>3)
        tmp=3;
    else
    if(tmp<-3)
        tmp=-3;
    return tmp;
}

int
query_outdoors ()
{
  return outdoors;
}

int
set_no_explore (int i)
{
  return no_explore = i;
}

int
set_no_monster (int i)
{
  return no_monster = i;
}

int
set_no_wrap (int i)
{
  return no_wrap = i;
}

int
set_no_clean_up (int i)
{
  return no_clean_up = i;
}

int
query_no_explore ()
{
  return no_explore;
}

int
query_no_monster ()
{
  return no_monster;
}

int
query_no_wrap ()
{
  return no_wrap;
}

int
query_no_clean_up ()
{
  return no_clean_up;
}

mapping
query_doors ()
{
  return doors;
}

mapping
set_doors (mapping m)
{
  return doors = m;
}

mapping
query_exits ()
{
  return exits;
}

mapping
query_items ()
{
  return items;
}

string *
query_fob ()
{
  return fob;
}

mixed *
query_exit_dest()
{
  return values (exits);
}

mixed *
query_exit_dir()
{
  return keys (exits);
}

int
do_sound ()
{
  object *all;
  int flag = 0;
  string messu;

  remove_call_out ("do_sound");

  all = all_inventory(THOB);
  flag = 0;

  for (int i=0;i<sizeof(all);i++)
    {
    if (living(all[i]) && interactive(all[i]) && !all[i]->query_npc() && query_ip_number(all[i]))
      {
        flag++;
      }
    }

  if (!flag || flag == 0)
    return 0;

  if (sizeof(sounds) == 0)
    return 0;

  messu = wrap(sounds[random(sizeof(sounds))]);
  if (messu[<1] != '\n')
    messu += "\n";

  tell_room (THOB, messu);
  call_out ("do_sound", (sound_delay/2+random(sound_delay/2)));

  return 1;
}

string
query_area ()
{
    int idx, len;
    string file, file2;

    len = strlen(file_name(THOB));
    file2 = file_name(THOB);

    if (file2[0] != '/')
      file2 = "/" + file2;

    file = file2[7..len];

    if (!area || area == "")
    {
        if (file2[0..6] == "/world/")
        {
            idx = strsrch (file, "/");
            if (idx > -1)
                return file[0..idx-1];
            else
                return "unknown";
        }
        else
        {
            return "developmental";
        }
    }
    return area;
}

string
set_area (string str)
{
  return area = str;
}

mixed query_weather_zone()
{
  if (!arrayp(THOB->query_zone()))
    return ({ wzonex, wzoney });
  else
    return THOB->query_zone();
}

int query_weather_x_zone()
{
    return wzonex;
}
int query_weather_y_zone()
{
    return wzoney;
}

int set_weather_zone(int x, int y)
{
    if(x<0||y<0||x>10||y>10)
    {
        wzonex=-1;
        wzoney=-1;
        return 0;
    }
    wzonex=x;
    wzoney=y;
    return 1;
}

string
look_item (string str)
{
	string msg = "", *k, *it;
	int idx, i;

	k = keys(items);
	for (i = 0; i < sizeof(k); i++)
	{
		idx = member_array(str, explode(k[i], " "));

		if (idx != -1)
		{
			if (items[k[i]][<1] != '\n')
				return no_wrap ? items[k[i]] + "\n" : wrap(items[k[i]]) + "\n";
			else
				return no_wrap ? items[k[i]] : wrap(items[k[i]]);
		}
	}
	return msg;
}

string
show_blood ()
{
  if (blood > 10)
    return "There is lots of blood everywhere. ";
  else if (blood > 5)
    return "There has been battle recently, lots of blood is on the ground. ";
  else if (blood > 0)
    return "There is some blood on the ground. ";
  else
    return "";
}

void
dry_blood ()
{
  remove_call_out ("dry_blood");

  if (blood < 0)
    blood = 0;

  blood -= 1;
}

int
add_blood (int i)
{
  blood += i;
  call_out ("dry_blood", random(60) + 200);
}
