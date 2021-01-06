// DATE        : Sat Nov  1 22:00:25 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("By the Candlemaker's Shop");
  set_long (
    "A cobblestoned street running north and south from the Temple "
  + "Square. It has been named after the famous Candlemaker's shop"
  + " just east from here. The old witch Cravina sells not only or"
  + "dinary light sources but some majikal as well. A small candle"
  + " lamp swaying on the wall of the nearest building gives the s"
  + "treet some light during the night time. The street continues "
  + "to the south and in the north you can see the Temple Square. "
  + "A Sign is hanging above the Candlemaker's door.");

  add_exit ("south", ROOM_PATH + "candle4.c");
  add_exit ("north", ROOM_PATH + "templesq.c");
  add_exit ("east", ROOM_PATH + "candleshop.c");

  add_item ("sign door",
    "Above the door is hanging a sign. It says:\n            ()     "
  + "                  ()\n           ()                         ()"
  + "\n         ,(----------------------------(-.\n         |   Ye C"
  + "andlemaker's Shop       |\n         |      Cravina Ellyandra  "
  + "      |\n         |      Open: All night          |\n         `"
  + "-------------------------------'\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
