// DATE        : Mon Nov 10 02:28:53 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Staircase");
  set_long (
    "The staircase is circular and is so wide it must take up the w"
  + "idth of the tower. There is a painting on the wall here. It i"
  + "s glowing faintly in the dark.");

  add_exit ("down", ROOM_PATH + "tower5.c");
  add_exit ("up", ROOM_PATH + "tower7.c");

  add_item ("painting",
    "The painting is done with some substance foriegn to you.  The "
  + "picture shows two sections of the moon in the quarter state. "
  + " One is in the lower right corner of the painting and the oth"
  + "er is in the upper left.  Oddly, the two sections quater moon"
  + " glows faintly, even in this thick darkness.\n");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
