// DATE        : Sun Feb  8 19:44:12 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Forest clearing");
  set_long (
    "The path ends here at a small clearing. The mossy forestfloor "
  + "is covered with colorful flowers and the air is filled with t"
  + "he scent of woodland. Tall trees surround the clearing in eve"
  + "ry direction hiding the animals and their dens behind a thick"
  + " wall of wood. Three paths lead north, east and west from her"
  + "e.");

  add_exit ("north", ROOM_PATH + "fpath3.c");
  add_exit ("east", ROOM_PATH + "fpath1.c");
  add_exit ("west", ROOM_PATH + "fpath2.c");

  add_sound ("A cute little bunny hops across the opening.");
  add_sound ("Birch chirp in the nearby trees.");
  add_sound ("Melodical laughter echoes through the forest.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
