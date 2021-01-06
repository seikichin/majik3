// DATE        : Thu Mar 12 21:08:14 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Long hall");
  set_long (
    "You're standing at the west end of a long hallway. A long gree"
  + "n carpet covers the whole lenght of the floor. Few dimly glow"
  + "ing crystals have been attached to the walls on either sides "
  + "and a large colorstained window gives a magnificent, yet a li"
  + "ttle obscured view over the surrounding forest.");

  add_exit ("north", ROOM_PATH + "quero1.c");
  add_exit ("east", ROOM_PATH + "questa5.c");

  add_item ("window",
    "It's a large piece of mosaic that filters the light in myriad "
  + "shades.\n");

  add_item ("crystals crystal",
    "Small crystals that glow dimly with green light. They"
  + " seem to be firmly attached to the walls.\n");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
