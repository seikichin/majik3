#pragma strict_types

// DESCRIPTION : LPC redit - OasisOLC v1.5 clone
// CODER       : namhas
// VERSION     : 1.2

#define room(x) message ("3", x + "\n", ENV(THIS), THIS)
#define pline(x) message ("0", x + "\n", THIS)
#define prompt(x) message ("4", x, THIS)
#define fatal(x) message ("8", "\aFATAL: " + x + "\n", THIS)

#define VERSION 12

string d_short;
string d_long;
string d_file;
string d_area;

string state;
string tmp1;
string kludge;

string *fob;
string *sounds;

mapping exits;
mapping extd;

int f_light;
int f_outdoors;
int f_no_explore;
int f_no_monster;

int have_path;

int incompatible;
int line;
int eline;
int tmp2;
int kludge2;
int warn;

string deski = "";
string edesk = "";

int do_new (string);
int do_old (string);
int do_redit (string);
int do_menu ();
int do_name ();
int do_quit ();
int do_desc ();
int do_edit ();
int do_line (string);
int do_exit ();
int do_adx1 ();
int do_adx2 ();
int do_rmx1 ();
int do_modx (string);
int do_flag ();
int do_extd ();
int do_ade1 ();
int do_ade2 ();
int do_rme1 ();
int do_edit2 ();
int do_line2 (string);
int do_snds ();
int do_asnd ();
int do_rsnd ();

void
warning (string x) {
message ("9", "\aWARNING: " + x + "\n", THIS);
warn++;
}

int
main (string str)
{
    if (!str) {
	if (virtualp(ENV(THIS)))
	{
	    fatal ("You can't edit virtual objects!");
	    return 1;
	}
	str = file_name(ENV(THIS));
    }

    if (str[<2..] != ".c")
	str += ".c";

    if (!absolute_path (str))
	str = this_player()->query_cwd() + str;

    str = resolve_path (str);

    if (file_size (resolve_path(THIS->query_cwd() + "../path.h")) > 1)
      have_path = 1;
    else {
      have_path = 0;
      warning ("You don't have ^c1path.h^c0 file in directory /"+resolve_path(THIS->query_cwd()+ "../") + "/.");
    }

    if (file_size (str) < 1)
    {
	do_new (str);
	return 1;
    }
    else
    {
	do_old (str);
	return 1;
    }
}

int
do_new (string str)
{
    d_short = "An unfinished room";
    d_long = "You are in an unfinished room.";
    d_file = str;
    d_area = ENV(THIS)->query_area();

    f_light = 0;
    f_outdoors = 0;
    f_no_monster = 0;
    f_no_explore = 0;

    do_redit (str);
    return 1;
}

int
do_old (string str)
{
    int vers, n, sz;
    string *dir, *dest, out;

    d_short = str->query_short();
    d_long = str->query_long();
    d_long = replace_string(d_long, "\n", " ");
    d_long = replace_string(d_long, "  ", " ");

    sz = strlen(d_long);

    out = "";

    for (int j=0;j<sz;j++)
      {
        if (j < sz-2 && d_long[j] == '.' && d_long[j+1] != ' ')
          out += d_long[j..j] + " ";
        else
          out += d_long[j..j];
      }

    d_long = out;

    d_file = str;
    d_area = str->query_area();

    f_light = str->query_light();
    f_outdoors = str->query_outdoors();

    f_no_monster = str->query_no_monster();
    f_no_explore = str->query_no_explore();

    dir = str->query_exit_dir();
    dest = str->query_exit_dest();

    fob = str->query_fob();
    extd = str->query_items();
    sounds = str->query_sounds();

    exits = ([ ]);

    for (int i=0;i<sizeof(dir);i++) {
        if (have_path && dest[i][0] == '/')
          {
            n = strsrch(dest[i], "/", -1);
            dest[i] = dest[i][n+1..];
          }
            
	exits[dir[i]] = ({ i+1, dir[i], dest[i] });
    }

    vers = str->query_redit();

    if (!vers) {
	warning ("The room contains code that is not compatible with REDIT.");
	incompatible = 2;
    }
    else if (vers < VERSION) {
	warning ("The room is old and is not REDIT v1.2 compatible.");
	incompatible = 1;
    }

    do_redit (str);
    return 1;
}

