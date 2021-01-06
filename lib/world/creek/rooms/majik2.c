// DATE        : Sat Nov  1 23:26:07 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Crossing of Majik and Market streets");
  set_long (
    "You've standing at the crossing of Majik and Market streets. A"
  + " smell of fresh baked bread comes from the east where the Bak"
  + "er's sign can be seen. The Majik street continues to the east"
  + " and west while the Market street leads north and south. In t"
  + "he south you can see the Market place of the city.");

  add_exit ("south", ROOM_PATH + "market2.c");
  add_exit ("north", ROOM_PATH + "market1.c");
  add_exit ("east", ROOM_PATH + "majik3.c");
  add_exit ("west", ROOM_PATH + "majik1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
