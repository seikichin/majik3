// DATE        : Mon Nov  3 20:26:35 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Silvercreek cityguard headquarters");
  set_long (
    "This is the headquarters for the city guards. This room is the"
  + " office where you can complain about certain citizens or repo"
  + "rt a crime. A desk is on the back of the room, behind it sits"
  + " an important looking officer. A door leads east to the Marke"
  + "t place. Another door leads south. A ring of metal against me"
  + "tal and occasional yelps comes from behind the door in south."
  + "");

  add_exit ("east", ROOM_PATH + "marketp6.c");
  add_exit ("south", ROOM_PATH + "guard2.c");

  add_object (MONSTER_PATH + "cityguard");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
