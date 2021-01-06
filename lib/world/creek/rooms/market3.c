// DATE        : Sun Nov  2 00:12:13 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the crossing of Market and Southern Temple streets");
  set_long (
    "You're now at the crossing of Market and the Temple street. Th"
  + "e Market street continues to the north and south where it joi"
  + "ns the Merchant street. The Temple street stretches itself to"
  + " the east and west. A plume of smoke can be seen raising to t"
  + "he heavens some distance to the south west. A banging of hamm"
  + "er on anvil echoes also from that direction.");

  add_exit ("south", ROOM_PATH + "market4.c");
  add_exit ("north", ROOM_PATH + "market2.c");
  add_exit ("east", ROOM_PATH + "stemple4.c");
  add_exit ("west", ROOM_PATH + "stemple5.c");

  add_object (MONSTER_PATH + "lady");
  add_object (MONSTER_PATH + "citizen");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
