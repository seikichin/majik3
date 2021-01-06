// DATE        : Sun Jan 18 20:02:16 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A treetop above the Swantemple");
  set_long (
    "You're standing on a wooden platform high above the ground on "
  + "a treetop near the swantemple. The wind tugs at your clothes "
  + "and you feel as free as the birds that fly from tree to tree "
  + "near you. Spiralling stairs lead down to the ground from a ho"
  + "le in the center of the platform and narrow bridges lead nort"
  + "h south and east.");

  add_exit ("south", ROOM_PATH + "rope4.c");
  add_exit ("north", ROOM_PATH + "watchbridge.c");
  add_exit ("east", ROOM_PATH + "rope1.c");
  add_exit ("down", ROOM_PATH + "corner1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
