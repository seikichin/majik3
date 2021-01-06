// DATE        : Sun Nov  2 20:39:03 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marketplace, the northeast corner");
  set_long (
    "You're in the northeast corner of the Market place. The massiv"
  + "e building of the Academy of Magic blocks the view in east an"
  + "d north. A side door leads into the academy in east. The main"
  + " entrance to the academy is in the west. The Market place str"
  + "etches to the south and west.");

  add_exit ("south", ROOM_PATH + "marketp3.c");
  add_exit ("east", ROOM_PATH + "class.c");
  add_exit ("west", ROOM_PATH + "marketp11.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
