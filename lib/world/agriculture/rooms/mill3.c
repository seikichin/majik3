// DATE        : Mon Jan 19 01:06:25 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Inside the Mill");
  set_long (
    "This is the center of the mill. Next to the south wall is a hu"
  + "ge contraption. The wall behind it has some openings, in whic"
  + "h belts and pulleys go through to the outside. To the north i"
  + "s a large archway leading to another room.");

  add_exit ("east", ROOM_PATH + "mill4.c");
  add_exit ("west", ROOM_PATH + "mill2.c");
  add_exit ("north", ROOM_PATH + "hshop.c");

  add_item ("contraption",
    "The contraption is attached to the belts and pulleys which see"
  + "m to be providing it with some power. The machine creaks and "
  + "groans as it runs and occasionally a huge gust of steam comes"
  + " billowing out.\n");

  set_light (1);
  set_outdoors (0);
}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
