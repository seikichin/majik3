// DATE        : Mon Nov  3 21:23:22 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Smithy");
  set_long (
    "Sparkles fly in the air as the smith pounds his hammer down on"
  + " the anvil. The constant banging makes you ears ring. The roo"
  + "m is darkly lit, only the red embers give it some light. The "
  + "floor and shelves here are quite dusty, but this is a smithy "
  + "after all. A door leads east to the streets.");

  add_exit ("east", ROOM_PATH + "merchant2.c");
  add_object (MONSTER_PATH + "rolf");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
