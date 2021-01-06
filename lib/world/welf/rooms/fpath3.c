// DATE        : Tue Feb 10 20:48:03 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Forest");
  set_long (
    "You're walking along a well trodden path that leads through th"
  + "e Sol'daran forest towards north. In the south the path ends "
  + "at a small clearing. Tall and majestetic pines and beeches li"
  + "ne the path on both sides. Behind them the forest get denser "
  + "and wilder. Here and there you can see some small animals wat"
  + "ching you curiously from their hiding places in the undergrow"
  + "th.");

  add_exit ("south", ROOM_PATH + "fclearing.c");
  add_exit ("north", ROOM_PATH + "fpath4.c");

  add_sound ("A small bird looks curiously at you from its perch in a tall pinetree.");
  add_sound ("The wind hustles in the trees.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
