// DATE        : Sun Nov  2 22:32:20 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Grave street");
  set_long (
    "You're now walking on Grave street which connects the two Temp"
  + "le streets in north-south direction. Grave street leads north"
  + " and south from here. You can see the city cemetary over the "
  + "fence in east. A short street leads west in south. A chapel c"
  + "an be seen in the cemetary south east from here.");

  add_exit ("south", ROOM_PATH + "grave2.c");
  add_exit ("north", ROOM_PATH + "grave1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
