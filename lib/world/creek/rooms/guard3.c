// DATE        : Mon Nov  3 20:28:47 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A training room");
  set_long (
    "This room is reserved for training new guards and the citizens"
  + " now, for the chief guard has decided that every man capable "
  + "of holding a sword must defend the city if needed. The room h"
  + "as thick red mats on the floor. On the walls are placed diffe"
  + "rent weapons and shields. The training room continues to the "
  + "west where a door leads north to the office.");

  add_exit ("west", ROOM_PATH + "guard2.c");
  add_object (MONSTER_PATH + "argeras");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
