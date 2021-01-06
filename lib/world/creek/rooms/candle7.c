// DATE        : Sun Nov  2 20:46:10 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Candle street");
  set_long (
    "The Candle street continues to the north towards the Temple sq"
  + "uare and to the south where it joins the Merchant street. A l"
  + "oud banging of hammer on anvil comes from the nearest buildin"
  + "g in the west, must be the smithy of the city. Its door is ju"
  + "st around the corner in the south.");

  add_exit ("south", ROOM_PATH + "merchant1.c");
  add_exit ("north", ROOM_PATH + "candle4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
