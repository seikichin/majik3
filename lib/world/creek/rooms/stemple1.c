// DATE        : Mon Nov  3 22:07:13 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Southern Temple street");
  set_long (
    "You're walking along the Southern Temple street which continue"
  + "s to the east and west. In the east a short street leads to M"
  + "erchant street where many of the city's shops are located. Ba"
  + "nging of hammer on anvil echoes from the smithy in south of y"
  + "ou.");

  add_exit ("west", ROOM_PATH + "stemple6.c");
  add_exit ("east", ROOM_PATH + "candle4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
