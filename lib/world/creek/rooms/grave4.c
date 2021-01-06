// DATE        : Sun Nov  2 21:08:53 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The crossing of Grave street and Blood alley");
  set_long (
    "You're now standing at the crossing of Grave street and Blood "
  + "alley. Grave street leads north towards the city cemetary and"
  + " Blood alley leads west. The noise coming from the nearest tw"
  + "o building is loud enough to give you a headache. In your oth"
  + "er side is an Inn building and on the other side a Tavern. In"
  + " south the city walls rise before you.");

  add_exit ("north", ROOM_PATH + "grave5.c");
  add_exit ("west", ROOM_PATH + "blood1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
