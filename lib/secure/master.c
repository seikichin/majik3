inherit "/secure/secure";

object
connect ()
{
    object ob;
    mixed err;

    err = catch (ob = new ("/secure/login"));

    if (err)
    {
	efun::write ("Login attempt denied - the game is closed temporarily.\a\n");
	efun::write (err);
	destruct (this_object ());
    }

    call_out ("do_resolve", 1, ob);
    return ob;
}

void
do_resolve (object o1)
{
  object o2;
  string ip;

  o2 = find_player ("namhas");

  if (o2 && o1)
    {
      ip = query_ip_name(o1);
      if (!ip || ip == "" || ip == 0)
        ip = query_ip_number(o1);

      message ("0", "^cc[^c0 "+ctime(time())+" :: new connection from "+
        ip+" ^cc]^c0\n", o2);
    }
}

mixed
compile_object (string file)
{
  object caller;

  caller = previous_object();
  if (caller == find_object("/daemon/virtual")) return 0;
  return (object)call_other("/daemon/virtual", "compile_object", file, caller);
    return (object)call_other("/world/virtual/server", "compile_object", file); 
    return 0;
}

static void
crash (string error, object command_giver, object current_object)
{
    shout ("Game Driver shouts: Sky just fell! The game is crashing." +
      "\n");
    write_file ("/log/crash", ctime (time ()) + " :: " + MUD_NAME + " crashed, error: " +
      error + "\n");
}

static string *
update_file (string file)
{
    string *arr;
    string str;

    int    i;

    str = read_file (file);

    if (!str)
	return ({});

    arr = explode (str, "\n");

    for (i = 0; i < sizeof (arr); i++)
	if (arr[i][0] == '#')
	    arr[i] = 0;

    return arr;
}

string *
epilog (int load_empty)
{
    string *items;

    items = update_file ("/data/config/preload");

    return items;
}

void
preload (string file)
{
    string err;
    int    t1;

    if (file_size (file + ".c") == -1)
	return;

    t1 = time();

    write ("** Preloading : " + file + " ... ");

    err = catch (call_other (file, "??"));

    if (err != 0)
	write ("\n** Error " + err + " when loading " + file + "\n");
    else
    {
	t1 = time () - t1;
	write ("(" + t1/60 + "." + t1 % 60 + ")\n");
    }
}

void
log_error (string file, string message)
{
    string name, logfile;

    name = file_owner (file);

    if (name)
	logfile = "/log/" + lower_case(name);
    else
	logfile = "/log/log";

    printf ("%s", message);
    write_file (logfile, message);
}

string
make_path_absolute (string file)
{
    file = resolve_path ((string) this_player()->query_cwd(), file);
    return file;
}

string
creator_file (string str)
{
    return (string) call_other ("/secure/simul_efun", "creator_file", str);
}

string
domain_file (string str)
{
    return (string) call_other ("/secure/simul_efun", "domain_file", str);
}

string
author_file (string str)
{
    return (string) call_other ("/secure/simul_efun", "author_file", str);
}

int
view_errors (object user)
{
    return 1;
}

static void error_handler(mapping map, int flag) {
    object ob, namhas;
    string str;
    string err;

    ob = this_interactive() || this_player();
    namhas = find_player("namhas");

    if (flag) str = "*Error caught\n";
    else str = "";

    err = map["error"];
    err = replace_string (err, "\n", " ");

    if (ob != namhas)
      {
               tell_object (namhas,
                  sprintf ("--\n** %s\n## %O %s %s:%d\n",
                    err[1..],
                    (map["object"] || "<no object>"),
                    (map["program"] || "<no program>"),
                    map["file"], map["line"]));
      }
        
    write_file("/log/runtime",
      sprintf ("--\n** %s\n## %O %s %s:%d\n",
	err[1..],
	(map["object"] || "<no object>"),
	(map["program"] || "<no program>"),
	map["file"], map["line"]));

    if (!ob || !ENV(ob))
      return;

    if (!flag && ob) {
	if (ob->query_security() < 1)
	{
	    tell_object (ob, "You have found a bug. Please report it.\n");
            for (int i=0;i<sizeof(users());i++)
              {
                if (users()[i]->query_security())
              tell_object (users()[i], ob->query_cap_name()+" has bumped into a bug ("+(map["program"]+":"+map["line"])+").\n");
              }
	}
	else
	{
		tell_object (ob, 
		  sprintf ("--\n** %s\n## %O %s %s:%d\n",
		    err[1..],
		    (map["object"] || "<no object>"),
		    (map["program"] || "<no program>"),
		    map["file"], map["line"]));
	}
    }
}

string
get_root_uid () {
   return "root";
}

string
get_bb_uid () {
   return "backbone";
}
