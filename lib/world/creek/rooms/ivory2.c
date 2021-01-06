// DATE        : Thu Nov  6 19:37:01 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Ivory street, entrance to the Ivory Halls");
  set_long (
    "You've arrived to the doors of the Ivory Gardens, where the no"
  + "bles of Silvercreek gather to discuss of the matters of safet"
  + "y. The building itself is a sight indeed. Its walls are made "
  + "from some white stone that glitters and sparkles in sunlight "
  + "and glows softly in moonlight. The nobles of Silvercreek are "
  + "known to be fanatic worshippers of the god of justice and the"
  + "y have constant quarrels with the local ruffians who have mad"
  + "e their home near the west gate. The doors of the Ivory Garde"
  + "ns are in the west. The Ivory street leads north and south.");

  add_exit ("west", ROOM_PATH + "gardens1.c");
  add_exit ("south", ROOM_PATH + "ivory1.c");
  add_exit ("north", ROOM_PATH + "ivory3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
