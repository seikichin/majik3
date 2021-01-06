// DATE        : Sun Nov  2 21:53:47 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The crossing of Arcane and Candle streets");
  set_long (
    "You're at the crossing of Arcane street and Candle street. Arc"
  + "ane street leads west and Candle street leads south towards t"
  + "he Temple square. The city walls rise before you in north. Th"
  + "e massive building of the Academy of Magic is in the east, bl"
  + "ocking the view there. The doors of the town hall are in the "
  + "south.");

  add_exit ("south", ROOM_PATH + "candle6.c");
  add_exit ("west", ROOM_PATH + "arcane3.c");

  add_object (MONSTER_PATH + "citizen");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
