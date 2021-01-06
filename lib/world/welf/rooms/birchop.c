// DATE        : Tue Jan 27 20:20:23 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At a beautiful birchtree");
  set_long (
    "A solitary birch stands here at the center of a small opening."
  + " It is sturdy enough to hold a small treehouse on its perches"
  + " but its beauty remains undeniable. Its leaves are of golden "
  + "colors and its white bark shimmers like silver. Slender stair"
  + "s spiral around its trunk to the treehouse. A path leads east"
  + " to Morninglane.");

  add_exit ("east", ROOM_PATH + "mlane3.c");
  add_exit ("up", ROOM_PATH + "birchin.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
