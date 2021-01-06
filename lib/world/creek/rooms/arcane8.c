// DATE        : Sun Nov  2 22:20:42 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Arcane street");
  set_long (
    "You're now walking along the Arcane street which runs in east-"
  + "west direction from the Academy to the Ivory Halls. Around "
  + "the corner in the west is the main entrance to the gardens. C"
  + "ity walls rise before you in the north blocking the view ther"
  + "e.");

  add_exit ("east", ROOM_PATH + "arcane7.c");
  add_exit ("west", ROOM_PATH + "ivory5.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
