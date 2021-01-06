// DATE        : Mon Jan  5 12:57:15 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Enterance to the Mill");
  set_long (
    "Here is the entrnace to the mill. There is a set a double door"
  + "s on the east wall. The room is huge and the roof is pretty h"
  + "igh up. It runs lengthwise away from the doors and deeper int"
  + "o the building. Near the north wall there is a counter. Other"
  + " than that this area is filled with various things, mostly in"
  + " boxes or containers.");

  add_exit ("east", ROOM_PATH + "mill3.c");
  add_exit ("out", ROOM_PATH + "mill1.c");

  add_item ("counter",
    "The counter has a stool behind it and looks to be a reception "
  + "desk or some sort, however, there is no one behind it. It is "
  + "small, about 1.5 meters wide and less than 1 meter tall.\n");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
