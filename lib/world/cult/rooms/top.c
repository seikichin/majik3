// DATE        : Tue Nov 11 22:40:20 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Pinnacle of the Tower");
  set_long (
    "You have reached the pinnacle of the tower. To your surpise th"
  + "ere is no roof here. There are four walls, but the top is com"
  + "pletly open to the elements. In the center of the room is a t"
  + "riangular table made of the same stone as the tower. On the s"
  + "outhern side of the room, the staircase is built right into t"
  + "he floor and is the only exit short of flying out the top.");

  add_exit ("down", ROOM_PATH + "stair1.c");

  add_item ("stairs staircase",
    "The stairs are built right into the floor. There isn't a door "
  + "and any other cover, you simply walk right down or up.\n");

  add_item ("table triangle",
    "The tr"
  + "iangular table has 3 equal sides that are about 20 feet long "
  + "each. On the top of the table is a huge depiction of a magnif"
  + "icigant dragon.\n");

  add_item ("wall walls",
    "The walls are made of a strange material, con"
  + "sistent with the rest of the tower. They rise up approximatly"
  + " 15 feet from the floor and have sections that rise up 2 feet"
  + " higher, spaced about 4 feet apart.\n");

  set_outdoors (4);

  add_object (ITEM_PATH + "cult_board.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

