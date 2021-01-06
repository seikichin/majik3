// DATE        : Sun Feb 22 00:15:12 1998
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
  + "e sunniest day. There are some footprints leading north as we"
  + "ll as to the west and southwest. You also hear some voices co"
  + "mming from the north.");

  add_exit ("northwest", ROOM_PATH + "oforest6.c");
  add_exit ("west", ROOM_PATH + "iforest3.c");
  add_exit ("southwest", ROOM_PATH + "iforest6.c");
  add_exit ("south", ROOM_PATH + "oforest14.c");
  add_exit ("southeast", ROOM_PATH + "oforest16.c");
  add_exit ("east", ROOM_PATH + "oforest12.c");
  add_exit ("north", ROOM_PATH + "oforest8.c");

  add_item ("maples maple tree trees",
    "The forest is full of healthy, thick maple trees.  The trees a"
  + "re tall and appear to be in perfect health.\n");

  add_item ("canopy",
    "The tree branches"
  + " mingle together to form an almost impenatrable rooftop, bloc"
  + "king out whatever light may be trying to shine through.\n");

  add_item ("floor forest floor ground",
    "The f"
  + "orest floor is overgrown with vegatation and dead tree limbs."
  + "  A few forest critters scurry by as look down.\n");

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
