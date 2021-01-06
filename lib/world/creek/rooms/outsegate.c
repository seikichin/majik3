// DATE        : Mon Nov  3 20:15:00 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Outside the southeast gate of Silvercreek");
  set_long (
    "You're at the southern east gate of Silvercreek. The northern "
  + "east gate is mainly used by the salesmen and the students at "
  + "the Academy of Magic while this gate being used by everyone e"
  + "lse. You can see the citystreets through the adamantium gates"
  + ". A road leads north to an opening.");

  add_exit ("west", ROOM_PATH + "underseg.c");
  add_exit ("north", ROOM_PATH + "opening.c");
  add_exit ("southeast", "/world/y87x345");

  add_object (MONSTER_PATH + "gateguard1"); 
  add_object (MONSTER_PATH + "gateguard1"); 

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
