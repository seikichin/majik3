// DATE        : Thu Mar 12 21:17:44 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Long hall");
  set_long (
    "You're standing at the east end of a long hallway. The floor h"
  + "ere is covered with a long green carpet. Few dimly glowing cr"
  + "ystals are attached to the walls and provide light to the hal"
  + "lway. A large colorstained window gives an alluring, yet obsc"
  + "ure view over the surrounding forest in east. You notice a si"
  + "milar window at the other end of the hallway.");

  add_exit ("west", ROOM_PATH + "queha2.c");
  add_exit ("north", ROOM_PATH + "quero4.c");

  add_item ("window",
    "A really awesome piece of mosaic. The light shining through th"
  + "e window is filtered in myriad colors.\n");

  add_item ("crystal crystals",
    "The crystals glow fain"
  + "tly with green light providing some light to the otherwise so"
  + " dusky hallway. They seem to be firmly attached to the walls."
  + "\n");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
