// DATE        : Mon Nov 10 00:39:43 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Dark Forest");
  set_long (
    "You are in a lush, green forest. You are realizing that this f"
  + "orest is rather large. To the east it seems to get even darke"
  + "r. The treetops form a thick, green canopy. Only a single ray"
  + " of sunlight would be allowed through on the sunniest day. Th"
  + "ere is no discernable path or footprints in sight.");

  add_exit ("west", ROOM_PATH + "oforest15.c");
  add_exit ("south", ROOM_PATH + "oforest17.c");
  add_exit ("northeast", ROOM_PATH + "iforest2.c");
  add_exit ("southeast", ROOM_PATH + "iforest7.c");
  add_exit ("north", ROOM_PATH + "oforest10.c");
  add_exit ("east", ROOM_PATH + "iforest4.c");
  add_exit ("northwest", ROOM_PATH + "oforest9.c");

  add_item ("floor forest_floor ground",
    "The forest floor is overgrown with vegatation and dead tree li"
  + "mbs.  A few forest critters scurry by as look down.\n");

  add_item ("maples maple tree trees",
    "The fores"
  + "t is full of healthy, thick maple trees.  The trees are tall "
  + "and appear to be in perfect health.  One of the trees has low"
  + "er branches than the others.  Maybe you could go up there and"
  + " get a better view of the area.\n");

  add_item ("canopy",
    "The tree branches mingle toge"
  + "ther to form an almost impenatrable rooftop, blocking out wha"
  + "tever light may be trying to shine through.\n");

  add_sound ("Horrible cries of pain echo all around you. ");
  add_sound ("A hollow voice echos in your head: Welcome to my nightmare. ");
  add_sound ("A frigid wind whips through the trees, freezing you to the bone. ");
  add_sound ("You hear the clanck of metal against bone nearby. ");

  set_outdoors (4);
  set_light (-1);

  add_monster (MONSTER_PATH + "elffighter");
}

init()
{
   ::init();
     add_action("climb_tree","climb");
}

climb_tree(string what)
{
     if (what != "tree")
{
return 0;
}
   else
{
   write("You grab a branch and start to climb the tree.  After a few scratches and "+
    "words muttered under your breath, you finally make it to a balcony above.\n");
   message("standard", capitalize(THIS->query_name()) + " climbs up the "+
    "tree.\n", ENV(THIS), THIS);
   THIS->move_player ( ROOM_PATH + "bridge29.c");
   return 1;
}
}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