int
do_save ()
{
    object ob, *inv;
    int j, n, y;
    string ret, *key, *k;

    if (incompatible)
	pline ("The room is incompatible with REDIT v1.2 - saved with backups.");
    else
	pline ("Done.\n");

    rm (d_file + "~");
    cp (d_file, d_file + "~");
    rm (d_file);

    if (!have_path)
      {
    write_file (d_file,
      "// DATE        : "+ctime(time())+"\n"
      + "// DESCRIPTION : A generic room object created using LPC redit 1.2\n"
      + "// CODER       : "+THIS->query("name")+"\n\n"
      + "inherit ROOM;\n\n"
      + "create_room ()\n"
      + "{\n"
      + "  set_short (\""+d_short+"\");\n"
      + "  set_long (\n"
      + "    \"");
      }
    else
      {
    write_file (d_file,
      "// DATE        : "+ctime(time())+"\n"
      + "// DESCRIPTION : A generic room object created using LPC redit 1.2\n"
      + "// CODER       : "+THIS->query("name")+"\n\n"
      + "#include \"../path.h\"\n\n"
      + "inherit ROOM;\n\n"
      + "create_room ()\n"
      + "{\n"
      + "  set_short (\""+d_short+"\");\n"
      + "  set_long (\n"
      + "    \"");
      }

    d_long = wrap(d_long);
    ret = "";
    j = 0;

    /* clean it up! */

    d_long = replace_string(d_long, "  ", "");
    d_long = replace_string(d_long, "\r", "");
    d_long = replace_string(d_long, "\t", "");

    if (d_long[<1..<1] == " ")
      d_long = d_long[0..<2];

    for (int i=0;i<strlen(d_long);i++, j++)
    {
	if (d_long[i] != '\n')
	    ret += d_long[i..i];
	else if (d_long[i-1] != '\n' && d_long[i] == '\n' && i != strlen(d_long)-2)
	    ret += " ";

	if (j > 60) {
	    ret += "\"\n  + \"";
	    j = 0;
	}
    }
    ret += "\");\n";

    if (exits)
    {
	key = keys(exits);
	ret += "\n";
	for (int w=0;w<sizeof(key);w++) {
            if (have_path && exits[key[w]][2][0] == '/')
              {
                n = strsrch(exits[key[w]][2], "/", -1);
                exits[key[w]][2] = exits[key[w]][2][n+1..];
              }

            if (have_path)
              ret += "  add_exit (\""+exits[key[w]][1]+"\", ROOM_PATH + \""+exits[key[w]][2]+"\");\n";
            else
	      ret += "  add_exit (\""+exits[key[w]][1]+"\", \""+exits[key[w]][2]+"\");\n";
        }
    }

    if (extd)
    {
      k = keys(extd);

      for (int l=0;l<sizeof(k);l++)
        {
          ret += "\n";
          extd[k[l]] = replace_string(extd[k[l]], "\\", "\\\\");
          extd[k[l]] = replace_string(extd[k[l]], "\"", "\\\"");
          ret += "  add_item (\""+k[l]+"\",\n    \"";
          for (int x=0;x<strlen(extd[k[l]]);x++, y++)
            {
              if (extd[k[l]][x] != '\n')
                ret += extd[k[l]][x..x];
              else
                ret += "\\n";

          if (y > 60) {
            ret += "\"\n  + \"";
            y = 0;
          }
        }

          ret += "\");\n";
        }
    }

    if (sounds && sizeof(sounds) > 0)
    {
      ret += "\n";

      for (int g=0;g<sizeof(sounds);g++)
        {
          sounds[g] = replace_string(sounds[g], "\n", " ");
          ret += "  add_sound (\""+sounds[g]+"\");\n";
        }
    }

    if (f_outdoors || f_light || f_no_monster || f_no_explore)
      ret += "\n";

    if (f_outdoors)
      ret += "  set_outdoors ("+f_outdoors+");\n";

    if (f_light)
      ret += "  set_light ("+f_light+");\n";

    if (f_no_monster)
      ret += "  set_no_monster ("+f_no_monster+");\n";

    if (f_no_explore)
      ret += "  set_no_explore ("+f_no_explore+");\n";

    write_file (d_file, ret);
    write_file (d_file,
      "\n}\n\n"
      + "// You should REMOVE all lines below this line if you are adding special\n"
      + "// stuff to this file by hand. Otherwise scary things can happen.\n\n"
      + "query_redit ()\n"
      + "{\n"
      + "  return "+VERSION+";\n"
      + "}\n");

    ob = find_object(d_file);

    if (ob)
    {
	inv = all_inventory (ob);
	if (inv)
	    inv->move ("/world/misc/void");
	destruct (ob);
    }

    load_object (d_file);

    if (inv)
	inv->move (d_file);

    THIS->move_player (d_file);
    destruct (THOB);

    return 1;
}

