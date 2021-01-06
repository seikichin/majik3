// DATE        : Wed Oct 29 11:58:54 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A narrow ropebridge between the treetops");
  set_long (
    "As you walk on the narrow ropebridge it starts to sway from side to"
  + " side forcing you to tighten your grip on the ropes. Below, you ca"
  + "n see the holy swantemple and the four totems. The bridge continue"
  + "s to east and west to some kind of platforms.");

  add_exit ("east", ROOM_PATH + "treetop3.c");
  add_exit ("west", ROOM_PATH + "treetop4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
