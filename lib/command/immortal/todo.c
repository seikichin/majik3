// DESCRIPTION : todo progie
// CODER       : namhas

#pragma strict_types

/* definations */

#define D_COD		0
#define D_TIT		1
#define D_DAT		2
#define D_WHO		3
#define D_LVL		4
#define D_DSC           5

#define S_TIT           0
#define S_DSC           1
#define S_LVL           2

#define pline(x)	message ("0", x, THIS);
#define room(x)		message ("3", x, ENV(THIS), THIS);

/* global variables */

int            state;
int            id = 1;
mapping        data;
object         who;

static string  title;
static string  desc;
static string  lvl;

/* function prototypes */

int do_list    ();
int do_invoke  ();
int do_read    (int);
int do_assign  (int, string);
int do_remove  (int);

int ask_title  (string);
int ask_desc   (string);
int ask_level  (string);

int
do_sort (mixed a, mixed b)
{
  if(a > b)
    return 1;
  else if(a == b)
    return 0;
  else
    return -1;
}

int
main (string str)
{
  string arg1, arg2, arg3;

  restore_object ("/data/misc/todo");

  if (!data)
    data = ([ ]);

  if (!str)
    arg1 = "list";
  else
    {
      if (sscanf(str, "%s %s %s", arg1, arg2, arg3) != 3)
        if (sscanf(str, "%s %s", arg1, arg2) != 2)
          arg1 = str;
    }

  switch (arg1)
    {
      case "invoke" : do_invoke ();                   break;
      case "read"   : do_read   (to_int(arg2));       break;
      case "list"   : do_list   ();                   break;
      case "assign" : do_assign (to_int(arg2), arg3); break;
      case "remove" : do_remove (to_int(arg2));       break;
      default       : do_list   ();                   break;
    }

  return 1;
}

int
do_remove (int num)
{
  string *k;
  int j;

  if (!num)
    {
      pline ("Usage: todo remove <n>\n");
      return 1;
    }

  k = keys(data);
  j = sizeof(k);

  num = member_array(num, k);

  if (num == -1)
    {
      pline ("No such project.\n");
      return 1;
    }

  if (THIS->query_security() < 81 && data[k[num]][D_WHO] != THIS->query_name())
    {
      pline ("You can only remove projects invoked by YOURSELF.\n");
      return 1;
    }

  pline ("Removed.\n");
  map_delete (data, k[num]);
  save_object ("/data/misc/todo");
  return 1;
}

int
do_assign (int num, string coder)
{
  object o;
  string *k;
  int j;

  if (!num || !coder)
    {
      pline ("Usage: todo assign <n> <who>\n");
      return 1;
    }

  k = keys(data);
  j = sizeof(k);

  num = member_array(num, k);

  if (num == -1)
    {
      pline ("No such project.\n");
      return 1;
    }

  if (THIS->query_security() < 81 && data[k[num]][D_WHO] != THIS->query_name())
    {
      pline ("You can only assign coders to projects invoked by YOURSELF.\n");
      return 1;
    }

  o = find_player(coder);

  if (!o || !o->query_security())
    {
      pline ("No such coder online.\n");
      return 1;
    }

  data[k[num]][D_COD] = coder;

  tell_object (o, "You are now assigned coder of project number "+k[num]+".\n");
  pline ("Done.\n");
  save_object ("/data/misc/todo");
  return 1;
}

int
do_read (int num)
{
  string *k, b;
  int    j;

  if (!num)
    {
      pline ("Usage: todo read <n>\n");
      return 1;
    }  

  k = keys(data);
  j = sizeof(k);

  num = member_array(num, k);

  if (num == -1)
    {
      pline ("No such project.\n");
      return 1;
    }

  b = "";
  
  b += "TITLE           : "+data[k[num]][D_TIT]+"\n";
  b += "ASSIGNED CODER  : "+data[k[num]][D_COD]+"\n";
  b += "INVOKED BY      : "+data[k[num]][D_WHO]+"\n";
  b += "DATE            : "+ctime(data[k[num]][D_DAT])+"\n";
  b += "LEVEL REWARD    : "+data[k[num]][D_LVL]+"\n";
  b += repeat_string ("-", 78) + "\n";
  b += wrap(data[k[num]][D_DSC]) + "\n";
  b += repeat_string ("-", 78) + "\n";

  if (data[k[num]][D_COD] == "-")
    {
      b += wrap("You can begin working on this project, but first please tell"+
        " to "+capitalize(data[k[num]][D_WHO])+" that you want to do this.\n");
    }
  else
    {
      b += wrap("This project is reserved for "+capitalize(data[k[num]][D_COD])+", you can only help him in his project if he wants.\n");
    }

  pline (b);
  return 1;
}

int
do_invoke ()
{
  if (who && who != THIS)
    {
      pline ("Sorry, TODO system is busy.\n");
      return 1;
    }

  if (THIS->query_security() < 51)
    {
      pline ("Sorry, only real gods can invoke new projects.\n");
      return 1;
    }

  if (state == S_TIT)
    {
      who   = THIS;
      title = "";
      lvl   = "";
      desc  = "";

      pline ("Title for the project : ");
      input_to ("ask_title");
      return 1;
    }

  if (state == S_DSC)
    {
      pline ("Long description for the project : ");
      input_to ("ask_desc");
      return 1;
    }

  if (state == S_LVL)
    {
      pline ("How many levels you will award for the project : ");
      input_to ("ask_level");
      return 1;
    }

  return 1;
}

int
ask_title (string s)
{
  if (strlen(s) > 2)
    {
      title = s;
      state = S_DSC;
      do_invoke ();

      return 1;
    }

  do_invoke ();

  return 1;
}

int
ask_desc (string s)
{
  if (strlen(s) > 2)
    {
      desc  = wrap(s) + "\n";
      state = S_LVL;
      do_invoke ();

      return 1;
    }

  do_invoke ();

  return 1;
}

int
ask_level (string s)
{
  if (to_int(s))
    {
      lvl   = s;
      state = S_TIT;
      who   = 0;

      id++;
      data[id] = ({ "-", title, time(), THIS->query_name(), lvl, desc });
      pline ("Done.\n");
      save_object ("/data/misc/todo");
      return 1;
    }

  do_invoke ();

  return 1;
}

int
do_list ()
{
  string b, *k;
  int j;

  k = keys(data);
  j = sizeof(k);
  b = "";

  b += "^c0^bb^cW##. assigned coder   title of the project                       ^c0\n";

  k = sort_array(k, "do_sort");

  for (int i=0;i<j;i++)
    {
      b += sprintf ("^cc%2d^c0. ^c1%-16s^c0 %s\n", k[i], data[k[i]][D_COD],
             data[k[i]][D_TIT]);
    }

  pline (b);

  pline ("\nUsage: todo [read <n> | invoke | remove <n> | assign <n> <coder>]\n");

  return 1;
}
