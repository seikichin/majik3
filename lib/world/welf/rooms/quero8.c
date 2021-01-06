// DATE        : Sun Dec 28 01:50:21 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Small atelier");
  set_long (
    "You're standing in a room that seems to be a small atelier. Th"
  + "e walls are covered with various paintings. Before the window"
  + " in south has been placed an easel and next to it a small tab"
  + "le. Several brushes and paint jars have been laid on the tabl"
  + "e. A door leads north from here.");

  add_exit ("north", ROOM_PATH + "queha6.c");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
