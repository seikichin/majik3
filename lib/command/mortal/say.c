// SAY.C
//
// Parsed to take the language switching as a parameter by Project.
//

#define SCRAMBLE_D "/daemon/scramble.c"
#define LANGUAGE_D "/daemon/language";
int

main (string str)
{
    string *buf, name, adverb,what1,what2,str_scramble,t_lang,w_lang,lang; 
    object *who,PREV, namhas;
    int j;

    namhas = find_player("namhas");
    
    if (previous_object()->query_npc())
      PREV = previous_object();
    else
      PREV = THIS;

    if (!str)
    {
        notify_fail ("usage: say [*<language>] <message>, to see last "
        + "messages type \"say last\"\n");
      return 0;
    }

  if (str == "last")
    {
      buf = PREV->query_last("say");
      for(int i=0;i<sizeof(buf);i++)
        message ("last", buf[i] + "\n", PREV);
      return 1;
    }

    if (namhas)
    {
      if (ENV(PREV) != ENV(namhas) && interactive(PREV))
        {
          message ("snoop", 
            "You hear "+PREV->query_cap_name()+"'s voice from the distance saying, '^c1"+str+"^c0'\n", namhas);
        }
    }
  
    if((str[0..0])=="*")
    {
    sscanf(str,"*%s %s",lang,str);
    if((strlen(lang)) >0)
    {
	"/command/mortal/lang.c"->main(lang);     
    }
    }

    t_lang = THIS->query_current_language();

    if (t_lang == 0 || t_lang == "human")
      t_lang = "common";

  adverb = "";

  if (sscanf (str, ":%s %s", adverb, str) == 2)
    adverb = " " + SOUL_D->find_adverb(adverb);

  if (adverb == " ")
    adverb = "";

  if (adverb != " slowly" && PREV && PREV->query_race() == "gnome")
    str = replace_string(str, " ", "");    

  if (str[<1] == '?') {
    what1 = "ask";
    what2 = "asked";
  }
  else if (str[<1] == '!') {
    what1 = "exclaim";
    what2 = "exclaimed";
  } 
  else {
    if (str[<1] != '.')
      str += ".";

    what1 = "say";
    what2 = "said";
  }

  name = PREV->query_cap_name();
  who = all_inventory(ENV(PREV));
  for(j = 0;j<sizeof(who);j++)
  {
   w_lang = who[j]->query_current_language();
   if(who[j] != PREV)
   {  
      str_scramble = "/daemon/language"->scramble(t_lang,
who[j]->query_skill_chance(t_lang), str);

      message ("com", capitalize(PREV->query_name(who[j])) +
      " "+pluralize(what1)+adverb+" in "+t_lang+", '^c1" + str_scramble + "^c0'\n",
      who[j],ENV(who[j]));
      who[j]->add_last("say",capitalize(PREV->query_name(who[j])) +
    " "+what2+adverb+" in "+t_lang+", '^c1" + str_scramble + "^c0'");
 }    
}  
 message ("com", "You "+what1+adverb+
 " in "+t_lang+", '^c1"+ str +"^c0'\n", PREV);
return 1;
}

query_author()
{
  return"project";
}

query_help()
{
  return "You use this to communicate with others in the same room. <msg> is"
  + " shown to everyone currently in the room.";
}

query_synopsis()
{
  return "say <msg>";
}

query_see_also()
{
  return "lang(1), whisper(1)";
}
query_position ()
{
  return POS_RESTING;
}

