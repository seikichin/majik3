// DATE        : Sun Nov  2 22:24:48 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A short street");
  set_long (
    "You're on a short street connectin Chapel and Ivory streets. C"
  + "hapel street is just a short distance in the east and Ivory s"
  + "treet in the west.");

  add_exit ("east", ROOM_PATH + "chapel2.c");
  add_exit ("west", ROOM_PATH + "tochap1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
