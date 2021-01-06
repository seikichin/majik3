// DATE        : Sat Nov  1 21:57:46 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A short street block on the Candlemaker's street");
  set_long (
    "A cobblestoned street running north and south from the Temple "
  + "Square. It has been named after the famous Candlemaker's shop"
  + " south from the Temple Square. The old witch Cravina sells no"
  + "t only ordinary light sources but some majikal as well. A sma"
  + "ll candle lamp swaying on the wall of the nearest building gi"
  + "ves the street some light during the night time. The street c"
  + "ontinues to the north and in the south you can see the Temple"
  + " Square.");

  add_exit ("south", ROOM_PATH + "templesq.c");
  add_exit ("north", ROOM_PATH + "candle3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
