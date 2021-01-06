// DATE        : Sat Feb 21 21:45:05 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Dark Forest");
  set_long (
    "You are in a lush, green forest. The ground here is very moist"
  + " and it seems to get softer to the south and southwest. There"
  + " are not many animals around, which strikes you as odd in suc"
  + "h a beautiful, healthy forest. Another strange fact is the da"
  + "rkness, which seems very unnatural. You are leaving obvious t"
  + "racks in the wet dirt.");

  add_exit ("southwest", ROOM_PATH + "oforest7.c");
  add_exit ("south", ROOM_PATH + "oforest4.c");
  add_exit ("southeast", ROOM_PATH + "oforest6.c");
  add_exit ("east", ROOM_PATH + "oforest1.c");

  add_item ("maples maple tree trees",
    "The forest is full of healthy, thick maple trees.  The moist g"
  + "round lets the trees grown stronger here than other parts of "
  + "the forest.\n");

  add_item ("floor forest_floor ground",
    "The forest floor is very moist here which allows "
  + "the vegatation to thrive.  You can see some tracks in the wet"
  + " dirt.\n");

  add_item ("canopy",
    "The tree branches mingle together to form an almost im"
  + "penatrable rooftop, blocking out whatever light may be trying"
  + " to shine through.\n");

  add_item ("tracks footprints",
    "The wet ground makes the tracks here obvio"
  + "us.  You see two distinctly different types, besides your own"
  + ".  One type is made goblins.  You can tell this by the deep t"
  + "racks made from heavy foot steps and the shape of the ugly, d"
  + "eformed feet.  The other type is made by a more graceful and "
  + "lightfooted humaniod, possibly elven.\n");

  add_sound ("Horrible cries of pain echo all around you. ");
  add_sound ("A hollow voice echos in your head: Welcome to my nightmare. ");
  add_sound ("A frigid wind whips through the trees, freezing you to the bone. ");
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
