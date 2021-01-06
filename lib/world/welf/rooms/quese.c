// DATE        : Sun Dec 28 00:49:00 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Servants' room");
  set_long (
    "This room is rather simple compared to the other rooms in the "
  + "treepalace, but it has the same mixed feeling of homeliness a"
  + "nd magic as the rest of Sol'daran's forest realm. A cosy look"
  + "ing sofa, small round table and a couble of stools are the on"
  + "ly furniture in here. Doors lead west and north from here.");

  add_exit ("north", ROOM_PATH + "queseq.c");
  add_exit ("west", ROOM_PATH + "questa1.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
