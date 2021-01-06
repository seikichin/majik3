// DATE        : Sun Nov  2 20:30:13 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marketplace");
  set_long (
    "The Market place is terribly crowded. People push you aside as"
  + " they hurry by you to the nearest booth in east. The Market p"
  + "lace continues to the east, south and north. The massive buil"
  + "ding of the Academy of Magic is in the north casting a shadow"
  + " over the whole Market place. In the south you can see the Ci"
  + "ty Guard Headquarters. A short alley leads west.");

  add_exit ("south", ROOM_PATH + "marketp6.c");
  add_exit ("north", ROOM_PATH + "marketp9.c");
  add_exit ("east", ROOM_PATH + "marketp5.c");
  add_exit ("west", ROOM_PATH + "tomarket.c");

  add_object (MONSTER_PATH + "lady");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
