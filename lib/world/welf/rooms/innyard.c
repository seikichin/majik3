// DATE        : Sat Nov  1 21:16:34 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the sign of the Sunflower Tavern");
  set_long (
    "You're standing in front of the Sunflower Tavern. The building"
  + " is quite an extraordinary sight. It has been built aroun"
  + "d a huge oak and some of the inn rooms are actually on the tr"
  + "ee's limbs. The building is painted green to fit in the surrou"
  + "nding forest, but its door is bright red and very welcoming. "
  + "A sign has been hung above the door. The street is in the w"
  + "est and in the south are located the inn stables.");

  add_exit ("south", ROOM_PATH + "stables.c");
  add_exit ("east", ROOM_PATH + "sunflower.c");
  add_exit ("west", ROOM_PATH + "street2.c");
  add_door ("east", ROOM_PATH + "sunflower.c", "door","wooden", 0, 0, 0);

  add_item ("sign",
    " \n__________________________________,-.\n==+======-==--=-======"
  + "=======+====._,'\n  |                          |\n,-+----------"
  + "----------------+-.\n| ..::THE SUNFLOWER TAVERN::.. |\n|       "
  + "--,--'--,--'--{@       |\n|    The Cheapest and Best     |\n|  "
  + "   Tavern in Sol'daran      |\n`=============================="
  + "'\n");

  add_sound ("You can hear the horses neighing inside the stables.");
  add_sound ("A loud merrymaking echoes from inside the tavern.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
