inherit MONSTER;

#include "../path.h";

create_monster()
{
     set_name(({"Rayak","rayak", "goblin king"}));
     set_short("Rayak, the goblin king stares at you with bloodlust in his eyes");
     set_long(wrap("Rayak is a very frightening figure. His huge red eyes stare at you with "+
      "disgust. He has dark green skin which you get a clear view of through is open leather "+
      "vest. Rayak is one of the scariest goblins you have ever seen. He has gigantic muscles "+
      "which are flexed as he prepares to tear you to pieces.\n"));

     set_emote(({"Rayak flexes his muscles.", 
                 "Rayak barks some orders at a fearful goblin.",
                 "Rayak looks at your puny form and laughs uncontrollably."}));

     set_language("grahnik");

     set_talk(({"You are no match for me.",
                "I'll give you the first shot, if you think you can beat me.",
                "This forest is mine and nobody can stop me!",
                "Once Kane has finished off the feeble elf, we will triumph."}));
     
     add_weapon(ITEM_PATH + "longsword.c");
     add_object(ITEM_PATH + "woodfrag.c"); 
     add_object(ITEM_PATH + "ghead.c");

     set_gender (1);

     /* Goblin kings are usually quite tough, almost best of goblins! */
     
     set_race("goblin");
     set_levels (([ "fighter" : 50 + random(20) ]));

     add_alignx (-random(1024));
     add_aligny (-random(1024));
     
     add_money (100 + random(100));
}
