// DATE        : Mon Nov  3 20:48:54 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A guardhouse at the west gate");
  set_long (
    "The room has only the furniture that is needed. A bed for the "
  + "guard who is not in duty and a table for the others so that t"
  + "hey can play cards on a rainy day. More than few empty bottle"
  + "s of whisky are scattered around the room giving it a rather "
  + "messy feeling.");

  add_exit ("north", ROOM_PATH + "underwgate.c");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
