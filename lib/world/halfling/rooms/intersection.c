// DATE        : Sat Nov  1 21:53:34 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("shire");
  set_short ("Intersection of Fisherman's Lane and Market Road");
  set_long (
    "You stand at the meeting of two roads. Fisherman's Lane goes n"
  + "orth and south while Market Road goes east and west. This see"
  + "ms to be the center of the village as you can seen halfling h"
  + "uts and burrows all around. To the west there are also many c"
  + "arts that look like merchant stands.");

  add_exit ("south", ROOM_PATH + "road2.c");
  add_exit ("north", ROOM_PATH + "road1.c");
  add_exit ("east", ROOM_PATH + "road4.c");
  add_exit ("west", ROOM_PATH + "mroad1.c");

  set_outdoors(4);

  add_item ("huts burrows",
    "There are huts and burrows all around you but, they are mainly"
  + " along the road to the north and south.\n");

  add_sound ("You rub your eyes as some dust from the road is blown into them.");

  add_monster (MONSTER_PATH + "rano.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

