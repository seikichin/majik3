// DATE        : Tue Jan  6 12:49:24 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Inside the Mill");
  set_long (
    "This is the center of the mill. The room is filled with items "
  + "of all sorts, but one thing catches your eye above all else. "
  + "Next to the south wall is a huge contraption. The wall behind"
  + " it has some openings, in which belts and pulleys go through "
  + "to the outside.");

  add_exit ("east", ROOM_PATH + "mill4.c");
  add_exit ("west", ROOM_PATH + "mill2.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
