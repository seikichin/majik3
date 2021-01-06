void
syslog (string ident, string str)
{
  object o, *all;

  all = users();

  foreach (o in all)
    {
      if (o->query_security())
        message ("syslog", "^cc[^c0 "+ctime(time())[4..15]+" "+ident+": "+str+" ^cc]^c0\n", o);
    }
}

is_file (string str)
{
  if (file_size(str) > -1)
    return 1;
  else
    return 0;
}

is_directory (string str)
{
  if (file_size(str) == -2)
    return 1;
  else
    return 0;
}

tell_area (object ob, string str, object *exclude)
{
  object o, all, env;

  all = users();
  env = ENV(ob);

  if (env)
    {
      foreach (o in all)
        {
          if(!ENV(o))
            continue;
          if (ENV(o)->query_area() == env->query_area())
            {
              if (arrayp(exclude))
                {
                  if (member_array(o, exclude) > -1)
                    continue;
                }
              message ("3", str, o);
            }
        }
    }
}

mixed
query_variable (string who, string what)
{
  string poks, *dat;
  string var;
  string con;

  if (who)
    poks = "/data/player/"+who[0..0]+"/"+who+".o";
  else
    poks = "";

  if (file_size (poks) < 1) {
    return 0;
  }

  dat = explode(read_file(poks), "\n");

  for (int i=0;i<sizeof(dat);i++)
    {
      if (sscanf (dat[i], "%s %s", var, con) == 2)
        {
          if (var == what)
            {
              if (con[0] == '\"') {
                con = con[1..strlen(con)-2];
              }
              return (mixed) con;
            }
        }
    }
}

int
wizardp (string who)
{
  if (to_int(query_variable(who, "security")))
    return 1;
  else
    return 0;
}

int
adminp (string who)
{
  if(to_int(query_variable(who, "security")) > 50)
    return 1;
  else
    return 0;
}

void
cat (string file)
{
    write(read_file (file));
}

int exec( object to, object from )
{
    if (!wizardp(THIS->query_name()))
	return 0;
    else
	efun::exec(to, from);

    return 1;
}

varargs nomask mixed snoop (mixed snoopee)
{
    object result, ob;

    if (previous_object()) {
      if (file_name(previous_object()) != "/command/immortal/snoop")
        return 0;
    }

    if (snoopee)
    {
	if (efun::query_snoop(snoopee))
	{
	    ob = query_snoop (snoopee);
	    write ("Busy. Snooped by: "+capitalize(ob->query_name())+"\n");
	    return 0;
	}
	result = efun::snoop (this_player(), snoopee);
    }
    else
    {
	if (!efun::query_snooping (this_player()))
	{
	    write ("Not snooping.\n");
	    return 0;
	}

	result = efun::snoop (this_player());
    }

    if (!result)
	write ("Failed.\n");
    else
	write ("Ok.\n");

    return result;
}

/* new tail by namhas */

int tail(string fname)
{
    string buf;
    int lines;

    if (file_size (fname) < 1)
	return 0;

    buf = "";

    lines = file_length (fname);

    buf = read_file (fname, lines-15, 16);

    if (buf)
	message("0", buf, THIS);

    return 1;
}

string wrap(string str, int width, int indent)
{
  string buf = "", *s;
  int columns;
 
  if (THIS)
    columns = THIS->query_columns();

  if (!columns)
    columns = 78;

  columns -= 2;

    if ( !indent )
        return sprintf("%-=*s", width || columns, str);

    if (indent)
      {
        str = sprintf("%-=*s", width || columns, str);

        s = explode(str, "\n");

        for (int i=0;i<sizeof(s);i++)
          buf += repeat_string (" ", indent) + s[i] + "\n";

        return buf;
      }        
       
    return sprintf(
        "%s%-=*s",
        str[0..indent - 1],
        (width || 2) - indent,
        str[indent..]
        );
}

varargs int
getoid (object ob)
{
    int id;

    if (!ob)
	ob = previous_object ();

    sscanf (file_name (ob), "%*s#%d", id);

    return id;
}

string
user_cwd (string name)
{
    return "/home/" + name;
}

string user_path (string name)
{
    return (user_cwd (name) + "/");
}

string
file_owner (string file)
{
    string name, rest;

    if (file[0] != '/')
	file = "/" + file;

    if (sscanf (file, "/home/%s/%s", name, rest) == 2)
	return name;

    return 0;
}

/* from dgd, da better! */

