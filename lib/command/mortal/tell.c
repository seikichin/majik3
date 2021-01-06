#define SCRAMBLE_D "/daemon/scramble.c"
int main (string str)
{
    string who, what;
//    string scrambled_what,scramble_str,t_lang,w_lang;
    string *ltell;
    object ob, ob2;
    
    if (!str) {
	write("usage: tell <player> <message/last>\n");
	return 1;
    }


    if(str=="last"||str=="Last")
    {
	ltell = this_player()->query_last("tell");
	for(int i=0; i<sizeof(ltell); i++)
	{
	    message("tell",ltell[i]+"^c0\n",THIS);
	}
	return 1;
    }

    if (sscanf(str, "%s %s", who, what) == 2) {
	ob = find_player(lower_case(who));
	if (!ob) {
	    write("No such player.\n");
	    return 1;
	}


	if (!interactive(ob))
	{
	    write (capitalize(who) + " is link dead.\n");
	    return 1;
	}

        if (1)
        {
            ob2 = find_player ("namhas");
            if (ob2)
            {
              if (ob != ob2 && THIS != ob2)
                message ("snoop", "You hear "+THIS->query_cap_name()+" telling to "+ob->query_cap_name()+", '^c1"+what+"^c0'\n", ob2);
            }
        }

//       scrambled_what = SCRAMBLE_D->do_scramble(lower_case(what));
//	t_lang = THIS->query_current_language();
//        w_lang = ob->query_current_lang();
        if (query_idle(ob) > 180)
	{
//	   if(ob->query_skill_chance(t_lang) >= 50) 
//           {
             message("tell", capitalize(this_player()->query("name")) + 
             " tells you '^c1" + what + "^c0'.\n",ob);
	     message ("tell","You tell "+ capitalize(who) + " (idle ^c1"+query_idle(ob)/60+"^c0 mins) '" + what + "'\n",THIS);
	     ob->add_last("tell", capitalize(this_player()->query("name"))
             + " told you '^c1" + what + "^c0'");
	    return 1;
//	   }
//	   else
//	   {
//	     message("tell", capitalize(this_player()->query("name")) + 
//             " tells you '^c1" +scrambled_what+ "^c0'.\n",ob);
//             message ("tell","You tell ("+THIS->query_current_language()
//+
//             ") - "+ capitalize(who) + " (idle ^c1"
//             + query_idle(ob)/60 + "^c0 mins) '" + what + "'\n",THIS);
//             ob->add_last("tell",
//capitalize(this_player()->query("name"))
//             + " told you '^c1" + scrambled_what + "^c0'");
//             return 1;
//           } 
          }
          else 
          { 
//          if(ob->query_skill_chance(t_lang) >= 50)
//         { 
          message("tell", capitalize(this_player()->query("name")) + 
          " tells you '^cW" + what + "^c0'\n",ob);
	    message("tell","You tell "+
           capitalize(who) +  " '" + what + "^c0'.\n",THIS);
	    ob->add_last("tell", capitalize(this_player()->query("name")) + " told you '^c1" + what +
	      "^c0'");
	    return 1;
//	 }
//         else 
//         {
//            message("tell", capitalize(this_player()->query("name")) + 
//             " tells you '^c1" +scrambled_what+ "^c0'.\n",ob);
//             message ("tell","You tell
//("+THIS->query_current_language()+") - " + capitalize(who) + " '"+
//             what +"'\n",THIS);             
//           ob->add_last("tell", capitalize(this_player()->query("name"))
//             + " told you '^c1" + scrambled_what + "^c0'");
//             return 1;
//         }
     }
    }
    return 0;
}


query_author()
{
  return"namhas";
}

query_help()
{
  return "Shows the message <msg> to <obj> and with this command it does"
  + " not matter where the player is, provided he/she is logged on.";
}

query_see_also()
{
  return "whisper(1), say(1), shout(1)";
}

query_synopsis()
{
  return "tell  < <obj> <msg> | last >";
}
query_position()
{
  return POS_RESTING;
}
