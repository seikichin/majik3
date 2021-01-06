// DATE        : Mon Nov  3 20:56:54 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Bank");
  set_long (
    "An elegant looking hall with just few pieces of furniture. Cha"
  + "irs and sofas on one wall and a long desk on the other. Behin"
  + "d the desk sits an important looking bank officer. A door lea"
  + "ds east back to the streets.");

  add_exit ("east", ROOM_PATH + "gold2.c");

  set_outdoors (1);
  set_light (1);
  add_object (MONSTER_PATH + "officer");
}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
