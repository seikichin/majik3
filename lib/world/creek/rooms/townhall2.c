// DATE        : Mon Nov  3 21:30:59 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Townhall of Silvercreek");
  set_long (
    "You've arrived to the common office in the town hall. This is "
  + "the room for leaving ideas about improving the city or just c"
  + "omplaining about something in Silvercreek. A small lamp is ha"
  + "nging from the ceiling illuminating the room. An important lo"
  + "oking officer is sitting behind the desk. A door leads east t"
  + "o the entrance hall.");

  add_exit ("east", ROOM_PATH + "townhall1.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
