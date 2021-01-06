#define PREV previous_object()
#define SCRAMBLE_D "/daemon/language.c"
int
main (string str)
{
    string *buf;
    object who;
    string kuka, msg,scramble_msg,scramble_str,w_lang,t_lang;

    if (!str)
    {
	notify_fail ("usage: whisper <player> <message>, to see last messages type \"say whisper\"\n");
	return 0;
    }

    if (str == "last")
    {
	buf = THIS->query_last("whisper");
	for(int i=0;i<sizeof(buf);i++)
	    message ("last", buf[i] + "\n", THIS);
	return 1;
    }

   t_lang = THIS->query_current_language(); 
   if (sscanf(str, "%s %s", kuka, msg) == 2)
    {
	if (who = find_player(kuka))
	{
	   w_lang = who->query_current_language(); 
           if (environment(who) == environment(PREV))
	    {   
	     	
               if(who->query_skill_chance(t_lang) >= 50)
               {
                 message ("com", capitalize(PREV->query_name()) + 
		  " whispers something to "+capitalize(who->query_name())+".\n", environment(PREV),
		  ({PREV, who }));
		message ("com", "You whisper to "+capitalize(who->query_name())+" in "+t_lang+", '^c1" + msg +"^c0'\n",PREV);
		message ("com", capitalize(PREV->query_name()) + " whispers to you in "+t_lang+", '^c1" + msg +"^c0'\n",who);  

		who->add_last("whisper", capitalize(PREV->query_name()) +
		  " whispered to you '^c1" + str + "^c0'");
	      }
              else
              {
               scramble_str = SCRAMBLE_D->scramble(t_lang, 100, str);
               scramble_msg = SCRAMBLE_D->scramble(t_lang, 100, msg);
               message ("com", capitalize(PREV->query_name()) +
               " whispers something to "+
               capitalize(who->query_name())+".\n",({PREV, who }));
                message ("com", "You whisper to " 
             +capitalize(who->query_name())+" '^c1" + msg +"^c0'\n",PREV); 
          message("com", capitalize(PREV->query_name()) + 
        " whispers to you '^c1" + scramble_msg +"^c0'\n",who);
           who->add_last("whisper", capitalize(PREV->query_name()) +
              " whispered to you '^c1" + scramble_str + "^c0'");

            }
	   } 
           else
		write ("Whisper to who?\n");
	}
	else
	    write ("Could not find that player ("+kuka+").\n");
    }
    else
	write ("usage: whisper <who> <message>\n");

    return 1;
}

query_author()
{
  return"namhas";
}

query_help()
{
  return "By whispering you can communicate with someone in the same room with"
  + " you without others hearing what you are saying. <msg> will be shown to"
  + " object <obj>";
}

query_see_also()
{
  return "tell(1), shout(1), say(1)";
}

query_synopsis()
{
  return "whisper <obj> <msg>";
}

query_example()
{
  return "whisper foo bar";
}
query_position()
{
  return POS_RESTING;
}

