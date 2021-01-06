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
    object *who,PREV;
    string g_str, g_lang,temp_lang;
    int j;
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

  if (str == "last")
    {
      buf = PREV->query_last("say");
      for(int i=0;i<sizeof(buf);i++)
        message ("last", buf[i] + "\n", PREV);
      return 1;
    }

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
  g_str = "/home/madrid/gangsta.c"->scramble(str);
  g_lang = "gangsta";
  temp_lang = t_lang;
  for(j = 0;j<sizeof(who);j++)
  {
   w_lang = who[j]->query_current_language();
   if(who[j] != PREV)
   {  
      str_scramble = "/daemon/language"->scramble(t_lang,
      who[j]->query_skill_chance(t_lang), str);
      if(THIS->query_cap_name() == "Madrid")
      {
        str = g_str;
        temp_lang = t_lang;
        str_scramble= g_str;
        t_lang =  g_lang;
      }
      message ("com", capitalize(PREV->query_name()) +
      " "+pluralize(what1)+adverb+" in "+t_lang+", '^c1" + str_scramble + "^c0'\n",
      who[j],ENV(who[j]));
      who[j]->add_last("say",capitalize(PREV->query_name()) +
    " "+what2+adverb+" in "+t_lang+", '^c1" + str_scramble + "^c0'");
    t_lang = temp_lang;
 }    
}  

 message ("com", "You "+what1+adverb+
 " in "+t_lang+", '^c1"+ str +"^c0'\n", PREV);
return 1;
}
