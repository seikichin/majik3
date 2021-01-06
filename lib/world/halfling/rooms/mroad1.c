// DATE        : Mon Nov  3 22:41:17 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("market");
  set_short ("West side of Market Road");
  set_long (
    "You are on Market Road, west of the intersection. It is a plai"
  + "n dirt road and it is surrounded by rolling, grassy plains. I"
  + "t continues on to the east and west. East leads to an interse"
  + "ction while west goes out of the Shire.  There is a hut to th"
  + "e south.\n");

  add_exit ("west", ROOM_PATH + "mroad2.c");
  add_exit ("east", ROOM_PATH + "intersection.c");
  add_exit ("south", ROOM_PATH + "guild1.c");

  set_outdoors(4);

  add_item ("plains",
    "The plains go on for miles. As far as you can see.\n");
  add_item ("hut",
    "The hut is a little large and is well constructed. There is a"
  + " symbol of a wooden cart over the entrance.\n");

  add_monster(MONSTER_PATH + "barcos.c");
  add_object(ITEM_PATH + "cart.c");
  add_monster(MONSTER_PATH + "bertha.c");

}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

