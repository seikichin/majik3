// DATE        : Sun Dec 28 01:58:28 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Sideroom");
  set_long (
    "This small room has no furniture at all. A small window lets f"
  + "rest air into the room and a single candle on the window sill"
  + " is the only light source in this shadowy room. Narrow stairs"
  + " lead upstairs and a door leads north.");

  add_exit ("up", ROOM_PATH + "questa8.c");
  add_exit ("north", ROOM_PATH + "queswan.c");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
