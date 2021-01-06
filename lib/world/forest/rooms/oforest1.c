// DATE        : Sat Feb 21 21:43:41 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Dark Forest");
  set_long (
    "You are in a lush, green forest. It is thick with tall maples "
  + "and vegatation covers the forest floor. There is something er"
  + "ie about this place. The treetops form a thick, green canopy."
  + " Only a single ray of sunlight would be allowed through on th"
  + "e sunniest day. There is no discernable path or footprints in"
  + " sight.");

  add_exit ("west", ROOM_PATH + "oforest2.c");
  add_exit ("southwest", ROOM_PATH + "oforest4.c");
  add_exit ("south", ROOM_PATH + "oforest5.c");
  add_exit ("southeast", ROOM_PATH + "oforest6.c");
  add_exit ("north", "/world/y423x266");
  add_exit ("east", ROOM_PATH + "oforest3.c");

  add_item ("floor forest_floor ground",
    "The forest floor is overgrown with vegatation and dead tree li"
  + "mbs.  A few forest critters scurry by as look down.\n");

  add_item ("maples maple tree trees",
    "The fores"
  + "t is full of healthy, thick maple trees.  The trees are tall "
  + "and appear to be in perfect health.\n");

  add_item ("canopy",
    "The tree branches mingle "
  + "together to form an almost impenatrable rooftop, blocking out"
  + " whatever light may be trying to shine through.\n");

  add_sound ("Horrible cries of pain echo all around you. ");
  add_sound ("A hollow voice echos in your head: Welcome to my nightmare. ");
  add_sound ("A frigid wind whips through the trees, freezing you to the bone. ");
  add_sound ("You hear the clanck of metal against bone nearby. ");

  set_outdoors (4);
  set_light (-1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
