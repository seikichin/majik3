// DATE        : Mon Nov  3 20:47:24 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A lecture room");
  set_long (
    "You're in a small lecture room in the Academy of Magic. This r"
  + "oom is used to teach the young spell students the needed theo"
  + "ries while casting the spells. Ten seats and desks are neatly"
  + " in two lines before the teaching magicians desk. A chalk boa"
  + "rd is placed on the east wall. Doors lead north and west.");

  add_exit ("west", ROOM_PATH + "marketp12.c");
  add_exit ("north", ROOM_PATH + "tower1.c");
  add_object (MONSTER_PATH + "student");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
