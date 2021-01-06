// DATE        : Sun Dec 28 01:54:26 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Small dusky room");
  set_long (
    "You're in a small shadowy stairwell. Narrow stairs lead up and"
  + " down. A small window on the south wall lets the wind blow fr"
  + "esh air into the room. A simple candleholder has been attache"
  + "d to the west wall and a singe candle on it provides light to"
  + " the room. A doorway leads east and a door leads north.");

  add_exit ("down", ROOM_PATH + "questa4.c");
  add_exit ("north", ROOM_PATH + "queleg.c");
  add_exit ("up", ROOM_PATH + "questa10.c");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
