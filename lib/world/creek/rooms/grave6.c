// DATE        : Sun Nov  2 22:40:35 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Grave street");
  set_long (
    "You're walking on Grave street which connects the two Temple s"
  + "treets in north-south direction. Grave street leads norh and "
  + "south. You can see the city cemetary over the fence in east. "
  + "A short street leads west in north. You can see a chap in the"
  + " cemetary north east from here.");

  add_exit ("south", ROOM_PATH + "grave3.c");
  add_exit ("north", ROOM_PATH + "grave2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
