/*
 * /secure/receive.c
 * 
 * Contains the receive_message function to support different terminals
 * 
 * Coders:     Namhas, Dazzt
 * 
 * */

inherit "/inherit/living/translate";

int term;
int client;

static int www;

int
set_www (int i)
{
  return www = i;
}

void
receive_message (string cla, string str)
{
  mapping term_info;
  string *term_keys;
  int i, j;

  if (!str)
    return;

	str = translate(str);
	
  if (term == 1)
    term_info = (mapping) TERMINAL_D->query_term_info ("vt100");
  else if (term == 2)
    term_info = (mapping) TERMINAL_D->query_term_info ("ansi");
  else if (term == 3)
    term_info = (mapping) TERMINAL_D->query_term_info ("html");
  else if (term == 4)
    term_info = (mapping) TERMINAL_D->query_term_info ("xterm");
  else if (term == 5)
    {
      receive (str);
      return;
    }
  else
    term_info = (mapping) TERMINAL_D->query_term_info ("unknown");

  if (www)
    term_info = (mapping) TERMINAL_D->query_term_info ("html");

  if (client || term == 6) {
    receive ("%" + cla + ":" + strlen(str) + ":" + str);
    return;
  }

  term_keys = keys (term_info);

  j = sizeof (term_keys);

  if (www || term == 3)
    {
  str = replace_string(str, "&", "&amp;");
  str = replace_string(str, "<", "&lt;");
  str = replace_string(str, ">", "&gt;");

  for (int l=0;l<j;l++)
    str = replace_string(str, term_keys[l],
strlen(term_info[term_keys[l]]) > 2 ?
"<font color=\""+term_info[term_keys[l]]+"\">" : "");

  str = replace_string(str, "\n", "<br>");
  }
else
 {
  for (i = 0; i < j; i++)
    str = replace_string (str, term_keys[i], term_info[term_keys[i]]);
}

  if (www)
    "/www/cgi/wuc"->add_buf (THOB->query_true_name(), str);
  else
    receive (str);
}

void
catch_tell (string message)
{
  receive_message ("0", message);
}
