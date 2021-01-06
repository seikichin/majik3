// DATE        : Mon Nov  3 20:42:18 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A hallway");
  set_long (
    "This terribly long hallway leads east to the entrance hall and"
  + " to west where the library of Academy is. On both sides of th"
  + "e hallway are rooms for young students who want to learn the "
  + "art. A door leads east to the entrance hall.");

  add_exit ("east", ROOM_PATH + "acadent.c");
  add_exit ("west", ROOM_PATH + "hallway1.c");
  add_object (MONSTER_PATH + "student");
}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
