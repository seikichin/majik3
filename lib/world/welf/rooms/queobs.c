// DATE        : Sun Mar 15 09:31:22 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Observatory");
  set_long (
    "You're standing in a perfectly round room that seems to be an "
  + "obervatory of some sort. The whole domed ceiling is made of g"
  + "lass windows providing an excellent view at the sky and the s"
  + "tars. Couple of bookcases and desks have been placed beside t"
  + "he walls. The floor here is full of astronomical symbols and "
  + "inscriptions. Short stais lead east to the great library.");

  add_exit ("east", ROOM_PATH + "quelib.c");

  set_outdoors (4);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
