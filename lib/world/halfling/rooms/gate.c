// DATE        : Mon Jan  5 15:21:20 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Inside the fence");
  set_long (
    "You are surrounded by a shabby wooden fence on three sides. To"
  + " the east of you, however, there is a moderately sized river "
  + "and bridge to cross it. There is a gate leading out and the b"
  + "ridge takes you to wooden building beyond.");

  add_exit ("east", ROOM_PATH + "bridge.c");
  add_exit ("gate", ROOM_PATH + "road8.c");

  add_item ("river",
    "The river is not overly large or deep. It does seem to be flow"
  + "ing fairly rapidly.\n");

  add_item ("building",
    "The building is just beyond the bridge. I"
  + "t appears to be a workplace of somekind. The river flows very"
  + " near is southern side and is turning the great wheel there. "
  + "Plus, you notice some wisps of black smoke coming from a ston"
  + "e chimney on top.\n");

  add_item ("fence",
    "The fence is looks pretty old and in disrep"
  + "air. This matters little since it is only about 1 meter high "
  + "and wouldn't serve to keep very many people out. The gate is "
  + "closed, but unlocked.\n");

  add_item ("bridge",
    "The bridge is made of wood and some sto"
  + "ne supports. It looks very sturdy and safe to cross. There ar"
  + "e also handrails on each side.\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
