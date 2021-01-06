// DATE        : Thu Feb 26 20:11:23 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Under an old oak");
  set_long (
    "You're standing on top of a small hill. A sturdy old oak grows"
  + " here towering over you. You can see that a treehouse has bee"
  + "n built on its crown, the bottom of the house showing through"
  + " the lowest branches. Ropeladders lead up into the house thro"
  + "ugh a hole on its floor and a path least east where it joins "
  + "Morninglane.");

  add_exit ("east", ROOM_PATH + "mlane1.c");
  add_exit ("up", ROOM_PATH + "oakhouse.c");

  add_sound ("A fawn looks at you with its large round eyes and darts back into the forest where it came from.");
  add_sound ("A small squirrel climbs incredibly quickly to the oak's top.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
