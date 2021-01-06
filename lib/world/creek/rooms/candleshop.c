// DATE        : Sat Nov  1 23:46:10 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Ye Candlemaker's Shop");
  set_long (
    "The floor boards creak nastily as you enter the room. Time see"
  + "ms to have stopped in here. The air is perfectly still, not a"
  + " slightest sign of a breeze or a gust of air. The room itself"
  + " is quite dusty, filled with old shelves full of candles and "
  + "lamps. A door leads west to the streets.");

  add_exit ("west", ROOM_PATH + "candle2.c");

  add_object (MONSTER_PATH + "cravina");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
