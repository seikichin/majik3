// DATE        : Mon Dec 29 16:00:27 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Under a treeshed");
  set_long (
    "You're standing under a small shed that's built on top of a ta"
  + "ller appletree. Strong looking ropeladders lead up into the s"
  + "hed through a hole in its bottom. The elven orchard spreads i"
  + "tself in north.");

  add_exit ("up", ROOM_PATH + "shed.c");
  add_exit ("north", ROOM_PATH + "orchard3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
