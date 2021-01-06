// DATE        : Sun Nov  2 19:15:16 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The crossing of Northern Temple street and Gold street");
  set_long (
    "You're now at the crossing of Gold and Northern Temple streets"
  + ". The Gold street leads north where the Bank is located and t"
  + "he Temple street continues to the east and west. You can hear"
  + " the counting of money from an open window in the nearby buil"
  + "ding.");

  add_exit ("north", ROOM_PATH + "gold1.c");
  add_exit ("east", ROOM_PATH + "ntemple1.c");
  add_exit ("west", ROOM_PATH + "ntemple4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