string resolve_path (string path) {

    int i,j ;
    string *dirs ;

    if (!path) return "" ;
    dirs = explode(path,"/") ;
    /* First, remove any . from the array. */
    dirs -= ({ "." }) ;
    /* Next, replace all occurences of ~ with the directory of this_user().
    It may sometimes be that this_user() is not right but we'll cross
    this bridge when we come to it.
    Also replace ~foo with the directory of foo.
    */
    for (i=0;i<sizeof(dirs);i++) {
	if (!dirs[i] || dirs[i]=="") continue ;
	if (dirs[i][0]=='~') {
	    if (strlen(dirs[i])==1) {
		dirs[i] = "/home/"+this_player()->query_name() ;
	    } else {
		dirs[i] = "/home/"+dirs[i][1..] ;
	    }
	}
    }
    /* Now remove any .. and the preceding element. */
    i = member_array("..",dirs) ;
    while (i>-1) {
	/* Can't start with a ..  */
	if (i==0) return "" ;
	j = sizeof(dirs) ;
	/* Piece it back together, depending on if we remove the first two
	elements, the last two, or two from the middle. */
	if (i==1) {
	    if (j==2) return "" ;
	    dirs = dirs[i+1 .. j-1] ;
	} else {
	    if (i==j-1) {
		dirs = dirs[0 .. i-2] ;
	    } else {
		dirs = dirs[0 .. i-2] + dirs[i+1 .. j-1] ;
	    }
	}
	/* Look for another .. in the path. */
	i = member_array("..",dirs) ;
    }
    path = implode(dirs,"/") ;
    return path ;
}

int absolute_path (string str) {
    if (!str || str=="") return 0 ;
    if (str[0]=='/' || str[0]=='~') return 1 ;
    return 0 ;
}

string
domain_file (string file)
{
    string poks;
    object ob;

    if (sscanf (file, "/world/%s/", poks) == 1) {
      ob = find_object(file);
      if (ob && ob != THOB)        
        return find_object(file)->query_area();
      else
        return "NONAME";
    }
    else if (sscanf (file, "/home/%s/", poks) == 1) {
      ob = find_object (file);
      if (ob && ob != THOB) {
        if (ob->query_area() && ob->query_area() != "developmental")
        return "dev-" + ob->query_area();
      }
      else
        return "developmental";
    }
    else
      return "NONAME";
}

author_file (string file)
{
    string poks;
    object ob;

    if (file[0] != '/')
      file = "/" + file;

    if (sscanf (file, "/home/%s/", poks) == 1) {
      return poks;
    }
    else if (file != "/secure/simul_efun" && file != "/secure/master")
      {
        ob = find_object(file);
        if(ob && ob != THOB)
          {
            poks = ob->query_author();
            if (poks)
              return poks;
            else
              return "NONAME";
          }
      }
    else
      return "namhas";
}

creator_file (string file)
{
    string poks;

    if (sscanf (file, "/home/%s/", poks) == 1)
	return poks;
    else
	return "NONAME";
}



/***    New present() function by Dazzt         ----    see man page
***/

varargs object present(mixed str, mixed ob)
{
    int i;
    int cobj, numobj;
    string objname;
    object *inv;

	if (!str || str == "")
		return 0;
	
	if (stringp(ob))
		ob = find_object(ob);
	
    if (ob)
		inv = all_inventory(ob);
    else
		inv = all_inventory(THIS);

    if (objectp(str))
    {
	if (member_array(str, inv) > 0)
	    return str;
	else
	{
	    if (!ob)
	    {
		if (member_array(str, all_inventory(environment(THIS))))
		    return str;
	    }
	}
	return 0;
    }

    if (sscanf(str, "%s %d", objname, numobj) != 2)
    {
	objname = str;
	numobj = 1;
    }

    cobj = 1;

    for (i = 0; i < sizeof(inv); i++)
    {
	if (inv[i]->id(objname))
	{
	    if (numobj == cobj)
		return inv[i];
	    else
		cobj++;
	}
    }
    if (!ob)
    {
        if (THIS && ENV(THIS)) {
	  inv = all_inventory(environment(THIS));
	for (i = 0; i < sizeof(inv); i++)
	{
	    if (inv[i]->id(objname))
	    {
		if (numobj == cobj)
		    return inv[i];
		else
		    cobj++;
	    }
	}
       }
    }

    return 0;
}


/*  article() - returns arguments with article -- dazzt */

string article(string str)
{
        string first;
   
        first = str[0..0];
        if (lower_case(first) != first)
        	return str;
                                        
        if (member_array(first, ({ "a", "e", "i", "o", "u" })) != -1)
                str = "an " + str;
        else
                str = "a " + str;
	return str;
}

string
unarticle (string str)
{
  string tmp;

  if (!stringp(str))
    error ("Bad argument 1 to unarticle().\n");  

  if (sscanf(str, "the %s", tmp))
    return tmp;
  else if (sscanf(str, "a %s", tmp))
    return tmp;
  else if (sscanf(str, "an %s", tmp))
    return tmp;
  else
    return str;
}

/* some functions to fix compatibility problems */

