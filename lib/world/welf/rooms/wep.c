// DATE        : Tue Jan 27 20:18:33 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Sol'daran weaponry");
  set_long (
    "Weapons of all sorts have been placed on display around the sh"
  + "op. Mostly wooden ones like spears and bows remain the majori"
  + "ty but several shining blades and fine pieces of armour hang "
  + "on the walls as well. A glowing green crystal has been embedd"
  + "ed in the ceiling providing just the right kind of lightning "
  + "to the small room. The gleam and sparkle on the weapons are s"
  + "ure to make everyone to notice them. A door leads west.");

  add_exit ("west", ROOM_PATH + "ifwep.c");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
