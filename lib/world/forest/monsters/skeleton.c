inherit MONSTER;

#include "../path.h";

create_monster()
{
     set_name(({ "a skeleton warrior", "skeleton", "warrior" }));
     set_short("a skeleton warrior stalking his prey without emotion");
     set_long(wrap("You are nearly frozen with fear as you look at this horrible sight. It "+
      "is a skeleton. There is no flesh and the only thing besides bone are the softly "+
      "glowing eyes. A fierce, biting cold eminates from the skeleton that heightens your "+
      "fear. The warrior is wearing only a helm that has two horns which point down and "+
      "forward, almost directly into it's eyes.\n"));
   
     set_emote(({"A wave of cold eminates from the skeleton.", 
                 "The skeleton walks with an unceasing, robotic stride."}));

     
     set_wander(1, 30);

     set_msgin ("arrives, bones rattling");
     
     set_pick(75);
     
     add_weapon(ITEM_PATH + "longsword.c");     

     set_aggressive();    
     set_race("skeleton");
     set_levels(([ "fighter" : 58 + random(8) ]));
}
