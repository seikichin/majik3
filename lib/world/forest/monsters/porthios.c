inherit MONSTER;

#include "../path.h";
#define say(x) "/command/mortal/say"->main(x)

create_monster()
{
     set_name(({"Porthios","porthios", "elf" "prince","prince porthios"}));
     set_short("Porthios, the elven prince watches the forest floor from above");
     set_long(wrap("Porthios is a tall, slender elf. He has a certain air of superiority about "+
      "him. He wears a golden headband, which signifies him as a prince. He is clothed in a "+
      "dark green cloak over his breastplate.\n"));

     set_emote(({"Porthios looks out the window.", 
                 "Porthios sighs in despair."}));

     set_language("alande");

     set_talk(({"We must stop the goblins!",
                "The goblins are destroying our beautiful forest."}));

     set_gender (1);     
     set_race("tanir");
     set_levels(([ "fighter" : 33 + random(33) ]));
}

init()
{
  add_action("do_show","show");
}

do_show(string what)
{
  if(what == "pendant" && (present("pendant",THIS)));
  {
    if(present("obfrag",THIS));
    {
      say(THIS->query_cap_name()+", you already have the obsidian moon fragment. "
       + "There is nothing more I can offer you to aid you in the quest.");
      return 1;
    }
   write(wrap("You show the silver pendant to Porthios and he hands you something.\n"));
   say ("Since you hold my mother's silver pendant, I know you have accepted the quest to "+
    "save Filonius. I have given you one of the four moon fragments, which you will need to "+
    "enter the top room of the tower, where Filonius is being held captive by Kane. Kane is a "+
    "human mage who is helping the goblins steal the forest from us. You must find the three "+
    "other moon fragments and ^c1^cw'assemble'^c1^cg them to form the sacred Moon Shield. Once you have "+
    "the shield you will be able to enter the top of the tower. There you will have to defeat "+
    "Kane and save Filonius from his torture. It is belived that the Goblin King, hiding in "+
    "the forest, has one of the fragments while the other two can be found inside the tower.");

   message("standard", THIS->query_cap_name() + " shows a pendant to "+
    "Porthios.\n", ENV(THIS), THIS);
   clone_object(ITEM_PATH + "obfrag.c")->move(THIS);
   return 1;
  }
  
  if(what == "pendant")
   {
    say("Who are you!? My mother didn't give my any notice of you comming here. "
     + "Leave now, before I slice off your ear for lying!");
    return 1;
   }
}

