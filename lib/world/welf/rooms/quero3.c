// DATE        : Sun Dec 28 01:44:27 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Messy room");
  set_long (
    "The room you're standing in now is a total mess. Musical notes"
  + " and papers few flutes and lutes, a viola and a brass symbal "
  + "lay here and there on the floor. A comfortable looking purple"
  + " sofa has been placed before the window on the north wall. A "
  + "desk and chair has been placed next to it. A door leads south"
  + " from here.");

  add_exit ("south", ROOM_PATH + "queha2.c");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
