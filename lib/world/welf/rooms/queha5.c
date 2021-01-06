// DATE        : Thu Mar 12 21:27:07 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Long hallway");
  set_long (
    "The long hallway you're standing in runs in east-west directio"
  + "n. The floor here is covered with a long green carpet. Few di"
  + "mly glowing crystals have been attached to the walls to provi"
  + "de some light to the otherwise so dusky hallway. At the both "
  + "ends of the hallway there's a magnificent mosaic window.");

  add_exit ("west", ROOM_PATH + "questa6.c");
  add_exit ("south", ROOM_PATH + "quero7.c");
  add_exit ("east", ROOM_PATH + "queha6.c");

  add_item ("crystal crystals",
    "They glow faintly with green light. They seem to be firmly att"
  + "ached to the walls.\n");

  add_item ("window mosaic",
    "They really are fine pieces of art, but t"
  + "he view through the windows is a bit too obscure.\n");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
