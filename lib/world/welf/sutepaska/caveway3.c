// DATE        : Thu Nov  6 19:23:33 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A caveway");
  set_long (
    "The caveway ends here abruptly. Fresh air drift in the cave fr"
  + "om an opening. Bushes grow outside the cave at the mouth of i"
  + "t and must conceal the cave perfectly from outside. The bushe"
  + "s and leaves form a dense wall at the mouth of the cave but y"
  + "ou think you could manage to push yourself through them. The "
  + "caveway leads south and in the north you can escape out.");

  add_exit ("south", ROOM_PATH + "caveway2.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
