// DATE        : Sun Nov  2 21:34:53 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Bazaar");
  set_long (
    "You're now near the west gate of Silvercreek. The surrounding "
  + "area has quite a bad reputation, being the place where most o"
  + "f the crimes in city are committed. The square before the gat"
  + "e is some kind of a bazaar. Some tricksters and ruffians are "
  + "trying to earn their bread nearby, fooling some unfortunate t"
  + "ravellers. Some distance in south you can see a tavern. Ivory"
  + " street leads north from here and a short alley leads east to"
  + " Grave street. You can see the doors of the Ivory Halls a s"
  + "hort distance in north.");

  add_exit ("south", ROOM_PATH + "bazaar2.c");
  add_exit ("north", ROOM_PATH + "ivory1.c");
  add_exit ("east", ROOM_PATH + "tobaz.c");
  add_exit ("west", ROOM_PATH + "bazaar3.c");

  add_object (MONSTER_PATH + "dog");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
