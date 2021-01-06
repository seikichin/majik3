inherit MONSTER;

#include "../path.h"

#define say(x) "/command/mortal/say"->main(x)
#define room(x) message("standard", x, ENV(THIS), THIS)

create_monster()
{
     restore_object (MONSTER_PATH + "jaffer");
     set_name(({ "jaffer", "halfling" }));
     set_short("The Ol' Jaffer");
     set_long(wrap("The Ol' Jaffer is a halfling that's fat even as halflings go.  He has "+
      "blonde hair and blue eyes.  He stands about 3 feet tall.  He is wearing brown breeches "+
      "and a white cloth vest.  He stands behind the bar awaiting the next order.\n"));

     set_emote(({"The Ol' Jaffer grabs a rag and wipes down the bar.",
                 "Ol' Jaffer pours a beer and gives it to a customer.",
                 "Ol' Jaffer farts a nasty, smelly fart."}));

     set_language ("palen");
     set_gender (1);

     set_talk(({"What can I get ya?",
                "Try my Jaffer brew, it's the best around."}));

     set_race("halfling");

     set_levels(([ "fighter" : 10 ]));

     set_pick(80);
}

die ()
{
  rm (MONSTER_PATH + "jaffer.o");
}

init()
{
  ::init();
  add_action("do_order","order");
}
do_order(string drink)
{
  if(!drink)
  { 
    write("Usage: order <name>.\n");
  }
  if(capitalize(drink) == "Shot")
  {
    if(THIS->query_money() < 1)
     {say("You don't have enought money for that!");
      return 1;}
    if(THIS->query_money() >= 1)
     {      
    write(wrap("The Ol' Jaffer grabs a bottle of wiskey from behind the bar, pours a shot "+
           "and hands it to you.\n"));
    room(THIS->query_cap_name()+" recieves a shot of wiskey from The Ol' Jaffer.\n");
    clone_object(ITEM_PATH+"shot.c")->move(THIS);
    THIS->add_money(-1);
    THOB->add_money(1);
    save_object (MONSTER_PATH + "jaffer");
    return 1;
     }
  }

  if(capitalize(drink) == "Beer")
{
    if(THIS->query_money() < 2)
     {say("You don't have enought money for that!");
      return 1;}
    if(THIS->query_money() >= 2)
    {
    write("The Ol' Jaffer pours you a beer and hands it to you.\n");
    room(THIS->query_cap_name()+" orders a beer from The Ol' Jaffer.\n");
    clone_object(ITEM_PATH+"beer.c")->move(THIS);
    THIS->add_money(-2);
    THOB->add_money(2);
    save_object (MONSTER_PATH + "jaffer");
    return 1;
    }
}
  if(capitalize(drink) == "Wine")
{
    if(THIS->query_money() < 4)
     {say("You don't have enought money for that!");
      return 1;}
    if(THIS->query_money() >= 4)
    {
    write("The Ol' Jaffer grabs a bottle of red wine, pours a glass, and hands it to you.\n");
    room(THIS->query_cap_name()+" orders a glass of wine from The Ol' Jaffer.\n");
    clone_object(ITEM_PATH+"wine.c")->move(THIS);
    THIS->add_money(-4);
    THOB->add_money(4);
    save_object (MONSTER_PATH + "jaffer");
    return 1;
    }
}     
  write("We don't have that kind of drink.\n");
  return 0;

}
