// DATE        : Mon Jan  5 16:24:29 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Rear of the Mill");
  set_long (
    "This is the back end of the mill. There is large set of double"
  + " doors on the east wall, through which numerous pipes leave. "
  + "They are attached to the walls and come from inside the mill."
  + " The rest of the room is empty except for the tools and pipe "
  + "sections spread all about.");

  add_exit ("west", ROOM_PATH + "mill3.c");

  add_object ( MONSTER_PATH + "barliman.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

