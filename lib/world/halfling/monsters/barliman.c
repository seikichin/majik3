inherit MONSTER;

#include "../path.h";

create_monster()
{
     set_name(({"barliman"}));
     set_short("Barliman Butterbung, a stout halfling");
     set_long(wrap("Before you stands a round, stout halfling. His is sweating profusely and "+
      "breathing hard. He wears a dirty, yellow shirt and a pair of torn trousers. His eyes "+
      "are a deep blue, and his hair is dark brown and very curly.\n"));

     set_gender (1);
     set_language ("palen");

     set_emote(({"Sweat pours from Barliman's brow.", 
                 "Barliman grabs a wrench and begins to assemble some sections of pipe."}));

     set_talk(({"Is there something you came for?",
                "If you want to know about irrigation just ask me about it.",
                "This job is a real bitch some times."}));
     
     set_race("halfling");

     set_levels(([ "fighter" : 15 ]));

}

init()
{
  add_action("do_ask","ask");
  add_action("do_buy","buy");
}

do_ask(string what)
{
  if(what == "barliman about irrigation")
  {
   say("If you plan on growing any crops 'round here your gonna need an ample "
    + "supply of water. I have pipes runnin' all over the Shire and you can access "
    + "them with one of my special water drills. They only last for a limited time so "
    + "don't ferget to come back. If you want to buy one I can sell you one right here. "
    + "They're only 10 gold, type 'buy water drill' to do so.\n");
    return 1;
  }
}

do_buy(string thing)
{
  if(thing == "water drill")
  {
    if(THIS->query_money() < 1000)
       {say("I said it costs 10 gold, which you don't have");
        return 1;}
      if(THIS->query_money() >= 1000)
    {
      say("Just a second and I'll get your drill.\n");
      write(wrap("Barliman runs off to front of the mill and returns quickly with an object "
       + "in his hand. He hands it to you with a smile and returns to his work.\n"));
      message("standard", THIS->query_cap_name()+" hands some money to "
       + "Barliman.\n", ENV(THIS), THIS);
      message("standard", "Barliman heads for the front of the mill and returns quickly. "
       + "He hands a strange object he brought back with him "
       + "to "+THIS->query_cap_name()+ "\n", ENV(THIS), THIS);
      clone_object("/home/madrid/agriculture/drill.c")->move(THIS);
      THIS->add_money(-1000);
      THOB->add_money(1000);
      return 1;
    }
  }
}



