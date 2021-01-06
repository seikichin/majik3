// DATE        : Tue Feb  3 19:15:39 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Sylvan cemetary");
  set_long (
    "You're wandering in the grove that is perhaps the most sacred "
  + "for the elven kin of Sol'daran. Here in this most serene and "
  + "beautiful grove is buried those who have left this world fore"
  + "ver. Tall and beautiful birch trees surround the grove and hi"
  + "de it in their caring embrace. Shining white memorial stones "
  + "have been laid on the places where the dead rest. In the sout"
  + "h you can see the city of Sol'daran over the silvery fence.");

  add_exit ("south", ROOM_PATH + "winterstr2.c");
  add_exit ("north", ROOM_PATH + "sylcem2.c");
  add_exit ("east", ROOM_PATH + "sylcem3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
