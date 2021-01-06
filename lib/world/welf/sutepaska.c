// DATE        : Thu Nov  6 19:08:38 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("An underwater cave");
  set_long (
    "You are in an underwater cave. The crystal clear water allows "
  + "you to see perfectly. The water is icy cold and refreshing bu"
  + "t it makes your limbs numb and saps your strength all the tim"
  + "e you remain here. You can see light coming from above, but t"
  + "here's also a small hole near the bottom in south.");

  add_exit ("south", ROOM_PATH + "undertunnel.c");
  add_exit ("up", ROOM_PATH + "glittercave.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
