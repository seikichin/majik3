// DATE        : Thu Nov  6 19:45:56 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Chapel street");
  set_long (
    "Your walking along the Chapel street which runs in north-south"
  + " direction from the arcane street towards the city cemetary i"
  + "n south. A small gaslamp glows softly on the other side of th"
  + "e street.");

  add_exit ("south", ROOM_PATH + "ntemple5.c");
  add_exit ("north", ROOM_PATH + "chapel2.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
