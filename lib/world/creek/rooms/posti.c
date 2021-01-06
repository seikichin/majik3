// DATE        : Mon Nov  3 21:39:17 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Post office");
  set_long (
    "This is the Post office of Silvercreek. The connections betwee"
  + "n the cities are good and if you want to mail some friend or "
  + "enemy this is the place for it. A desk is at the back of the "
  + "room. A door leads south to the streets.");

  add_exit ("south", ROOM_PATH + "stemple4.c");
  add_object (MONSTER_PATH + "postmaster");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
