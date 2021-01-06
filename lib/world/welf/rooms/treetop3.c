// DATE        : Tue Oct 28 21:40:22 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A treetop above the Swantemple");
  set_long (
    "You are standing on a wooden platform high above the ground on a tr"
  + "eetop. The wind tugs at your clothes and makes you feel as free as"
  + " the birds flying from tree to tree near you. Spiralling stairs le"
  + "ad down to the ground from a hole in the center of the platform an"
  + "d narrow ropebridges lead to west and north from here.");

  add_exit ("north", ROOM_PATH + "rope2.c");
  add_exit ("west", ROOM_PATH + "rope3.c");
  add_exit ("down", ROOM_PATH + "corner3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
