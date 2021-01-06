// DATE        : Sat Feb 21 21:48:10 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Dark Forest");
  set_long (
    "You are in a lush, green forest. It is thick with tall maples "
  + "and vegatation covers the forest floor. It is dark here, but "
  + "it seems to get even darker just to the south of you. You can"
  + " also feel moisture in the air, and the ground is becoming mo"
  + "re moist to the west.");

  add_exit ("west", ROOM_PATH + "oforest7.c");
  add_exit ("southwest", ROOM_PATH + "oforest10.c");
  add_exit ("south", ROOM_PATH + "iforest2.c");
  add_exit ("southeast", ROOM_PATH + "iforest1.c");
  add_exit ("east", ROOM_PATH + "oforest5.c");
  add_exit ("northeast", ROOM_PATH + "oforest1.c");
  add_exit ("north", ROOM_PATH + "oforest2.c");

  add_item ("maples maple tree trees",
    "The forest is full of healthy, thick maple trees.  Some of the"
  + "m have deep cuts and chopped off branches.  They could be the"
  + " signs of recent battle in the area.\n");

  add_item ("floor forest_floor ground",
    "The forest floor is over"
  + "grown with vegatation and dead tree limbs.  There are many tr"
  + "acks scattered around which show signs of a recent struggle.\n"
  + "");

  add_item ("tracks",
    "The tracks are to intermingled to make anything of them.\n");

  add_item ("canopy",
    "The "
  + "tree branches mingle together to form an almost impenatrable "
  + "rooftop, blocking out whatever light may be trying to shine t"
  + "hrough.\n");

  add_sound ("Horrible cries of pain echo all around you. ");
  add_sound ("A hollow voice echos in your head: Welcome to my nightmare. ");
  add_sound ("A frigid wind whips through the trees, freezing you to the bone. ");
  add_sound ("You hear the clanck of metal against bone nearby. ");
  add_sound ("Your feet sink into the mud a little. ");

  set_outdoors (4);
  set_light (-1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