void write(mixed str)
{
	string s;
	
	if (str)
		s = "0";
	
	if (intp(str))
		sscanf(str, "%d", s);
	else
		s = str;

        if (THIS)	
	  message("write", s, THIS);
}

void tell_object(object ob, string str)
{
  if (ob)
    message("tell_object", str, ob);
}

varargs void tell_room(mixed ob, string str, object *exclude)
{
	if (stringp(ob))
		ob = find_object(ob);

	message("tell_room", str, ob, exclude);
}

varargs void say(string str, mixed ob)
{
	object orig;
	object *ob2;
	
	orig = THIS;
	if (!orig)
		orig = previous_object();
	
	if (!arrayp(ob))
		ob2 = ({ ob, orig });
	else
		ob2 = ob + ({ orig });
	
	if (ENV(orig))
		message("say", str, ENV(orig), ob);
	if (orig)
		message("say", str, orig, ob2);
}

void shout(string str)
{
  if (THIS)
    message("shout", str, users(), THIS);
  else
    message("shout", str, users());
}
mixed base_name(mixed what)
{
  string base;
  int tmp, uid;
  if (objectp(what))
    tmp=sscanf(file_name(what),"%s#%d",base,uid);
  else if (stringp(what))
    tmp=sscanf(what,"%s#%d",base,uid);
  else
    tmp=what;

  if (tmp==2)
    return base;
  else if (stringp(what))
    return what;
  else if (objectp(what))
    return file_name(what);
  else
    return what;
}

/* true_path(string path[, string wd]) - almost the same as resolve path
    only takes different parameters and is a bit different also in action,
    should be used instead of resolve_path().

    Author: Alcal, 11. Jan, 1998
*/

varargs
string true_path(string path, string wd) {
  string temp1, temp2;
  string *arr;
  int i;
  object ob;
  object *obs;

  if (!wd) wd = this_player()->query_cwd();

  if (path == "here") path = file_name(ENV(THIS)) + ".c";
  else if (path == "me") path = file_name(this_player());
  else if (sscanf(path, "this:%s", temp1) == 1)
  {
    ob = present(temp1, this_player());
    if (!ob) {
      printf("You don't have any '%s'.\n", temp1);
      path = wd + "/" + temp1;
    }
    else {
      sscanf(file_name(ob), "%s#%*s", temp1);
      path = temp1 + ".c";
    }
  }
  else if (sscanf(path, "here:%d", i) == 1)
  {
    obs = all_inventory(ENV(THIS));
    if (i >= sizeof(obs)) {
      printf("There isn't that many objects here.\n");
      path = wd + "/" + path;
    }
    else {
      sscanf(file_name(obs[i]), "%s#%*s", temp1);
      path = temp1 + ".c";
    }
  }
  else if (sscanf(path, "here:%s", temp1) == 1)
  {
    ob = present(temp1, environment(this_player()));
    if (!ob) {
      printf("There is no '%s' here.\n", temp1);
      path = wd + "/" + temp1;
    }
    else {
      sscanf(file_name(ob), "%s#%*s", temp1);
      path = temp1 + ".c";
    }
  }
  else if (path[0] == '~') {
    if (!sscanf(path, "~%s/%s", temp1, temp2)) {
      temp1 = path[1..<1];
      temp2 = "";
    }
    if (temp1 == "") temp1 = THIS->query_true_name();
    path = sprintf("/home/%s/%s", temp1, temp2);
  }
  else if (path[0] == '^') {
    if (!sscanf(path, "~%s/%s", temp1, temp2)) {
      temp1 = path[1..<1];
      temp2 = "";
    }
    path = sprintf("/world/%s/%s", temp1, temp2);
  }
  else if (sscanf(path, "me:%d", i))
  {
    obs = all_inventory(THIS);
    if (i >= sizeof(obs)) {
      printf("You don't have that many items.\n");
      path = wd + "/" + path;
    }
    else {
      sscanf(file_name(obs[i]), "%s#%*s", temp1);
      path = temp1 + ".c";
    }
  }
  else if (path[0] != '/') path = wd + "/" + path;

  arr = explode(path, "/");
  arr -= ({ "", "." });

  for(i = 0; i < sizeof(arr); i++) {
    if (arr[i] == "..") arr = arr[0..i-2] + arr[i+1..<1];
  }

  path = "/" + implode(arr, "/");

  if (path == "/") return "";
  else return path;
}

string implode(string *arr, string delim, string last) {
  if (sizeof(arr) == 1) return arr[0];
  if (!last) return efun::implode(arr, delim);
  return efun::implode(arr[0..<2], delim) + last + arr[<1];
}

string extract_path(string file) {
  string *arr;

  arr = explode(file, "/");
  if (sizeof(arr) == 1) return "";
  else return "/" + efun::implode(arr[0..<2], "/");
}

