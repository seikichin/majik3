// DATE        : Mon Jan  5 15:20:24 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Outside the Mill");
  set_long (
    "Before you stands a large set of double doors attached to a bi"
  + "g wooden building. Opposite of that, a bridge crosses a quick"
  + "ly flowing river. The river flows out of the north and the ma"
  + "kes a turn east around the building. A small patch land betwe"
  + "en the two goes around the southern side of the structure.");

  add_exit ("enter", ROOM_PATH + "mill2.c");
  add_exit ("west", ROOM_PATH + "bridge.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