int
do_redit (string str)
{
    string *key;

    if (warn)
      {
        warn = 0;
        prompt ("Press ENTER to continue: ");
        input_to ("do_redit");
        return 1;
      }

    if (str != d_file)
    {
	if (state == "main")
	{
	    switch (str)
	    {
	    case "q":
	    case "Q":
		do_quit ();
		return 1;
		break;
	    case "1":
		do_name ();
		return 1;
		break;
	    case "2":
		do_desc ();                
		return 1;
		break;
            case "3":
                do_flag ();
                return 1;
                break;
	    case "4":
		do_exit ();
		return 1;
		break;
            case "6":
                do_extd ();
                return 1;
                break;
            case "7":
                do_snds ();
                return 1;
                break;
	    }
	}

        if (state == "snds_menu")
          {
            if (lower_case(str) == "a") {
              do_asnd ();
              return 1;
            }
            if (lower_case(str) == "b") {
              do_rsnd ();
              return 1;
            }
            if (lower_case(str) == "q" || str = "0") {
              do_menu ();
              return 1;
            }

          do_snds ();
          return 1;
        }

        if (state == "do_asnd")
        {
          if (!sounds)
            sounds = ({ str });
          else
            sounds += ({ str });
          do_snds();
          return 1;
        }

        if (state == "do_rsnd")
        {
          if (sizeof(sounds) < to_int(str)) {
            do_snds ();
            return 1;
          }
          else {
            sounds -= ({ sounds[to_int(str)-1] });
          }

          do_snds();
          return 1;
        }

        if (state == "do_flag")
          {
            if (str == "1")
              f_outdoors = 1;
            else if (str == "2")
              f_outdoors = 4;
            else if (str == "3" && f_light)
              f_light = 0;
            else if (str == "3")
              f_light = 1;
            else if (str == "4" && f_no_explore)
              f_no_explore = 0;
            else if (str == "4")
              f_no_explore = 1;
            else if (str == "5" && f_no_monster)
              f_no_monster = 0;
            else if (str == "5")
              f_no_monster = 1;
            else if (str == "0" || str == "q" || str == "Q") {
              do_menu ();
              return 1;
            }

            do_flag();
            return 1;
          }

	if (state == "ask_name")
	    d_short = str;

	if (state == "ask_quit") {
	    if (lower_case(str) == "y")
		do_save();
	    else
		pline ("The room is NOT saved.");
	    return 1;
	}

        if (state == "extd_menu") {
          if (lower_case(str) == "q" || str == "0") {
            do_menu();
            return 1;
          }
          else if (lower_case(str) == "a") {
            do_ade1 ();
            return 1;
          }
          else if (lower_case(str) == "b") {
            do_rme1 ();
            return 1;
          }

          do_extd();
          return 1;
        }

	if (state == "exit_menu") {
	    if (str == "q" || str == "Q") {
		do_menu();
		return 1;
	    }
	    else if (str == "a" || str == "A") {
		do_adx1 ();
		return 1;
	    }
	    else if (str == "b" || str == "B") {
		do_rmx1 ();
		return 1;
	    }
	    else
	    {
		tmp2 = 0;
		if (exits)
		{
		    key = keys(exits);
		    for (int i=0;i<sizeof(key);i++)
		    {
			if (to_int(str) == exits[key[i]][0]) {
			    tmp2 = 1;
			    do_modx (exits[key[i]][1]);
			    break;
			    return 1;
			}
		    }
		    if (tmp2)
			return 1;
		}
		do_exit ();
		return 1;
	    }
	}

        if (state == "do_ade1") {
          tmp1 = str;
          do_ade2();
          return 1;
        }
        if (state == "do_ade2") {
            if (!extd)
            {
                extd = ([ ]);
                extd[lower_case(tmp1)] = str;
            }
            else
            {
                extd[lower_case(tmp1)] = str;
            }
            do_extd ();
            return 1;
        }          
        if (state == "do_rme1") {
            str = lower_case(str);
            key = keys(extd);
            if (member_array(str, key) == -1)
                pline ("No such description available.");
            map_delete (extd, str);
            do_extd ();
            return 1;
        }

	if (state == "remove_exit1") {
	    key = keys(exits);
	    if (member_array(str, key) == -1)
		pline ("No such exit available.");
	    map_delete (exits, str);
	    do_exit ();
	    return 1;
	}
	if (state == "add_exit1") {
            str = lower_case(str);
            if (str == "n")
              str = "north";
            if (str == "s")
              str = "south";
            if (str == "e")
              str = "east";
            if (str == "w")
              str = "west";
            if (str == "sw")
              str = "southwest";
            if (str == "se")
              str = "southeast";
            if (str == "nw")
              str = "northwest";
            if (str == "ne")
              str = "northeast";
	    tmp1 = str;
	    do_adx2 ();
	    return 1;
	}
	if (state == "add_exit2") {
	    if (!exits)
	    {
                exits = ([ ]);
		exits[tmp1] = ({ 1, tmp1, str });
	    }
	    else
	    {
		key = keys(exits);
		exits[tmp1] = ({ sizeof(key)+1, tmp1, str });
	    }
	    do_exit ();
	    return 1;
	}
	if (state == "modify_exit")
	{
	    key = keys(exits);
	    exits[kludge] = ({ kludge2, kludge, str });
	    do_exit ();
	    return 1;
	}
    }

    do_menu ();
    return 1;
}

