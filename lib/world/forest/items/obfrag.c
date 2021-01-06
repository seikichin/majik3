inherit ITEM;

#include "../path.h"

create_item()
{
     set_name(({"fragment","moon fragment","obsidian fragment","obfrag"}));
     set_short("an obsidian moon fragment");
     set_long(wrap("A small obsidian piece, shaped like a half moon.  On the backside of the "+
              "fragment are four lines forming diamond.\n"));


     set_dimensions(2, 3, 2);
     set_weight(20);
     set_hp(150);
     set_max_hp(150);
     set_material("adamantium");
     
}

init()
{
   add_action("do_assemble","assemble");
}

do_assemble(string what)
{ 
  if(what == "fragments")
  {
    if(present("wood fragment",THIS)&&present("marble fragment",THIS)&&present("stone fragment",THIS))
    {
     write(wrap("You fumble with each of the fragments for a while. Then suddenly, you find a way "+
      "to piece them together. Each piece glows brightly and they begin to meld together. "+
      "The fragments have become something new!\n"));
     message("standard",THIS->query_cap_name() + " puts each of the moon fragments together. "+
      "They glow brightly then fade back down.\n", ENV(THIS), THIS);
     clone_object(ITEM_PATH + "moonshield.c")->move(THIS); 
     destruct(present("wood fragment"));
     destruct(present("marble fragment"));
     destruct(present("stone fragment"));
     destruct(THOB);
     return 1;
    }
    else
    {
     write(wrap("You try to assemble the moon fragments, but you realize that something is missing "+
      "from the puzzle.\n"));
     return 1;
    }
  }
  else
  {
   write("Assemble what?\n");
   return 1;
  }
}


