// DATE        : Sat Nov  1 21:47:13 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The innernmost part of the temple, the hall of last hope");
  set_long (
    "The dead may get a second chance if the gods are pleased. This"
  + " is the hall of spirits, the place of forgiving if it be the "
  + "hate that drove one to the death. The white walls around you "
  + "shine with a bright light. The chanting of the priests echoes"
  + " from the east.");

  add_exit ("east", ROOM_PATH + "gifts.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
