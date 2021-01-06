// DATE        : Fri Nov  7 22:44:18 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Market Road");
  set_long (
    "You are on a dirt road heading east and west. To the north and"
  + " south are huts. You can see and intersection to the west and"
  + " some more buildings to the east.");

  add_exit ("east", ROOM_PATH + "road5.c");
  add_exit ("west", ROOM_PATH + "intersection.c");
  add_door ("north", ROOM_PATH + "bank", "door", "wooden", 0, 0, 0);  

  set_outdoors(4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

