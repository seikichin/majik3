// DATE        : Sun Nov  2 21:32:32 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Bazaar");
  set_long (
    "You're now near the west gate of Silvercreek. The surrounding "
  + "area has quite a bad reputation, being the place where most o"
  + "f the crimes in city are done. The square before the gate is "
  + "some kind of a bazaar. It stretches to east and south. Some t"
  + "ricksters and ruffians are trying to earn their bread nearby,"
  + " fooling some unfortunate travellers. Some distance in south "
  + "east you can see a tavern.");

  add_exit ("south", ROOM_PATH + "bazaar1.c");
  add_exit ("east", ROOM_PATH + "bazaar4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
