// DATE        : Mon Nov  3 21:21:46 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Drunken Dragon's Inn");
  set_long (
    "You're in the main room of the famous Drunken Dragon's Inn. Th"
  + "e people smile at you and a burst of cheers welcomes you as y"
  + "ou step in. All are having fun in here. There are several tab"
  + "les and chairs and few sofas. At the back of the room is a de"
  + "sk for ordering drinks and food, the roasted boar is famous a"
  + "nd the scent of roasted meat fills the air. A fireplace is on"
  + " one wall, the roaring fire in it giving a cosy feeling. A do"
  + "or leads east out of the inn. In north there is a room for on"
  + "es who don't like the noise and want to eat in peace. Stairs "
  + "lead upstairs to the rent rooms.");

  add_exit ("east", ROOM_PATH + "innyard.c");
  add_exit ("north", ROOM_PATH + "inn2.c");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
