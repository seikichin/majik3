// DATE        : Mon Dec 29 15:57:21 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Orchard");
  set_long (
    "Apple and plumtrees around you are in full blossom and the stu"
  + "nningly strong sweet smell of their flowers makes you sneeze "
  + "as you inhale the forest air. The orchard continues in north "
  + "and west.");

  add_exit ("north", ROOM_PATH + "orchard1.c");
  add_exit ("west", ROOM_PATH + "orchard3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
