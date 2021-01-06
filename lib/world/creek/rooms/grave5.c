// DATE        : Sun Nov  2 21:08:38 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Grave street");
  set_long (
    "You're now walking along the Grave street which runs in north "
  + "south direction. The Grave street joins the Blood Alley in so"
  + "uth and the Southern Temple street in north. Some cheers and "
  + "merrymaking echo from the building in east.");

  add_exit ("south", ROOM_PATH + "grave4.c");
  add_exit ("north", ROOM_PATH + "grave3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
