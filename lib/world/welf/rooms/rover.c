// DATE        : Sun Jan 18 19:52:30 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Ropebridge over the river");
  set_long (
    "The ropebridge is long and narrow and it sways from side to si"
  + "de as you make your way towards the treetop on the other side"
  + " of the river. You stop  to watch the sparkling river below a"
  + "nd notice a perfect swimming place some distance in south whe"
  + "re the river gets wider and the current weaker. The ropebridg"
  + "e leads east and west.");

  add_exit ("west", ROOM_PATH + "rtreetop1.c");
  add_exit ("east", ROOM_PATH + "rtreetop2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
