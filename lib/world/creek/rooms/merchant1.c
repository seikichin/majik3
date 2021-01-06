// DATE        : Sun Nov  2 23:04:38 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Merchant street");
  set_long (
    "You're walking along Merchant street. The most of the city's s"
  + "hops are located here. The city smithy is in west. An irritat"
  + "ingly loud banging comes from that direction. In the east you"
  + " can see Armourer's sign. A short street leads north where th"
  + "e Candle street begins. The city wall blocks your way in sout"
  + "h.");

  add_exit ("north", ROOM_PATH + "candle7.c");
  add_exit ("east", ROOM_PATH + "merchant3.c");
  add_exit ("west", ROOM_PATH + "merchant2.c");

  add_object (MONSTER_PATH + "citizen");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
