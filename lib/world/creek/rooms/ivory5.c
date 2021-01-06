// DATE        : Sun Nov  2 22:21:39 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The crossing of Arcane and Ivory streets");
  set_long (
    "You've arrived to the crossing of Ivory and Arcane. Arcane str"
  + "eet leads east from here and the Ivory street leads south to "
  + "the doors of Ivory Halls and the strange bazaar near the we"
  + "st gate.");

  add_exit ("south", ROOM_PATH + "ivory4.c");
  add_exit ("east", ROOM_PATH + "arcane8.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
