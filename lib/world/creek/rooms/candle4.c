// DATE        : Sun Nov  2 20:45:19 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the crossing of Candle street and Southern Temple street");
  set_long (
    "You're at the crossing of Candle street and Southern Temple st"
  + "reet. The Temple street continues further to the west and eas"
  + "t and the Candle street to the north towards the Temple Squar"
  + "e and south to the Merchant street. You can hear the banging "
  + "of hammer on anvil from the south where a plume of smoke can "
  + "be seen raising from the Smithy.");

  add_exit ("south", ROOM_PATH + "candle7.c");
  add_exit ("north", ROOM_PATH + "candle2.c");
  add_exit ("east", ROOM_PATH + "stemple5.c");
  add_exit ("west", ROOM_PATH + "stemple1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
