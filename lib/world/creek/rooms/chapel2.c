// DATE        : Thu Nov  6 19:41:34 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Chapel street");
  set_long (
    "You're now walking along Chapel street. A short street leads w"
  + "est to Ivory street and to the Ivory Halls. Chapel street lea"
  + "ds north and south. You can see the city cemetary some distan"
  + "ce in south.");

  add_exit ("west", ROOM_PATH + "tochap2.c");
  add_exit ("south", ROOM_PATH + "chapel1.c");
  add_exit ("north", ROOM_PATH + "chapel3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
