// DATE        : Tue Jan  6 13:00:10 1998
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
  + "ed to it.");

  add_exit ("gate", ROOM_PATH + "gate.c");
  add_exit ("west", ROOM_PATH + "road7.c");

  add_item ("fence",
    "The fence is looks pretty old and in disrepair. This matters l"
  + "ittle since it is only about 1 meter high and wouldn't serve "
  + "to keep very many people out. The gate is closed, but unlocke"
  + "d.\n");

  add_item ("building",
    "The building looks somewhat like a barn, except for the wh"
  + "eel on the side. There is a set of double door on the side fa"
  + "cing you, the east side.\n");

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