int
do_desc ()
{
    state = "ask_desc";
    write ("\033[H\033[J");
    pline ("Old description was:\n");
    pline ("^cy" + d_long + "^c0\n");
    pline ("Enter new room description: (\".\" alone saves \"h\" for help)\n");
    deski = "";
    line = 1;
    do_edit ();
    return 1;
}

int
do_edit ()
{
    write (line + "> ");
    input_to ("do_line");
    return 1;
}

int
do_edit2 ()
{
    write (eline + "> ");
    input_to ("do_line2");
    return 1;
}

int
do_line2 (string str)
{
    string ret;

    if (str == ".")
    {
        ret = edesk;
        edesk = "";
        // for (int i=0;i<strlen(ret);i++) {
        //    if (ret[i] != '\n')
        //        edesk += ret[i..i];
        //    else
        //        edesk += " ";
        // }
        do_redit (ret);
    }
    else if (str == "h")
    {
        pline ("Available commands are:\n");
        pline ("  .\tsave and quit");
        pline ("  h\tdisplay this help page");
        pline ("  z\tdisplay whole description");
        pline ("  q\tquit without saving\n");
        pline ("No other commands available yet.");
        do_edit2 ();
    }
    else if (str == "q")
    {
        do_extd ();
    }
    else if (str == "z")
    {
        pline ("Current description is:\n");
        pline ("^cy" +edesk+ "^c0\n");
        do_edit2 ();
    }
    else
    {
        edesk += str + "\n";
        eline++;
        do_edit2 ();
        return 1;
    }

    return 1;
}

int
do_line (string str)
{
    string ret;

    if (str == ".")
    {
	ret = wrap (deski);
	d_long = "";
	for (int i=0;i<strlen(ret);i++) {
	    if (ret[i] != '\n')
		d_long += ret[i..i];
	    else
		d_long += " ";
	}
	d_long;
	do_menu ();
    }
    else if (str == "h")
    {
	pline ("Available commands are:\n");
	pline ("  .\tsave and quit");
	pline ("  h\tdisplay this help page");
	pline ("  z\tdisplay whole description");
	pline ("  q\tquit without saving\n");
	pline ("No other commands available yet.");
	do_edit ();
    }
    else if (str == "q")
    {
	do_menu ();
    }
    else if (str == "z")
    {
	pline ("Current description is:\n");
	pline ("^cy" + wrap(deski)+ "^c0\n");
	do_edit ();
    }
    else
    {
	deski += str + " ";
	line++;
	do_edit ();
	return 1;
    }

    return 1;
}

