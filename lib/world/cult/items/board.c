// FILE NAME   : /world/board
// DESCRIPTION : Bulletin Board Object
// CODER       : Tommi "Namhas" Leino, shaman@neutech.fi / Majik!

inherit BASE;

#define SAVEFILE "/data/board/cult_board"

string     messages;
string     new_header;
string     new_body;

int        num_messages;

static int line_number;

object     who;

create ()
{
  restore_object (SAVEFILE);
  set_name ("board");
  set_short ("a bulletin board");
  set_long ("If you see this the board is not working.\n");
}

init ()
{
  add_action ("do_note", "note");
  add_action ("do_read", "read");
  add_action ("do_remove", "remove");
}

long ()
{
  message ("itemlong",
    "You can set up new notes with the command 'note <topic>'. Read a note with\n"+
    "'read <number>', and remove an old note wiwth 'remove <number>'.\n",
  this_player ());

  if (num_messages == 0)
    {
      set_short ("A bulletin board (empty)");
      write ("It is empty.\n");
      return;
    }

  write ("The bulletin board contains " + num_messages);

  if (num_messages == 1)
    {
      set_short ("A bulletin board (1 message)");
      write (" note:\n\n");
    }
  else
    {
      set_short ("A bulletin board ("+num_messages+" messages)");
      write (" notes:\n\n");
    }

  headers();
}

get ()
{
  write ("It is secured to the ground.\n");
  return 0;
}

headers ()
{
  string header, body, rest;
  int i, tmp;

  i = 1;

  rest = messages;

  while (rest != 0 && rest != "")
    {
      tmp = sscanf (rest, "%s:\n**\n%s\n**\n%s", header, body, rest);
      if (tmp != 2 && tmp != 3)
        {
          write ("The board file is corrupted!\nPlease use 'bug' command and explain what happened!\n");
          write_file ("/log/board", ctime (time ()) + " :: " + file_name (this_object ()) +
            " board file corrupted!\n");
          return;
        }
      write (i + ":\t" + header + "\n");
      i += 1;
    }
}

do_note (string header)
{
  if (!header)
    {
      notify_fail ("usage: note <topic>\n");
      return 0;
    }

  if (who && environment (who) == environment (this_object ()))
    {
      write (capitalize(who->query_name()) + " is busy writing.\n");
      return 1;
    }

  if (strlen (header) > 50)
    {
      write ("Too long topic to fit on the paper.\n");
      return 1;
    }

  new_header = header;

  input_to ("get_body");

  message ("misc",
    "Write a message, and write \"^c1.^c0\" or \"^c1**^c0\" when done.\n",
  this_player());

  line_number = 1;

  write (line_number + "> ");

  new_body = "";

  return 1;
}

get_body (string str)
{
  if (str == "**" || str == ".")
    {
      say (capitalize (THIS->query_name()) +
        " writes a note titled \"" + new_header + "\".\n");
      new_header = new_header + "(" + THIS->query_name() +
        ", " + extract (ctime (time ()), 4, 9) + ")";
      messages = messages + new_header + ":\n**\n" + new_body + "\n**\n";
      num_messages += 1;
      new_body      = 0;
      new_header    = 0;
      line_number   = 0;
      save_object (SAVEFILE);
      write ("Done.\n");
      who = 0;
      return;
    }

  new_body = new_body + str + "\n";
  line_number++;

  write (line_number + "> ");
  input_to ("get_body");
}

do_read (string str)
{
  string header, body, rest;
  int i, tmp;

  if (!str || (sscanf (str, "%d", i) != 1 &&
               sscanf (str, "note %d", i) != 1))
    return 0;

  if (i < 1 || i > num_messages+1)
    {
      write ("There is no such message numbered (num_messages: "+num_messages+") "+i+".\n");
      return 1;
    }

  rest = messages;

  while (rest != 0 && rest != "")
    {
      i -= 1;
      tmp = sscanf (rest, "%s:\n**\n%s\n**\n%s", header, body, rest);
      if (tmp != 2 && tmp != 3)
        {
          write ("The board file is corrupted!\nPlease use 'bug' command and explain what happened!\n");
          write_file ("/log/board", ctime (time ()) + " :: " + file_name (this_object ()) +
            " board file corrupted!\n");
          return;
        }

      if (!i)
        {
          say (capitalize (THIS->query_name()) +
            " reads a note titled \"" + header + "\".\n");
          write ("The note is titled \"" + header + "\":\n\n");
          write (body);
          return 1;
        }
    }
}

do_remove ()
{
  write ("Sorry this command is not yet implemented.\n");
  return 1;
}

extract (string poks, int meep)
{
    int i;

    for(i=0;i<strlen(poks);i++)
    {
        if (i == meep)
        {
            return poks[meep..strlen(poks)];
        }
    }
    return " ";
}
