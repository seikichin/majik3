// DATE        : Thu Jan 15 20:09:44 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Sparkling forest stream");
  set_long (
    "The water isn't very deep at this spot and you can enjoy the f"
  + "lowing and sparkling stream as much as you like. The water is"
  + " very refreshing and you feel your sorrows washed away. A tal"
  + "l pine arches slightly over the river on the west side of the"
  + " stream and casts a soft shadow over you. The riverbank on th"
  + "e west side is near and easily reached but the eastern side "
  + "of the river seems to flow more strongly and is propably too "
  + "risky to swim. ");

  add_exit ("west", ROOM_PATH + "friver.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
