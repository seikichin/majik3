// DATE        : Mon Nov  3 20:54:06 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("An elegant entrance hall");
  set_long (
    "You've standing in an elegant hall in the Ivory Halls. The Ord"
  + "er of Ivory is a group of noble knights who have dedicated th"
  + "eir lives to defend the weak and aid the course of justice. T"
  + "he hall is decorated with paintings and some plants. A long r"
  + "ed oriental made carpet is on the floor. A door leads west. T"
  + "he city streets are in the east.");

  add_exit ("west", ROOM_PATH + "gardens5.c");
  add_exit ("east", ROOM_PATH + "ivory2.c");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
