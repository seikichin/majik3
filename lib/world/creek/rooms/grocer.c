// DATE        : Sun Nov  2 23:28:03 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Grocery");
  set_long (
    "You're in the Grocery of the city. The shelves are laid full o"
  + "f fresh food and the scent of bread and bacon makes you feel "
  + "hungry. Several items are hanging from the hooks on the walls"
  + ". A desk is on the back of the room. A door leads out to the "
  + "streets in south.");

  add_exit ("south", ROOM_PATH + "merchant5.c");

  set_outdoors (1);
  set_light (1);
  add_object (MONSTER_PATH + "joel");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
