inherit ITEM;

#define lw(x) sprintf("%-=*s", 70, x)

string message = "";
string from = "you";
string to = "empty";
string filename = "not-saved";
string subject = "<no subject>";

int status; /* 0 = empty, 1 = filled, 2 = stamped and sent, 3 = readed */
int date;
int fucked;

static int line = 1;

create_item ()
{
    set_name ("scroll");
    set_dimensions (20, 20, 1);
    set_material("leather");
}

get ()
{
    return 1;
}

long ()
{
    string long, how;

    if (!date)
	how = "new";
    else if ((time() - date) < 60 * 60)
	how = "rather new";
    else if ((time() - date) < 60 * 60 * 5) 
	how = "few days old";
    else if ((time() - date) < 60 * 60 * 24)
	how = "many days old";
    else if ((time() - date) < 60 * 60 * 48) {
	if (!fucked)
	{
	    if (message)
	    {
		for (int i=0;i<strlen(message);i++)
		{
		    if (!random (30))
		    {
			if (random(100) < 50)
			    message[i] = '.';
			else if (random(100) < 50)
			    message[i] = ',';
			else
			    message[i] = ' ';
		    }
		}
	    }
	    fucked = 1;
	}
	how = "few months old";
    }
    else {
	if (!fucked)
	{
	    if (message)
	    {
		for (int i=0;i<strlen(message);i++)
		{
		    if (!random (10))
		    {
			if (random(100) < 50)
			    message[i] = '.';
			else if (random(100) < 50)
			    message[i] = ',';
			else
			    message[i] = ' ';
		    }
		}
	    }
	    fucked = 1;
	}
	how = "very old and fragile";
    }

    long = "You see a "+how+" scroll made of fine leather. The scroll ";

    if (status == 0)
	long += "is empty. ";
    else if (status == 1)
	long += "contains something readable and is not yet sent. ";
    else if (status == 2)
	long += "is sealed with a stamp. It is from "+capitalize(from)+" and intended to "+capitalize(to)+". ";
    else if (status == 3)
	long += "contains something readable. It is from "+capitalize(from)+" and intended to "+capitalize(to)+". ";
    else if (status == 4)
	long += "is ripped to pieces and therefore is useless. ";
    else
	long += "is a bug. ";

    if (status != 4)
	long += "You can \"read\", \"rip\" and \"label\" the scroll.\n";

    long_desc = lw(long);

    return ::long();
}

short ()
{
    switch (status)
    {
    case 0:
	return "a blank scroll";
    case 1:
    case 3:
        if (subject != "<no subject>")
          return "a scroll of mail \"" + subject + "\"";
        else
          return "a scroll of mail";
    case 2:
	return "a stamped scroll";
    case 4:
	return "some pieces of a scroll";
    default:
	return "a horrible bug";
    }
}

init ()
{
    add_action ("do_read", "read");
    add_action ("do_rip", "rip");
    add_action ("do_write", "write");
    add_action ("do_label", "label");
}

int
do_label (string str)
{
  string *arr;

  if (!str) {
    notify_fail ("Usage: label <what> <label>\n");
    return 0;
  }

  arr = explode(str, " ");

  if (sizeof(arr) != 2)
    {
      notify_fail ("Usage: label <what> <label>\n");
      return 0;
    }

  if (!arr[0] || !arr[1] || present(arr[0]) != THOB)
    {
      notify_fail ("Usage: label <what> <label>\n");
      return 0;
    }

  subject = arr[1];

  return 1;
}

do_write (string str)
{
    object ob;

    if (!str)
      {
        notify_fail ("Write what?\n");
        return 0;
      }

    ob = present(str, THIS);

    if (ob == THOB)
    {
	if (status)
	{
	    notify_fail ("You need blank scroll to write on.\n");
	    return 0;
	}
        tell_room(environment(THIS), capitalize(THIS->query_name()) +
        " begins writing something on a scroll.\n", ({ THIS }));
        date = time();
	write ("Write your message below and hit \".\" alone when ready.\n");
	do_edit ();
	return 1;
    }
    else
    {
	notify_fail ("You don't have such thing or you can't write on it.\n");
	return 0;
    }
}

do_edit ()
{
    write (line + "> ");
    input_to ("do_line");
    return 1;
}

do_line (string str)
{
    if (str != ".")
    {
	message += str + "\n";
	line++;
        status=1;
	do_edit ();
    }
    else {
        tell_room(environment(THIS), capitalize(THIS->query_name()) +
        " writes a scroll of mail.\n", ({ THIS }));
      write ("Done.\n");
    }
}

do_rip (string str)
{
    object ob;

    if (!str)
      {
        notify_fail ("Rip what?\n");
        return 0;
      }

    ob = present(str, THIS);

    if (ob == THOB)
    {
	write ("You rip the scroll to small pieces.\n");
	if (to != THIS->query_name() || from != THIS->query_name())
	{
	    THIS->set_aligny(THIS->query_aligny() - (random (75) + 10));
	    THIS->set_alignx(THIS->query_alignx() - (random (36) + 10));
	}
	status = 4;
	call_out ("do_destruct", 1 + random(5));
	return 1;
    }
    else 
    {
	notify_fail ("You don't have such thing or you can't rip it.\n");
	return 0;
    }
}

do_destruct ()
{
    write ("A soft breeze blows the pieces away.\n");
    tell_room (environment(THIS), "You can see some pieces of a ripped scroll to fly away by the soft wind.\n", ({ THIS }));
    destruct (THOB);
}

do_read (string str)
{
    object ob;

    if (!str)
      {
        notify_fail ("Read what?\n");
        return 0;
      }

    ob = present(str, THIS);

    if (ob == THOB)
    {
        tell_room(environment(THIS), capitalize(THIS->query_name()) +
        " reads "+ob->short()+".\n", ({ THIS }));

	if (!status)
	{
	    write ("The scroll is empty. You can \"write\" something on it.\n");
	    return 1;
	}
	else
	{
	    long (); /* it doesn't display anything */

            write ("The scroll contains following text:\n\n");
            rm ("/open/tmp"+THIS->query_name());
            write_file ("/open/tmp" + THIS->query_name(), message);
            THIS->more_file ("/open/tmp" + THIS->query_name());
            rm ("/open/tmp"+THIS->query_name());

	    if (status == 2)
		status++;
  
            return 1;
	}
    }
    else
    {
	notify_fail ("You don't have such thing or you can't read it.\n");
	return 0;
    }
}

set_status (int i)
{
    status = i;
}

set_to (string s)
{
    to = s;
}

set_from (string s)
{
    from = s;
}

set_date (int i)
{
    date = i;
}

set_message (string s)
{
    message = s;
}

save_scroll ()
{
    int idx;

    while (1)
    {
	if (file_size ("/data/scroll/"+to+"-"+idx+".o") > 1)
	    idx++;
	else
	    break;
    }

    filename = "/data/scroll/" + to + "-" + idx;
    save_object ("/data/scroll/" + to + "-" + idx);
}

restore_scroll (string nimi, int idx)
{
    restore_object ("/data/scroll/" + nimi + "-" + idx);
}

query_status ()
{
  return status;
}

query_to ()
{
  return to;
}

query_from ()
{
  return from;
}

query_filename ()
{
  return filename;
}

int
query_date ()
{
  return date;
}

string
query_message ()
{
  return message;
}

string
query_subject ()
{
  return subject;
}
