// DATE        : Mon Nov  3 21:38:05 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A back room");
  set_long (
    "A small shadowy place, more suspicious than the main room you "
  + "have to admit. Small table at the center of the room and two "
  + "sofas around it. A flaming fireplace on one wall. This room h"
  + "as sorta tense feeling. You constantly look behind you to mak"
  + "e sure none will stab you. A door leads south.");

  add_exit ("south", ROOM_PATH + "den1.c");
  add_object (MONSTER_PATH + "hypocrisy");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
