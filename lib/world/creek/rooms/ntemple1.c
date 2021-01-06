// DATE        : Sun Nov  2 19:09:54 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Northern Temple street");
  set_long (
    "You're standing on the Northern Temple street. South from here"
  + " you can see the city cemetary over the fence. The adamantite"
  + " fence will keep the animals away, and the holy symbols engra"
  + "ved on it will stand against any evil intent towards the dead"
  + ". The street continues to the east and west.");

  add_exit ("east", ROOM_PATH + "ntemple2.c");
  add_exit ("west", ROOM_PATH + "ntemple3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
