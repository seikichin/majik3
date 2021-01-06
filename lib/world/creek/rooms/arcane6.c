// DATE        : Sun Nov  2 22:15:09 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The crossing of Arcane and Chapel streets");
  set_long (
    "You're now at the crossing of Arcane and Chapel. The Chapel st"
  + "reet leads south towards the city cemetary while the Arcane s"
  + "treet leads east and west. Far in the east you can see the ma"
  + "ssive building of the Academy of Magic.");

  add_exit ("south", ROOM_PATH + "chapel3.c");
  add_exit ("east", ROOM_PATH + "arcane5.c");
  add_exit ("west", ROOM_PATH + "arcane7.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
