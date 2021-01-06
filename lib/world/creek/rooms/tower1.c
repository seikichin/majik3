// DATE        : Mon Nov  3 20:46:27 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the base of a tower");
  set_long (
    "You've standing at the center of a round room. Spiralling stai"
  + "rs lead up to the tower of purest magic. The surrounding magi"
  + "c is very strong here and it makes you feel awkward. The atmo"
  + "sphere is very tense here. Doors lead south and west.");

  add_exit ("west", ROOM_PATH + "acadent.c");
  add_exit ("up", ROOM_PATH + "tower2.c");
  add_exit ("south", ROOM_PATH + "class.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
