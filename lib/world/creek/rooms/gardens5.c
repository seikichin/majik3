// DATE        : Mon Nov  3 21:13:39 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Hall of Gathering");
  set_long (
    "This is where the knights of Ivory gather when they have their"
  + " meetings. It is a big hall and at the center of it is a long"
  + " table. There are eight seats around it. At the other end of "
  + "the hall is a flaming fireplace. A crystal chandelier gives l"
  + "ight to the hall. Doors lead north, east and south.");

  add_exit ("east", ROOM_PATH + "gardens1.c");
  add_exit ("south", ROOM_PATH + "gardens7.c");
  add_exit ("north", ROOM_PATH + "gardens4.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
