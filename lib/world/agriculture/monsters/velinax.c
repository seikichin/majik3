inherit MONSTER;

#include "../path.h"

#define say(x) "/command/mortal/say"->main(x)
#define room(x) message("standard", x, ENV(THIS), THIS)

create_monster()
{
     restore_object (MONSTER_PATH + "velinax");
     set_name(({ "velinax", "halfling" }));
     set_short("velinax");
     set_long(wrap("Velinax is here clothed in a red, longsleeved shirt and dark pants. "+
      "He has a long beard which covers most of his face and neck. He is an average height "+
      "halfing with big green eyes.\n"));

     set_emote(({"Velinax picks his nose a bit.",
                 "Velinax looks through a brown sack in his hand."}));

     set_language ("palen");
     set_gender (1);

     set_talk(({"Well, are you gonna buy something or not?",
                "Everything I sell is listed on the sign."}));

     set_race("halfling");

     set_levels(([ "fighter" : 35 ]));

     set_pick(15);
}

die ()
{
  rm (MONSTER_PATH + "velinax.o");
  ::die();
}

init()
{
  ::init();
  add_action("do_buy","buy");
}
do_buy(string item)
{
  if(!item)
  { 
    write("Usage: buy <item name>.\n");
  }
  if(capitalize(item) == "Corn seeds")
  {
    if(THIS->query_money() < 200)
     {say("You don't have enought money for that!");
      return 1;}
    if(THIS->query_money() >= 200)
     {      
    write(wrap("Velinax shuffles through his sack. He pulls out a pouch of corn seeds and "+
           "hands them to you.\n"));
    room(THIS->query_cap_name()+" recieves a pouch of corn seeds from Velinax.\n");
    clone_object(ITEM_PATH+"corn_seeds.c")->move(THIS);
    THIS->add_money(-200);
    THOB->add_money(200);
    save_object (MONSTER_PATH + "velinax");
    return 1;
     }
  }

  if(capitalize(item) == "Hoe")
{
    if(THIS->query_money() < 500)
     {say("You don't have enought money for that!");
      return 1;}
    if(THIS->query_money() >= 500)
    {
    write("Velinax pulls out a hoe from behind the counter and hands it to you.\n");
    room(THIS->query_cap_name()+" recieves a hoe from Velinax.\n");
    clone_object(ITEM_PATH+"hoe.c")->move(THIS);
    THIS->add_money(-500);
    THOB->add_money(500);
    save_object (MONSTER_PATH + "velinax");
    return 1;
    }
}
  if(capitalize(item) == "Sicle")
{
    if(THIS->query_money() < 700)
     {say("You don't have enought money for that!");
      return 1;}
    if(THIS->query_money() >= 700)
    {
    write("Velinax pulls out a sicle from behind the counter and hands it to you.\n");
    room(THIS->query_cap_name()+" recieves a sicle from Velinax.\n");
    clone_object(ITEM_PATH+"sicle.c")->move(THIS);
    THIS->add_money(-4);
    THOB->add_money(4);
    save_object (MONSTER_PATH + "jaffer");
    return 1;
    }
}     
  say("I don't have that kind item.");
  return 1;

}
