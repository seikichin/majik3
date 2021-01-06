// DATE        : Sat Nov  1 23:52:54 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Baker's Shop");
  set_long (
    "Ahh, the smell of freshly baked breads and cakes. The air is f"
  + "illed with flour as the baker hurriedly works behind the desk"
  + " at the back of the room. The shop is filled with shelves and"
  + " baskets, all filled with breads and cakes. A door leads sout"
  + "h to the streets.");

  add_exit ("south", ROOM_PATH + "majik3.c");

  set_outdoors (1);
  set_light (1);
  add_object (MONSTER_PATH + "hob");
}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
