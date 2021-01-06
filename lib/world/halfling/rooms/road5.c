// DATE        : Mon Dec  8 05:16:03 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Market Road");
  set_long (
    "You are on a dirt road, mixed with hard packed clay. The road "
  + "runs to the west, which seems to be deeper into the town whil"
  + "e east leads out of it. There is a large hut to your north an"
  + "d a smaller structure to the south.");

  add_exit ("north", ROOM_PATH + "thall.c");
  add_exit ("south", ROOM_PATH + "booth.c");
  add_exit ("east", ROOM_PATH + "road6.c");
  add_exit ("west", ROOM_PATH + "road4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
