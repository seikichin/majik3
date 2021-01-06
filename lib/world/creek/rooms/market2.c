// DATE        : Sat Nov  1 23:34:17 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("On Market street");
  set_long (
    "You're standing on Market street which runs south from the Mar"
  + "ket place to Merchant street where the most of the city's sho"
  + "ps are located. The street continues to the north and south. "
  + "You can hear the shopkeepers yell their prices. The loud bang"
  + "ing of hammer on anvil comes from the south west.");

  add_exit ("south", ROOM_PATH + "market3.c");
  add_exit ("north", ROOM_PATH + "majik2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