int
do_quit ()
{
    state = "ask_quit";
    prompt ("Do you wish to save this room? : ");
    input_to ("do_redit");
    return 1;
}

int
do_name ()
{
    state = "ask_name";
    prompt ("Enter room name : ");
    input_to ("do_redit");
    return 1;
}

int
do_modx (string str)
{
    state = "modify_exit";
    kludge = str;
    kludge2 = exits[str][0];
    pline  ("OLD file name  : "+exits[str][2]+"");
    prompt ("NEW file name  : ");
    input_to ("do_redit");
    return 1;
}

int
do_rmx1 ()
{
    state = "remove_exit1";
    prompt ("^c0Exit direction : ");
    input_to ("do_redit");
    return 1;
}

int
do_adx1 ()
{
    state = "add_exit1";
    prompt ("^c0Exit direction : ");
    input_to ("do_redit");
    return 1;
}

int
do_asnd ()
{
  state = "do_asnd";
  prompt ("Enter the sound here : ");
  input_to ("do_redit");
  return 1;
}

int
do_rsnd ()
{
  state = "do_rsnd";
  prompt ("Number of the sound to remove : ");
  input_to ("do_redit");
  return 1;
}

int
do_adx2 ()
{
    state = "add_exit2";
    if (have_path)
      prompt ("^c0Exit file name (ROOM_PATH) : ");
    else
      prompt ("^c0Exit file name : ");
    input_to ("do_redit");
    return 1;
}

int
do_ade1 ()
{
    state = "do_ade1";
    prompt ("^c0Description keys (separate with space): ");
    input_to ("do_redit");
    return 1;
}

int
do_ade2 ()
{
    state = "do_ade2";
    pline ("^c0Description itself (end with \".\" help with \"h\"):\n");
    edesk = "";
    line = 1;
    do_edit2();
    return 1;
}

int
do_rme1 ()
{
    state = "do_rme1";
    prompt ("^c0Description keys to remove (separate with spaces): ");
    input_to ("do_redit");
    return 1;
}

int
do_flag ()
{
  string buf = "", buf1 = "NONE";
  int counter, columns;
  string *room_bits;

  room_bits = allocate(5);

  room_bits[0] = "WINDOW";
  room_bits[1] = "OUTDOORS";
  room_bits[2] = "LIGHT";
  room_bits[3] = "NO_EXPLORE";
  room_bits[4] = "NO_MONSTER";

  buf += "\033[H\033[J";

  buf += sprintf (
      "-- Room file   : [^cc%s^c0]    Room area: [^cc%s^c0]\n",
      d_file[0..29], d_area[0..12]);

  for (counter = 0; counter < sizeof(room_bits); counter++) {
     buf += sprintf("^cg%2d^c0) %-20.20s %s", counter + 1,
              room_bits[counter], !(++columns % 2) ? "\n" : "");
  }

    if (f_outdoors == 1) {
        buf1 = "WINDOW ";
    }
    else if (f_outdoors == 4) {
        buf1 = "OUTDOORS ";
    }

    if (f_light > 0) {
        if (buf1 == "NONE")
            buf1 = "LIGHT ";
        else
            buf1 += "LIGHT ";
    }

    if (f_no_explore > 0) {
      if (buf1 == "NONE")
        buf1 = "NO_EXPLORE ";
      else
        buf1 += "NO_EXPLORE ";
    }

    if (f_no_monster > 0) {
      if (buf1 == "NONE")
        buf1 = "NO_MONSTER ";
      else
        buf1 += "NO_MONSTER ";
    }

  buf += sprintf("\nRoom flags: %s%s%s\n", "^cc", buf1, "^c0");

  pline (buf);
  prompt ("Enter room flags, 0 to quit : ");
  state = "do_flag";
  input_to ("do_redit");
  return 1;
}

