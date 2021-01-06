// DATE        : Sun Jan 18 22:40:52 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Enterance to the Mill");
  add_object(MONSTER_PATH+"John.c");
  set_long (
    "Here is the entrance to the mill. There is a set a double door"
  + "s on the east wall. The room is huge and the roof is pretty h"
  + "igh up. It runs lengthwise away from the doors and deeper int"
  + "o the building. Near the north wall there is a picture of a f"
  + "arm. Other than that this area is filled with various things,"
  + " mostly dirt remains of a few plants. A large archways spans "
  + "across the south wall.");

  add_exit ("east", ROOM_PATH + "mill3.c");
  add_exit ("out", ROOM_PATH + "mill1.c");
  add_exit ("south", ROOM_PATH + "shop.c");

  add_item ("picture",
    "The is just an outdoors picture of a small farm with a crop of"
  + " of corn growing in it.  The sun is setting and it makes the "
  + "picture look beautiful.\n");

  add_item ("door doors",
    "The doors are huge and reach very hig"
  + "h up.\n");
  set_outdoors (0);
  set_light (1);
}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
