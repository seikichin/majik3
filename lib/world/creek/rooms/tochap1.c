// DATE        : Sun Nov  2 22:22:54 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A short street");
  set_long (
    "You're now walking on a short street connecting Chapel street "
  + "and Ivory street. Chapel street is in the east and Ivory stre"
  + "et in the west. You can see the garden over the fence in west"
  + ". The main entrance to the Ivory Halls is around the corner"
  + " in west.");

  add_exit ("east", ROOM_PATH + "tochap2.c");
  add_exit ("west", ROOM_PATH + "ivory3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