int
do_snds ()
{
  string buf = "";

  buf += "\033[H\033[J";

  buf += sprintf (
      "-- Room file   : [^cc%s^c0]    Room area: [^cc%s^c0]\n",
      d_file[0..29], d_area[0..12]);

  if (sounds && sizeof(sounds) > 0)
    {
      for (int i=0;i<sizeof(sounds);i++)
        buf += sprintf("^cp%d^c0) ^cy%s\n", i+1, sounds[i][0..60]);
    }

    buf += sprintf (
      "^cgA^c0) Add sound\n" +
      "^cgB^c0) Remove sound\n" +
      "^cgQ^c0) Quit to main menu\n");

    pline (buf);
    prompt ("Enter choice : ");
    state = "snds_menu";
    input_to ("do_redit");
    return 1;
}

int
do_extd ()
{
  string buf = "";
  string *key;

  buf += "\033[H\033[J";

  buf += sprintf (
      "-- Room file   : [^cc%s^c0]    Room area: [^cc%s^c0]\n",
      d_file[0..29], d_area[0..12]);

  if (extd)
    {
      key = keys(extd);

      for (int i=0;i<sizeof(key);i++) {
        buf += sprintf (
          "^cp%d^c0) ^cy%s\n",
              i+1, upper_case(key[i]));
      }
    }

    buf += sprintf (
      "^cgA^c0) Add description\n" +
      "^cgB^c0) Remove description\n" +
      "^cgQ^c0) Quit to main menu\n");

    pline (buf);
    prompt ("Enter choice : ");
    state = "extd_menu";
    input_to ("do_redit");
    return 1;
}

int
do_exit ()
{
    string buf = "";
    string *key;

    buf += "\033[H\033[J";

    buf += sprintf (
      "-- Room file   : [^cc%s^c0]    Room area: [^cc%s^c0]\n",
      d_file[0..29], d_area[0..12]);

    if (exits)
    {
	key = keys(exits);

	for (int i=0;i<sizeof(key);i++) {
	    buf += sprintf (
	      "^cg%d^c0) Exit %-6s : %s^cy%s\n",
	      i+1, exits[key[i]][1][0..5], have_path ? "(ROOM_PATH) " : "", exits[key[i]][2]);
	}
    }

    buf += sprintf (
      "^cgA^c0) Add exit\n" +
      "^cgB^c0) Remove exit\n" +
      "^cgQ^c0) Quit to main menu\n");

    pline (buf);
    prompt ("Enter choice : ");
    state = "exit_menu";
    input_to ("do_redit");
    return 1;
}

int
do_menu ()
{
    string buf = "";
    string *key;
    string ex = "NONE";
    string fg = "NONE";

    buf += "\033[H\033[J";

    if (exits)
    {
	key = keys(exits);
	ex = "";
	for (int i=0;i<sizeof(key);i++)
	    ex += upper_case(exits[key[i]][1]) + " ";
	if (strlen(ex) < 3)
	    ex = "NONE";
    }

    if (f_outdoors == 1) {
	fg = "WINDOW ";
    }
    else if (f_outdoors == 4) {
	fg = "OUTDOORS ";
    }

    if (f_light > 0) {
	if (fg == "NONE")
	    fg = "LIGHT ";
	else
	    fg += "LIGHT ";
    }

    if (f_no_explore > 0) {
      if (fg == "NONE")
        fg = "NO_EXPLORE ";
      else
        fg += "NO_EXPLORE ";
    }

    if (f_no_monster > 0) {
      if (fg == "NONE")
        fg = "NO_MONSTER ";
      else
        fg += "NO_MONSTER ";
    }

    buf += sprintf (
      "-- Room file   : [^cc%s^c0]    Room area: [^cc%s^c0]\n" +
      "^cg1^c0) Name        : ^cy%s\n" +
      "^cg2^c0) Description :\n^cy%s" +
      "^cg3^c0) Room flags  : ^cc%s\n" +
      "^cg4^c0) Exits       : ^cc%s\n" +
      "^cp5^c0) Objects     : ^cc%s\n" +
      "^cg6^c0) Extra descriptions menu\n" +
      "^cg7^c0) Sound control menu\n" +
      "^cgQ^c0) Quit\n",
      d_file[0..29], d_area[0..12], d_short, wrap(d_long) + "\n", fg, ex, sizeof(fob) ? "" + sizeof(fob) : "NONE");

    pline (buf);
    prompt ("Enter choice : ");
    state = "main";
    input_to ("do_redit");
    return 1;
}
