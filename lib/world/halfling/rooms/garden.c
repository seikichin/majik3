// DATE        : Sun Nov  2 21:42:11 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Garden");
  set_long (
    "This is a small garden. There are a few different types of veg"
  + "tables growing here. A white picket fence surrounds the garde"
  + "n with a gate leading to the south.");

  add_exit ("south", ROOM_PATH + "yard.c");

  set_outdoors(4);

  add_item ("vegtables garden",
    "The vegtables are mostly tomatoes, but there are a few cucumbe"
  + "rs growing here too. They don't look very ripe, but you could "
  + "pick a vegtable and eat it anyway.\n");

  add_item ("yard",
    "The yard is south of you, in front of so"
  + "meone's dwelling. The grass is cut short and there is a dirt "
  + "walkway leading from the road, to the east, to the front door"
  + ".\n");

  add_item ("gate",
    "The gate leads south to a yard. It doesn't have a lock, but"
  + " is tied closed with some string.\n");

  add_item ("fence",
    "The white picket fence surr"
  + "ounds the entire garden. There is a gate on it that leads to "
  + "the south, into someone's front yard.\n");

}

init()
{
   ::init();
   add_action("do_pick","pick");
}

do_pick(string what)
{
   if (what != "vegtables" && what != "vegtable")
  { 
   write("Pick what? There are only vegtables here.\n");
   return 1;
  }
 else
  {
   write("You pick a small, slightly white, tomato from the garden.\n");
   write("An angry voice calls from inside the burrow to the south: "+
         "Get the HELL out of my garden you bastard!\n");
   message("standard", THIS->query_cap_name() + " picks a tomato from the "+
           "garden.\n", ENV(THIS), THIS);
   clone_object(ITEM_PATH + "tomato.c")->move(THIS);
   return 1;
  }
}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