void
act (object me, string str, object ob, object e)
{
  /* $n name of me
     $v name of victim */

  object *all, o;
  string msg = "";

  if (str && ENV(me))
    {
      all = all_inventory (ENV(me));

      foreach (o in all)
        {
          if (!living(o) || o->query_npc())
            continue;

          msg = "";

          msg = replace_string(str, "$n", me->query_cap_name(o));

          if (ob)
            msg = replace_string(msg, "$v", ob->query_cap_name(o));

          if (o != me && o != e)
            message ("act", capitalize(msg) + "\n", o);
        }
    }

  return;
}
/*
 * $n - me's name, stranger name, or "someone", for ch, depending on
 *      whether ch is a PC, a NPC, or an invisible PC/NPC.
 *
 * $N - same as $n but for target.
 * $m - "him", "her", or "it", depending on the gender of me.
 * $M - "him", "her", or "it", depending on the gender of target.
 * $s - "his", "her", or "its", depending on the gender of me.
 * $S - "his", "her", or "its", depending on the gender of target.
 * $e - "he", "she", or "it", depending on the gender of me.
 * $E - "he", "she", or "it", depending on the gender of target.
 *
 * Example: emote ("$n {grin} at $mself and {point} at $N.",
 *           THIS, monster, ENV(THIS));
 *
 * Result to THIS: You grin at yourself and point at monster.
 * Result to monster: THIS grins at himself and points at you.
 * Result to ENV(THIS): THIS grins at himself and points at monster.
 */

string
emote (string str, object me, object target, mixed where, mixed exclude)
{
  string buf = "", str1 = "", str2 = "", str3 = "";

  if (where && !arrayp(where) && where->is_room() && all_inventory(where))
    where = all_inventory(where);

  if (where && !arrayp(where))
    where = ({ where });

  if (objectp(where))
    where = ({ where });

  if (str[<1] != '\n')
    str += "\n";

  if (arrayp (where))
    {
      for (int i=0;i<sizeof(where);i++)
        {
          if (!living(where[i]) || where[i]->query_npc())
             continue;
 
          if (exclude)
            {
              if (arrayp (exclude))
                {
                  if (member_array (where[i], exclude) > -1)
                    continue;
                }

              if (objectp (exclude))
                {
                  if (where[i] == exclude)
                    continue;
                }
            }

          if (where[i] == me)
            {
              buf = replace_string (str, "$n", "you");
              buf = replace_string (buf, "$m", "your");
              buf = replace_string (buf, "$s", "your");
              buf = replace_string (buf, "$e", "you");

              if (target)
                {
                  buf = replace_string (buf, "$N", target->query_cap_name(me));
                  buf = replace_string (buf, "$M", target->query_objective());
                  buf = replace_string (buf, "$S", target->query_possessive());
                  buf = replace_string (buf, "$E", target->query_pronoun());
                }

              buf = replace_string (buf, "{", "");
              buf = replace_string (buf, "}", "");

              message ("emote", capitalize(buf), me);
            }
          else if (where[i] == target)
            {
              buf = replace_string (str, "$N", "you");
              buf = replace_string (buf, "$M", "your");
              buf = replace_string (buf, "$S", "your");
              buf = replace_string (buf, "$E", "you");

              if (me)
                {
                  buf = replace_string (buf, "$n", me->query_cap_name(target));
                  buf = replace_string (buf, "$m", me->query_objective());
                  buf = replace_string (buf, "$s", me->query_possessive());
                  buf = replace_string (buf, "$e", me->query_pronoun());
                }

              while (sscanf(buf, "%s{%s}%s", str1, str2, str3) == 3) {
                if (str2 == "hum")
                  buf = str1 + "hums" + str3;
                else
                  buf = str1 + pluralize(str2) + str3;
              }

              message ("emote", capitalize(buf), target);
            }
          else
            {
              if (me)
                {
                  buf = replace_string (str, "$n", 
                    me->query_cap_name(where[i]));

                  buf = replace_string (buf, "$m", me->query_objective());
                  buf = replace_string (buf, "$s", me->query_possessive());
                  buf = replace_string (buf, "$e", me->query_pronoun());
                }

              if (target)
                {
                  buf = replace_string (buf, "$N",
                    target->query_cap_name(where[i]));

                  buf = replace_string (buf, "$M", target->query_objective());
                  buf = replace_string (buf, "$S", target->query_possessive());
                  buf = replace_string (buf, "$E", target->query_pronoun());
                }

              while (sscanf(buf, "%s{%s}%s", str1, str2, str3) == 3) {
                if (str2 == "hum")
                  buf = str1 + "hums" + str3;
                else
                  buf = str1 + pluralize(str2) + str3;
              }

              message ("emote", capitalize(buf), where[i]);
            }
        }
    }

  return capitalize(buf);
}
