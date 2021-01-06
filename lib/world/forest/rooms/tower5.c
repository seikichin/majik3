// DATE        : Mon Nov 10 02:27:20 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Staircase");
  set_long (
    "The staircase is circular and is so wide it must take up the w"
  + "idth of the tower. This part of the staircase is devoid of an"
  + "ything except the painting on the wall.");

  add_exit ("down", ROOM_PATH + "tower4.c");
  add_exit ("up", ROOM_PATH + "tower6.c");

  add_item ("painting",
    "The painting is done with some substance foriegn to you.  The "
  + "picture is of a quarter moon over the blackness of space and "
  + "a few stars.  Oddly, the quater moon glows faintly, even in t"
  + "his thick darkness.\n");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
