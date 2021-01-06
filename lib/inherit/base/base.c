#pragma strict_types

/*  NAME        : /inherit/base.c                                          */
/*  DESCRIPTION : base object for all objects                              */
/*  CODER       : namhas                                                   */

/* --- saveable variables                                                  */

string name;                         /* name of an object                  */
string *aliases;                     /* alias names of object              */

static int no_clean_up;              /* flag to prevent clean up           */
static int no_autoload;              /* flag to prevent autoload           */

/* --- not-saved variables                                                 */

static string long_desc;             /* long description                   */
static string short_desc;            /* short description                  */
static string info;                  /* special info when identifying      */

static int invis;                    /* for spell invisibility             */
static int sneak;                    /* for skill sneak                    */
static int hide;                     /* for skill hide                     */

/* --- function prototypes                                                 */

string     query_name ();
string *   query_aliases ();
string     query_short ();
string     query_long ();
string     query_info ();
string     short ();
string     long ();
string     stat_me ();

int        set_no_clean_up(int);
int        query_no_clean_up();

void       remove ();
void       move (mixed);

mixed      query (string);
mixed      set (string, string);

int        id (string);

void
remove ()
{
    if (interactive(THOB))
      THOB->force_us("quit");

    if (short_desc && ENV(THOB))
        tell_room (ENV(THOB), capitalize(short_desc) + " turns into a pile of dust.\n");

    destruct (THOB);
}

string
query_name ()
{
  if (invis)
    return "someone";
  else if (!name)
    return "something";
  else
    return name;
}

string
query_cap_name ()
{
  if (invis)
    return "Someone";
  else if (!name)
    return "Something";
  else 
    return capitalize(name);
}


string
query_maybe_cap_name ()
{
  if (invis)
    return "someone";
  else if (!name)
    return "something";
  else if (short()[0] > 64 && short()[0] < 91)
    		return capitalize(name);
  else return name;
}


string
query_true_name ()
{
  return name;
}

string *
query_aliases()
{
    return aliases;
}

string
query_short ()
{
    return short_desc;
}

string
query_long ()
{
    return long_desc;
}

string
query_info ()
{
    return info;
}

mixed
query (string str)
{
    return (mixed) fetch_variable (str);
}

mixed
set (string str, string arg)
{
    if (str == "security")
        return 0;

    return (mixed) store_variable(str, arg);
}

string
set_name (mixed s)
{
    if (arrayp(s))
    {
        name = s[0];
        s -= ({ s[0] });
        aliases = s;
        return name;
    }
    else {
        return name = s;
    }
}

string
set_short (string s)
{
    return short_desc = s;
}

string
set_long (string s)
{
    return long_desc = s;
}

string
set_info (string s)
{
    return info = s;
}

int
id (string str)
{
    if ((name && str == lower_case(name)) ||
      (name && str == name))
        return 1;

    if (aliases)
        if (name && (member_array(str, aliases) != -1))
            return 1;
    return 0;
}

string
short ()
{
    if (!short_desc && !name)
        return "<invisible>";
    else if (!short_desc)
        return capitalize(name) + " <invisible>";
    else
        return short_desc;
}

string
long ()
{
    if (!long_desc)
        if (!short_desc)
            return "You don't see anything special.";
        else
            return short ();
    else
        return long_desc;
}

int
set_no_clean_up(int i)
{
        return no_clean_up = i;
}

int 
query_no_clean_up()
{
		return no_clean_up;
}

int
set_no_autoload(int i)
{
        return no_autoload = i;
}

int
query_no_autoload()
{
        return no_autoload;
}

int
clean_up(int i)
{
	if (no_clean_up)
		return 0;

	if (ENV(THOB))
	{
			return 1;
	}
        
	if (!interactive(THOB))
		destruct(THOB);
	return 1;
}


string
stat_me ()
{
    int mem = memory_info(THOB);

    return
    "BASE OBJECT\n"
    + "  name         : "+(name ? name : "-")+" "+(aliases ? "("+implode(aliases, ", ")+")" : "")+"\n"
    + "  short_desc   : "+(short_desc ? short_desc : "-")+"\n"
    + "  long_desc    : "+(long_desc ? "" + strlen(long_desc) : "-")+"\n"
    + "  memory usage : "+(mem/1024)+" kB ("+sprintf("%2.2f", (mem*100.0/memory_info()))+")\n"
    + "  file name    : "+file_name(THOB)+"\n"
    + "  environment  : "+(environment() ? file_name(environment()) : "-")+"\n";
}

void
move (mixed dest)
{
    if (!dest)
        dest = previous_object ();

    if (environment())
      environment()->check_light();

    move_object (dest);
}

int
save_me (string file)
{
  return save_object (file);
}

int
restore_me (string file)
{
  return restore_object (file);
}

mapping
save_map ()
{
  mixed *all;
  mapping m = ([ ]);

  all = variables (THOB, 1);

  for (int i=0;i<sizeof(all);i++)
    {
       // lagloop (tm)

      if (strsrch(all[i][1], "static") > -1)
        continue;

      m[all[i][0]] = save_variable (fetch_variable(all[i][0]));
    }

  return m;
}

int
restore_map (mapping m)
{
  string *k, *v = ({ });
  mixed *all;
  int i, j;

  if (m)
    {
      k = keys (m);

      all = variables (THOB, 1);

      for (i=0;i<sizeof(all);i++)
        {
          if (strsrch(all[i][1], "static") > -1)
            continue;
          else
            {
              if (!v)
                 v = ({ all[i][0] });
              else
                 v += ({ all[i][0] }); 
            }
        }

      for (i=0;i<sizeof(k);i++)
        {
          if (member_array(k[i], v) > -1)
            store_variable (k[i], restore_variable (m[k[i]]));
        }
    }

  return i;
}

int query_hide() { return hide; }
int query_sneak() { return sneak; }
int query_invis() { return invis; }

int set_hide(int n) { hide = n; }
int set_sneak(int n) { sneak = n; }
int set_invis(int n) { invis = n; }
