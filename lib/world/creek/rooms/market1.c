// DATE        : Sat Nov  1 23:24:33 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Market street");
  set_long (
    "Strange scents drift in from the north where the market place "
  + "is located. The cobble stoned street is filled with litter, t"
  + "he people just don't care about anything when they are not at"
  + " home. Some pigeons coo at the street corner picking up trash"
  + "es and trying to find pieces of bread an old lady just threw "
  + "on them. The street continues to the north and south.");

  add_exit ("south", ROOM_PATH + "majik2.c");
  add_exit ("north", ROOM_PATH + "marketp1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
