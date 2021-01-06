// DATE        : Sun Dec 28 02:17:58 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Small balcony");
  set_long (
    "You're standing on a small balcony. The forest looks absolutel"
  + "y magnificent seen from the Que-Moran, the treepalace. A curi"
  + "ous looking liftsystem has been built on the balcony for an e"
  + "asier way to lift food deliveries from the kitchen shelter be"
  + "low. A door leads west into the treepalace.");

  add_exit ("west", ROOM_PATH + "queleg.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
