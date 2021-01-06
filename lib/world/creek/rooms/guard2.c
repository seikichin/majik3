// DATE        : Mon Nov  3 20:28:05 1997
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
  + "rent weapons and shields. A door leads north to the office. T"
  + "he training room continues to the east where the swordmaster "
  + "is waiting for citizens who want to learn how to fight proper"
  + "ly.");

  add_exit ("east", ROOM_PATH + "guard3.c");
  add_exit ("north", ROOM_PATH + "guard1.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
