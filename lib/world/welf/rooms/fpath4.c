// DATE        : Tue Feb 10 20:51:53 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Forest");
  set_long (
    "You're in the Sol'daran forest that surrounds the splendid cit"
  + "y of tanir. A well trodden path leads north and south. Tall m"
  + "ajestetic pines stand on the both sides of the path and behin"
  + "d them the forest becomes thicker. A barely visible trail lea"
  + "ds east through a thick bushwall towards the river.");

  add_exit ("south", ROOM_PATH + "fpath3.c");
  add_exit ("north", ROOM_PATH + "fpath5.c");
  add_exit ("east", ROOM_PATH + "swangrove.c");

  add_sound ("You can hear the swans singing in the east.");
  add_sound ("You think you heard someone chanting softly...");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
