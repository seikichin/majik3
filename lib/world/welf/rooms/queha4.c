// DATE        : Thu Mar 12 21:22:39 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Long hallway");
  set_long (
    "You're standing at the west end of a long hallway. The floor i"
  + "s covered with a long green carpet. Few faintly glowing cryst"
  + "als have been attached to the walls and provide some light to"
  + " the hallway. A large colorstained mosaic window gives a magn"
  + "ificent view over the city in west.");

  add_exit ("south", ROOM_PATH + "quero5.c");
  add_exit ("east", ROOM_PATH + "questa6.c");

  add_item ("crystal crystals",
    "They seem to glow dimly with green light providing some light "
  + "to the otherwise so dusky hallway. The crystals seem to be fi"
  + "rmly attached to the walls.\n");

  add_item ("window mosaic",
    "The view through the window is ma"
  + "gnificent, but alas, so blurred.\n");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
