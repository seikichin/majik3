// DATE        : Sun Feb 22 16:25:53 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Under a treemansion");
  set_long (
    "You're standing before a tall tree which supports the weight o"
  + "f an elven treemansion on its crown. Dainty stairs spiral up "
  + "to its doors. In the east lies Falan's way which runs through"
  + " Endalen, the part of the city where the nobility lives.");

  add_exit ("east", ROOM_PATH + "falan2.c");
  add_exit ("up", ROOM_PATH + "mansfront.c");

  add_sound ("You can hear people hurrying on the street in east.");
  add_sound ("A paradise bird flies to rest on the treetop.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
