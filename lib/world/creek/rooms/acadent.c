// DATE        : Mon Nov  3 20:43:45 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("An enormous entrance hall");
  set_long (
    "This hall is enormous. Looking up at the domed ceiling makes y"
  + "ou feel dizzy. Your steps echo louder and louder as you walk "
  + "through the hall. Some majikal runes have been carved to the "
  + "doors and doorframes and the walls are full of strange symbol"
  + "s and wards. The atmosphere here is tense. You can feel the p"
  + "ure essence of magic surrounding you, it makes you feel more "
  + "than nervous. Doors lead east and west. The door out of the A"
  + "cademy is in south.");

  add_exit ("east", ROOM_PATH + "tower1.c");
  add_exit ("west", ROOM_PATH + "hallway2.c");
  add_exit ("south", ROOM_PATH + "marketp11.c");

  add_object (MONSTER_PATH + "student");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
