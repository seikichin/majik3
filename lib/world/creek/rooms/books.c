// DATE        : Mon Nov  3 20:24:50 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Ye bookke shoppe");
  set_long (
    "You're in a room full of books. The books are neatly laid in s"
  + "helves, all in alphabethical order. If you are looking for ma"
  + "ps or just general information about some subject this is the"
  + " right place to start looking for. A door leads west to the s"
  + "treets.");

  add_exit ("west", ROOM_PATH + "gate3.c");
  add_object (MONSTER_PATH + "thanacus");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
