// DATE        : Mon Jan 19 01:02:49 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("farmers");
  add_object(MONSTER_PATH+"barliman.c");
  set_short ("Rear of the Mill");
  set_long (
    "This is the back end of the mill. There is large set of double"
  + " doors on the east wall, through which numerous pipes leave. "
  + "They are attached to the walls and come from inside the mill."
  + " The rest of the room is empty except for the tools and pipe "
  + "sections spread all about.");

  add_exit ("west", ROOM_PATH + "mill3.c");

  add_item ("door doors",
    "The huge double doors are open, through which the pipes make t"
  + "heir way to the various farmlands.\n");

  add_item ("tool tools",
    "There are various tools, l"
  + "ike wrenches and screwdrivers, scattered about the room.\n");

  add_item ("pipe pipes sections",
    "The "
  + "pipes are too numerous to count. The line the walls and the e"
  + "dges of the floor. You can hear the sound of rushing water co"
  + "mming from inside them.\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
