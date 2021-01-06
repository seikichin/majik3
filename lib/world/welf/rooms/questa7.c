// DATE        : Sun Dec 28 01:53:05 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Small dusky room");
  set_long (
    "You're in a small shadowy stairwell. Narrow stairs lead up and"
  + " down from  here. A small window on the north wall lets the w"
  + "ind blow fresh air into the room. A candleholder is attached "
  + "to the west wall and a single candle gives its light to the r"
  + "oom. A doorway leads east and a door leads south.");

  add_exit ("south", ROOM_PATH + "queleg.c");
  add_exit ("down", ROOM_PATH + "questa3.c");
  add_exit ("up", ROOM_PATH + "questa9.c");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
