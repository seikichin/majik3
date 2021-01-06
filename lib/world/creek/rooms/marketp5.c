// DATE        : Mon Nov 17 19:29:42 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marketplace, the mushie booth");
  set_long (
    "You push your way to the nearest booth in the crowded market p"
  + "lace. An old shaman has come here to sell his precious mushro"
  + "oms. His booth is just about to fall. Smell of mushrooms surr"
  + "ounds the nearby area and the people around the booth all see"
  + "m to giggle and laugh as they walk by. The market place conti"
  + "nues to all four directions. In the north the massive Academy"
  + " building dominates the view. In the east there is a curious "
  + "looking booth.");

  add_exit ("west", ROOM_PATH + "marketp7.c");
  add_exit ("south", ROOM_PATH + "marketp1.c");
  add_exit ("north", ROOM_PATH + "marketp10.c");
  add_exit ("east", ROOM_PATH + "marketp8.c");

  add_object (MONSTER_PATH + "cityguard");
  add_object (MONSTER_PATH + "shaman");
  add_object (MONSTER_PATH + "minstrel");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
