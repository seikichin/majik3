// inheritable board object by namhas

inherit ITEM;

#define pline(x) message("0", x+"\n", THIS)
#define room(x) message("0", x+"\n", ENV(THIS), THIS)

mapping msg;
static string savefile;

do_sort (mixed a, mixed b)
{
  if(a > b)
    return 1;
  else if(a == b)
    return 0;
  else
    return -1;
}

string
set_savefile (string str)
{
  return savefile = str;
}

create_item ()
{
  THOB->create_board();

  if (!savefile) {
      savefile = file_name(THOB);
      sscanf (savefile, "%s#%*s", savefile);
  }

  restore_object (savefile);
}

init ()
{
  THOB->init_board();

  add_action ("do_write", "write");
  add_action ("do_read", "read");
  add_action ("do_remove", "remove");
}

do_remove (string str)
{
  string s1, s2, *k;
  int i;

  if (!str || present(explode(str, " ")[0]) != THOB)
    {
      notify_fail ("Remove what?\n");
      return 0;
    }

  if (sscanf(str, "%s %s", s1, s2) != 2)
    {
      pline ("Usage: remove board <number>");
      return 1;
    }

  if (!msg)
    msg = ([ ]);

  k = keys(msg);
  k = sort_array(k, "do_sort");

  i = to_int(s2);
  i--;

  if (i<0 || i>(sizeof(k)-1))
    {
      pline ("No such message.");
      return 1;
    }
  else if (msg[k[i]][0] != THIS->query_name() && THIS->query_security() < 51)
    {
      pline ("You can't remove that message.");
      return 1;
    }
  else
    {
      map_delete (msg, k[i]);
      pline ("Message number "+(i+1)+" removed.");
      room (THIS->query_cap_name()+" removes message number "+(i+1)+" from the board.");
      save_object (savefile);
    }

  return 1;
}

do_read (string str)
{
  string s1, s2, *k, buf = "";
  int i;

  if (!str || present(explode(str, " ")[0]) != THOB)
    {
      notify_fail ("Read what?\n");
      return 0;
    }

  if (sscanf(str, "%s %s", s1, s2) != 2)
    {
      pline ("Usage: read board <number>");
      return 1;
    }

  if (!msg)
    msg = ([ ]);

  k = keys(msg);
  k = sort_array(k, "do_sort");

  i = to_int(s2);
  i--;

  if (i<0 || i>(sizeof(k)-1))
    {
      pline ("No such message.");
      return 1;
    }
  else
    {
      buf += "Date: "+ctime(k[i])+"\n";
      buf += "From: "+msg[k[i]][0]+"\n";
      buf += "Subject: ^c1"+msg[k[i]][1]+"^c0\n\n";
      buf += wrap(msg[k[i]][2]);

      pline (buf);
      room(THIS->query_cap_name()+" reads message number "+(i+1)+" from the board.");
    }

  return 1;
}

do_write (string str)
{
  string s1, s2, s3, *k;
  int t;

  if (!str || present(explode(str, " ")[0]) != THOB)
    {
      notify_fail ("Write on what?\n");
      return 0;
    }

  if (sscanf(str, "%s (%s) %s", s1, s2, s3) != 3)
    {
      pline ("Usage   : write board (<subject>) <message>");
      pline ("Example : write board (test message) this is a test");
      return 1;
    }
 
  if (!msg)
    msg = ([ ]);

  k = keys(msg);
  k = sort_array(k, "do_sort");

  if (sizeof(k) > 15)
    map_delete (msg, k[0]);

  t = time();

  msg[t] = ({ THIS->query_name(), s2, wrap(s3) });

  pline ("Your message is now on the board.");
  room(THIS->query_cap_name()+" writes a new message on the board.");
  save_object (savefile);

  return 1;
}

short ()
{
  string *k;
  int sz;

  if (!msg)
    msg = ([ ]);

  k = keys(msg);
  sz = sizeof(k);

  if (!sz)
    return ::short() + " (empty)";
  else if (sz == 1)
    return ::short() + " (one message)";
  else
    return ::short() + " ("+sz+" messages)";
}

long ()
{
  string buf = "", *k;
  int sz;

  buf += ::long();

  if (!msg)
    msg = ([ ]);

  k = keys(msg);
  sz = sizeof(k);

  if (k)
    k = sort_array(k, "do_sort");

  if (!sz)
    buf += "The board is empty.\n";
  else if (sz == 1)
    buf += "There is only one message on the board:\n";
  else
    buf += "There are "+sz+" messages on the board:\n";

  for (int i=0;i<sz;i++)
    {
      buf += sprintf ("^c0^cc%2d^c0. %-16s (%-11s) :: ^c1%s^c0\n", i+1,
        msg[k[i]][0][0..15], ctime(k[i])[4..15], msg[k[i]][1]);
    }

  return buf;
}
