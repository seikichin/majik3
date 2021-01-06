// DATE        : Mon Nov  3 23:50:46 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Arcane street");
  set_long (
    "You're walking along Arcane street which has been named after "
  + "the academy of magic. The academy looms before you quite a di"
  + "stance in east. The citywalls rise before you in north blocki"
  + "ng the view there. The street continues to the east and west."
  + "");

  add_exit ("west", ROOM_PATH + "arcane8.c");
  add_exit ("east", ROOM_PATH + "arcane6.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
