// DATE        : Sun Nov  2 23:33:42 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A guardhouse at the east gate");
  set_long (
    "This room has only the furniture that is needed. A bed for the"
  + " guard who is not in duty and a table for the others so that "
  + "they can play cards on a rainy day. A small lamp gives the ro"
  + "om some light. Doors lead north and south.");

  add_exit ("south", ROOM_PATH + "underseg.c");
  add_exit ("north", ROOM_PATH + "underneg.c");

  set_light (1);
}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
