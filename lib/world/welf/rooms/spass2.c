// DATE        : Thu Dec 25 19:29:25 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Spring pass");
  set_long (
    "Lush darkgreen plants line the sides of the cobblestoned stree"
  + "t which leads west towards the holy swantemple. In the east t"
  + "here is a nice looking fountain square where people can meet "
  + "and relax.");

  add_exit ("west", ROOM_PATH + "spass1.c");
  add_exit ("east", ROOM_PATH + "square.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
