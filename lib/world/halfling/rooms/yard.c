// DATE        : Sat Nov  8 10:10:56 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Front yard");
  set_long (
    "You have entered someone's front yard. There is a dirt walkway"
  + ", which you're standing on, heading from the road to the east"
  + " to a burrow. There is one wooden door on the burrow and two "
  + "circular windows. A white fence with a gate is to the north.");

  add_exit ("north", ROOM_PATH + "garden.c");
  add_exit ("east", ROOM_PATH + "road3.c");
  add_exit ("west", ROOM_PATH + "burrow2.c");

  set_outdoors(4);

  add_item ("gate",
    "The gate is closed, but is only held that way by a piece of st"
  + "ring.\n");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
