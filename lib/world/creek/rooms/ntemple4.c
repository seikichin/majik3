// DATE        : Mon Nov  3 21:43:21 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Northern Temple street");
  set_long (
    "You're walking along the Northern Temple street which runs in "
  + "east-west direction. In the south you can see the city cemeta"
  + "ry over the adamantite fence. The building on your north side"
  + " is the bank of the city.");

  add_exit ("west", ROOM_PATH + "ntemple5.c");
  add_exit ("east", ROOM_PATH + "ntemple3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
