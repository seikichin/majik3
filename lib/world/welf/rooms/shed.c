// DATE        : Mon Dec 29 16:01:30 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Small treeshed");
  set_long (
    "You're now in a small shed that is built on the treetop above "
  + "the orchard. You are not so sure what is built and what is th"
  + "e tree itself, so perfectly blends the worked out wood with t"
  + "he still living one. Small window on the north wall provides "
  + "a view over the orchard below you. Sturdy enough looking rope"
  + "ladders lead down through a hole in the floor.");

  add_exit ("down", ROOM_PATH + "ushed.c");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
