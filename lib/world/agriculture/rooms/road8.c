// DATE        : Sun Jan 18 21:26:55 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Old Mill Road");
  set_long (
    "The road here is damp with a few puddles, making it a little m"
  + "uddy. You see that the road goes on further to the west, whil"
  + "e east there is a picket fence with a gate on it. The fence s"
  + "urrounds a large building with a gigantic wooden wheel attach"
  + "ed to it. South you see a small log cabin and north is a path"
  + " leading to some fields.");

  add_exit ("west", ROOM_PATH + "road7.c");
  add_exit ("south", ROOM_PATH + "road9.c");
  add_exit ("gate", ROOM_PATH + "gate.c");

  add_item ("building",
    "The building looks somewhat like a barn, except for the wheel "
  + "on the side. There is a set of double door on the side facing"
  + " you, the east side.\n");

  add_item ("fence",
    "The fence is looks pretty old and in dis"
  + "repair. This matters little since it is only about 1 meter hi"
  + "gh and wouldn't serve to keep very many people out. The gate "
  + "is closed, but unlocked.\n");

  add_sound ("The sound of rushing water comes from the east.");
  add_sound ("Your feet sink into the ground a little.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
