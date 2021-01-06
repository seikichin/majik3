// DATE        : Tue Jan 27 20:14:42 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A treetop above the Swantemple");
  set_long (
    "You're standing on a wooden platform high above the ground on "
  + "a treetop near the swantemple. Birds tsirp happily on the per"
  + "ches nearby and the fresh forest air makes you close your eye"
  + "s and walk in reveries. Spiralling stairs lead down to the gr"
  + "ound and narrow ropebridges lead to another treetops in east,"
  + " west and south.");

  add_exit ("east", ROOM_PATH + "rope5.c");
  add_exit ("west", ROOM_PATH + "rope1.c");
  add_exit ("down", ROOM_PATH + "corner2.c");
  add_exit ("south", ROOM_PATH + "rope2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
