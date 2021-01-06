// DATE        : Tue Jan  6 13:03:16 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("On the bridge");
  set_long (
    "The river flows loudly below you as you stand on the wooden br"
  + "idge. A large building is to your west and a green pasture ar"
  + "ea enclosed by a fence is to the east.");

  add_exit ("east", ROOM_PATH + "mill1.c");
  add_exit ("west", ROOM_PATH + "gate.c");

  add_item ("pasture",
    "The pasture is covered with fresh, green grass.\n");

  add_item ("bridge",
    "A nicely done "
  + "bridge, complete with handrails on each side. It looks old, y"
  + "et sturdy.\n");

  add_item ("river",
    "The water is clear and clean. It flows quickly ove"
  + "r the many rocks on the bottom.\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
