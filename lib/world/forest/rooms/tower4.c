// DATE        : Mon Nov 10 02:26:17 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Bottom of the stairs");
  set_long (
    "You are at the bottom of a wide staircase which dominates the "
  + "room. The steps are wide, but thin and lead up into darkness."
  + " It will be a precarious walk up them. There is also a window"
  + " on the south wall. To the south is the entrance hall.");

  add_exit ("south", ROOM_PATH + "tower1.c");
  add_exit ("up", ROOM_PATH + "tower5.c");

  add_item ("stairs stairway",
    "The stairs are very wide, but also very thin.  Walking up them"
  + " will be difficult at best.  They are made of the same stone "
  + "as the tower walls and don't seem to be worn in the slightest"
  + ".\n");

  add_item ("window",
    "You look out the window and get a limited view of the outsi"
  + "de.  The ground is covered with dirt and there is a swirling "
  + "green mist that surrounds the tower.\n");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
