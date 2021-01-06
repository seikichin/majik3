// DATE        : Sat Nov  1 23:29:48 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Majik street, at the Baker's sign");
  set_long (
    "As the main street of the city, Majik Street is filled with pe"
  + "ople during the day and night. The High Temple of Truth can b"
  + "e seen some way in the west and the Majik street continues to"
  + " the east towards the southern east gate of the city. A smell"
  + " of freshly baked coming from the bakery in the north fills t"
  + "he air. A sign is hanging above the baker's door. An old gasl"
  + "amp is glowing softly on the other side of the street.");

  add_exit ("north", ROOM_PATH + "baker.c");
  add_exit ("east", ROOM_PATH + "majik4.c");
  add_exit ("west", ROOM_PATH + "majik2.c");

  add_item ("sign",
    "A sign is hanging above the door. It reads:\n        .__.__.___"
  + ".___.__._\n       ( .  .   .   .   .  )\n      ('  .   .   .   "
  + ".   .`)\n      `|                   |'\n       |  The City Bake"
  + "ry  |\n       |  Open: 06-20      |\n       |                  "
  + " |\n       `-------------------'\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
