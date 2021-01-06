// DATE        : Thu Feb  5 17:43:13 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Small alcove");
  set_long (
    "You're in a small alcove of one of the Sol'daran's treehouses."
  + " Small glowing crystals are embedded into the walls illuminat"
  + "ing the room in a bright silvery light. A small wooden bench "
  + "has been placed beside the northern wall. A curtained doorway"
  + " leads west from here.");

  add_exit ("west", ROOM_PATH + "birchma.c");
  add_exit ("east", ROOM_PATH + "birchin.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
