// DATE        : Sun Nov  2 21:51:19 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The crossing of Arcane and Gold streets");
  set_long (
    "You've arrived to the crossing of Arcane and Gold. The Arcane "
  + "street leads east and west while Gold street leads south to t"
  + "he bank doors. The city walls rise before you in the north. T"
  + "he massive building of the Academy of Magic is in the east at"
  + " the end of the street.");

  add_exit ("south", ROOM_PATH + "gold2.c");
  add_exit ("east", ROOM_PATH + "arcane2.c");
  add_exit ("west", ROOM_PATH + "arcane5.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
