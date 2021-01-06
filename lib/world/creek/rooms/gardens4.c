// DATE        : Mon Nov  3 21:12:33 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Ivory Halls");
  set_long (
    "You're walking in a long hall. Everything here is made pf so,e"
  + " strange white stonelike material. The hall floor is covered "
  + "with a long red carpet. Ivory garden is in the east and the h"
  + "all of justice in north while the hall of gathering is in sou"
  + "th.");

  add_exit ("east", ROOM_PATH + "gardens2.c");
  add_exit ("south", ROOM_PATH + "gardens5.c");
  add_exit ("north", ROOM_PATH + "gardens6.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
