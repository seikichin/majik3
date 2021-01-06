// DATE        : Thu Nov  6 21:24:27 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Outside the northeast gate of Silvercreek");
  set_long (
    "You're now at the northern east gate of Silvercreek. This gate"
  + " is mainly used by the salesmen and the students at the Acade"
  + "my of Magic while the southern gate is used by everyone else."
  + " you can see a marketplace on the other side of the gate. A r"
  + "oad leads south to an opening.");

  add_exit ("south", ROOM_PATH + "opening.c");
  add_exit ("west", ROOM_PATH + "underneg.c");
  add_exit ("northeast", "/world/y87x345");

  add_object (MONSTER_PATH + "gateguard1");
  add_object (MONSTER_PATH + "gateguard1");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
