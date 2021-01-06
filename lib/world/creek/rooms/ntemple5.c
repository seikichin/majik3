// DATE        : Sun Nov  2 19:18:16 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The crossing of Northern Temple street and Chapel street");
  set_long (
    "You've arrived to the crossing of the Chapel street and Northe"
  + "rn Temple street where the Chapel street leads north and the "
  + "Temple street to the east and west. You can see a chapel in t"
  + "he north over the cemetary fence.");

  add_exit ("north", ROOM_PATH + "chapel1.c");
  add_exit ("east", ROOM_PATH + "ntemple4.c");
  add_exit ("west", ROOM_PATH + "grave1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
