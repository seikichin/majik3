// DATE        : Fri Oct 31 00:45:52 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A treetop above the Swantemple");
  set_long (
    "You are standing on a wooden platform high above the ground on"
  + " a treetop. The wind tugs at your clothes and makes you feel "
  + "as free as the birds flying from tree to tree near you. Spira"
  + "lling stairs lead down to the ground from a hole in the cente"
  + "r of the platform and narrow ropebridges lead to east and nor"
  + "th from here.");

  add_exit ("south", ROOM_PATH + "herbarope.c");
  add_exit ("north", ROOM_PATH + "rope4.c");
  add_exit ("east", ROOM_PATH + "rope3.c");
  add_exit ("down", ROOM_PATH + "corner4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
