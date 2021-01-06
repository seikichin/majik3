// DATE        : Sun Dec 28 01:45:43 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Dusky chamber");
  set_long (
    "This room is neatly furnished. A writing desk and a chair have"
  + " been placed before the window on the north wall and the east"
  + " and west walls are fully covered by bookcases. A strange run"
  + "e embroidered carpet covers the whole floor. A door leads sou"
  + "th.");

  add_exit ("south", ROOM_PATH + "queha3.c");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
