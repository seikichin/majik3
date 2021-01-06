// DATE        : Mon Dec 29 15:53:51 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Orchard");
  set_long (
    "Sweet scents welcome you as you walk along the apple and plumt"
  + "rees of the elven orchard. Small trees around you bear shiny "
  + "red apples and delicious looking plums. The orchard spreads i"
  + "n west and south while a small path leads east from here.");

  add_exit ("south", ROOM_PATH + "orchard2.c");
  add_exit ("east", ROOM_PATH + "torchard.c");
  add_exit ("west", ROOM_PATH + "orchard4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
