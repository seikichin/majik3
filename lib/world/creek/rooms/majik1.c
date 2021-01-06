// DATE        : Sat Nov  1 22:47:50 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("On Majik street, just east from the Temple square");
  set_long (
    "As the main street of the city, Majik Street is filled with pe"
  + "ople during the day and night. The High Temple of Truth can b"
  + "e seen some way in the west and the Majik street continues to"
  + " the east towards the southern east gate of the city. An old "
  + "gaslamp is glowing softly on the other side of the street.");

  add_exit ("east", ROOM_PATH + "majik2.c");
  add_exit ("west", ROOM_PATH + "templesq.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
