// DATE        : Sun Jan 25 22:42:27 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Study room");
  set_long (
    "You have entered what appears to be a study room. There are ta"
  + "bles and chairs set all around the room with a lamp at each o"
  + "ne. The walls are made of obsidian and are plain except for t"
  + "he three windows on the west wall. An archway is the only exi"
  + "t which leads east.");

  add_exit ("east", ROOM_PATH + "unihall1.c");

  add_item ("window windows",
    "You take a peak out of one of the windows and see a huge flat "
  + "plain outside. In the distance you can see a few farm plots a"
  + "nd some people moving this way and that.\n");

  add_item ("table tables chairs chair",
    "The tables and chair"
  + "s are made of solid oak. There are about fifteen or so tables"
  + " with two to four chairs at each. They are all polished and b"
  + "uffed to an immaculate shine.\n");

  add_item ("lamp lamps",
    "The lamps are small and made of"
  + " copper. The is one set at each table, but a few are not lit."
  + "\n");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
