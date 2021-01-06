// DATE        : Sun Nov  2 21:58:02 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Candle street, at the Town Hall");
  set_long (
    "You're walking on Candle street which runs in north south dire"
  + "ction. The doors to the Town Hall of Silvercreek are in the w"
  + "est where you can enter the building. Candle street leads nor"
  + "th and south where the Temple square is located. A short stre"
  + "et in south leads east to the marketplace.");

  add_exit ("south", ROOM_PATH + "candle5.c");
  add_exit ("north", ROOM_PATH + "arcane4.c");
  add_exit ("west", ROOM_PATH + "townhall1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
