// DATE        : Sun Nov  2 21:58:32 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Candle street, at a short alley");
  set_long (
    "You're now stanging at a T-crossing where the Candle street co"
  + "ntinues to the north and south and a short street leads to th"
  + "e Market place. Loud arguing and haggling about the prices ca"
  + "n be heard from there. In the north you can see the doors of "
  + "the Town Hall.");

  add_exit ("south", ROOM_PATH + "candle3.c");
  add_exit ("north", ROOM_PATH + "candle6.c");
  add_exit ("east", ROOM_PATH + "tomarket.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
