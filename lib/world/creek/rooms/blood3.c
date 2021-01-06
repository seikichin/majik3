// DATE        : Sun Nov  2 21:11:06 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Blood Alley");
  set_long (
    "The Blood alley and the west gate area have a bad reputation. "
  + "It is here where most of the crimes of Silvercreek are commit"
  + "ted. The alley continues to the east and north. In north you "
  + "can see some kind of a bazaar. The west gate is around the co"
  + "rner in north.");

  add_exit ("north", ROOM_PATH + "blood4.c");
  add_exit ("east", ROOM_PATH + "blood2.c");

  add_object (MONSTER_PATH + "ruffian");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
