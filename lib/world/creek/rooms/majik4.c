// DATE        : Sat Nov  1 23:39:15 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the crossing of Majik and Gate streets");
  set_long (
    "You've standing at the crossing of Majik and Gate streets. As "
  + "the main street of the city, Majik street is filled with peop"
  + "le. The Majik street continues to the west and the Gate stree"
  + "t to the north and south. The southern east gate can be seen "
  + "a short distance to the east and the Market place in north. A"
  + " smell of freashly baked bread drifts in from the west.");

  add_exit ("south", ROOM_PATH + "gate2.c");
  add_exit ("north", ROOM_PATH + "gate1.c");
  add_exit ("east", ROOM_PATH + "underseg.c");
  add_exit ("west", ROOM_PATH + "majik3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
