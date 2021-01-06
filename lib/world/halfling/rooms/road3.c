// DATE        : Fri Jan 16 17:41:30 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Fisherman's Lane");
  set_long (
    "You are at the south end of Fisherman's Lane. The dirt roadgra"
  + "dually turns into the grassy plains beyond. There is a large "
  + "building to the northeast. To the west is a molehill with a b"
  + "urrow built into the side. Just to the north of the burrow is"
  + " a small garden.");

  add_exit ("west", ROOM_PATH + "yard.c");
  add_exit ("north", ROOM_PATH + "road2.c");

  add_item ("burrow molehill",
    "There is a molehill to your west. There is a dirt walkway, goi"
  + "ng through the front yard, which leads up to a wooden door. T"
  + "here are two circular windows on the left side of the door.\n");

  add_item ("building",
    "T"
  + "he building to the northeast is quite a large structure. It i"
  + "s made completly of wood and you can barely make out a sign n"
  + "ext to the door.\n");

  add_item ("garden",
    "There is a small garden to the northwest wit"
  + "h a white picket fence surrounding it.\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
