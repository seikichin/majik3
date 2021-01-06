// DATE        : Sat Feb 21 21:57:32 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Bedroom");
  set_long (
    "The small room you're standing in is moderately decorated. A b"
  + "ed and a small desk are placed beside the west wall and a cab"
  + "inet dominates the south wall. Few glowing crystals are attac"
  + "hed to the walls to light the room.");

  add_exit ("east", ROOM_PATH + "mansliv.c");

  add_item ("desk",
    "It's a normal wooden writing desk. There are no drawers in it."
  + "\n");

  add_item ("bed",
    "Quite comfortable looking ordinary bed. Some elves, mostly t"
  + "he nobility, like to sleep in beds, while the common elves sl"
  + "eep under trees, or on their branches.\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
