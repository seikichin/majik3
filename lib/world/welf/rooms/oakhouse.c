// DATE        : Thu Feb 26 19:50:30 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Treehouse");
  set_long (
    "You're in a small room which is used as an alcove to the treeh"
  + "ouse. There isn't much of a furniture, just an old rugged sof"
  + "a and a small table beside it. A small window on the east wal"
  + "l lets some light into the room. Ropeladders lead down to the"
  + " ground level through a round hole at the center of the floor"
  + ". An arched doorway leads west.");

  add_exit ("down", ROOM_PATH + "oakunder.c");
  add_exit ("west", ROOM_PATH + "oakmain.c");

  add_item ("sofa",
    "It's old and rugged and fits here perfectly.\n");

  add_item ("window",
    "The view is quite"
  + " nice and you'd love to spend some more time looking at the a"
  + "ctivities down in the city.\n");

  add_item ("table",
    "It is old like the sofa beside it"
  + " and has been through a lot of use.\n");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
