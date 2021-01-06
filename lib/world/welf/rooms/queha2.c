// DATE        : Thu Mar 12 21:13:38 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Long hall");
  set_long (
    "The long hallway you're standing in runs in east-west directio"
  + "n. The floor is covered with a long green carpet. Few dimly g"
  + "lowing crystals are attached to the walls on either side and "
  + "provide some light to the hallway. There's a large mosaic win"
  + "dow at the both ends of the hallway.");

  add_exit ("west", ROOM_PATH + "questa5.c");
  add_exit ("north", ROOM_PATH + "quero3.c");
  add_exit ("east", ROOM_PATH + "queha3.c");

  add_item ("crystal crystals",
    "The crystals glow dimly with green light. They seem to be firm"
  + "ly attached to the wall.\n");

  add_item ("window mosaic",
    "Really nice pieces of mosaic. The li"
  + "ght shining through the windows is filtered in a hundred diff"
  + "erent shades.\n");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
