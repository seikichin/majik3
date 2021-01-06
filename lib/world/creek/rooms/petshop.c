// DATE        : Sun Nov  2 23:28:57 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A petshop");
  set_long (
    "You're in a room full of cages and animals. The animals are ne"
  + "rvous and make an annoying noise, irritatingly loud. A travel"
  + "ling companion would be nice though, now that you think of it"
  + ". Maybe you should buy a pet. Above the desk is hanging a sig"
  + "n. A door leads west to the streets.");

  add_exit ("west", ROOM_PATH + "merchant6.c");
  add_object (MONSTER_PATH + "akeem");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
