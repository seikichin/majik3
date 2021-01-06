// DATE        : Sun Nov 23 08:00:58 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Staircase");
  set_long (
    "You are on a huge stair case. It is about as wide as ten you y"
  + "our body widths. You are surrounded by the strange blue walls"
  + " and there is a single, triangular window here. The staircase"
  + " continues up and down. There is also a single torch here on "
  + "the wall.");

  add_exit ("up", ROOM_PATH + "top.c");
  add_exit ("west", ROOM_PATH + "globby.c");
  add_exit ("down", ROOM_PATH + "enter.c");

  add_item ("window",
    "You look out the window and get a fantastic view of the landsc"
  + "ape outside. The tower is pearched high on a mountain peak an"
  + "d you can see for miles around. You are so high that you are "
  + "almost in the cloud line.\n");

  add_item ("torch",
    "The torch is attached to the wall b"
  + "y a metal holdster. It is lit, but does not seem to be consum"
  + "ed by the fire.\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
