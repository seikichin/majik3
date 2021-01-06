// DATE        : Sun Dec 28 01:41:59 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Elegantly decorated room");
  set_long (
    "You're standing in a elegantly decorated bedroom. Marvellous a"
  + "nd very old looking paintings hang on the walls. A very comfo"
  + "rtable looking bed has been placed near the window on north w"
  + "all. A table, chair and a chest of drawers are the rest of th"
  + "e furniture here. A door leads south.");

  add_exit ("south", ROOM_PATH + "queha1.c");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
