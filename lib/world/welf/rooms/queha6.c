// DATE        : Thu Mar 12 23:15:43 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Long hallway");
  set_long (
    "You're standing at the east end of a long hallway. The floor i"
  + "s covered with a long green carpet. Few dimly glowing crystal"
  + "s are attached to the walls and provide some light to the dus"
  + "ky hallway. A large colorstained window gives you a nice, yet"
  + " obscure view over the surrounding forest. There's a similar "
  + "window at the other end of the room.");

  add_exit ("west", ROOM_PATH + "queha5.c");
  add_exit ("south", ROOM_PATH + "quero8.c");

  add_item ("window",
    "A fine piece of art, and it provides you a nice, yet a bit obs"
  + "cured, view over the forest that surrounds the Que-Moran's tr"
  + "eepalace.\n");

  add_item ("crystal crystals",
    "They all seem to glow with a faint green light. The"
  + "y are firmly attached to the walls and there's absolutely no "
  + "way to remove them.\n");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
