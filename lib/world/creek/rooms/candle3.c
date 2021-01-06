// DATE        : Sun Nov  2 19:10:57 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the crossing of Candle and Northern Temple street");
  set_long (
    "You've arrived to the crossing of Candle street and The Northe"
  + "rn Temple street. The Candle street continues to the north an"
  + "d south where the Temple Square is and the Northern Temple st"
  + "reet continues to the west. You hear some noises coming from "
  + "the market place nearby.");

  add_exit ("south", ROOM_PATH + "candle1.c");
  add_exit ("north", ROOM_PATH + "candle5.c");
  add_exit ("west", ROOM_PATH + "ntemple2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
