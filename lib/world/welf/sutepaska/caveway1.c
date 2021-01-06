// DATE        : Thu Nov  6 19:20:56 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A caveway");
  set_long (
    "The caveway twists here and there abruptly from one side to an"
  + "other and you lose sense of direction soon. Luckily there are"
  + " no side passages and you can't really get lost in here. The "
  + "floor and walls of the cave are moist and water drips from th"
  + "e ceiling sending echoes from the walls. The dripping noise i"
  + "s quite calming. The caveway leads east and south.");

  add_exit ("east", ROOM_PATH + "caveway2.c");
  add_exit ("south", ROOM_PATH + "glittercave.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
