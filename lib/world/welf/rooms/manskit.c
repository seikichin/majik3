// DATE        : Sun Feb 22 16:33:24 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Kitchen");
  set_long (
    "You're standing in a luxurious kitchen. Cupboards, cabinets an"
  + "d shelves fill the room and you can smell delicious aroma of "
  + "fresh bread, spices and wine. There's alose a stonemade firep"
  + "lace beside the north wall.");

  add_exit ("south", ROOM_PATH + "mansmain.c");

  add_sound ("The aroma of fresh bread and wine fills your nostrils and you suddenly feel very hungry.");
  add_sound ("Mmmmm, what's that delicious scent.");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
