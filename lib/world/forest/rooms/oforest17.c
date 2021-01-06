// DATE        : Mon Nov 10 00:50:38 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Dark Forest");
  set_long (
    "The thick darkness to east and northeast is the first thing yo"
  + "u notice when you enter this part of the forest. You are in a"
  + " lush, green forest. It is thick with tall maples and vegatat"
  + "ion covers the forest floor. There is something erie about th"
  + "is place. The treetops form a thick, green canopy. Only a sin"
  + "gle ray of sunlight would be allowed through on the sunniest "
  + "day. There is no discernable path or footprints in sight.");

  add_exit ("northeast", ROOM_PATH + "iforest4.c");
  add_exit ("southeast", ROOM_PATH + "oforest19.c");
  add_exit ("north", ROOM_PATH + "oforest13.c");
  add_exit ("east", ROOM_PATH + "iforest7.c");
  add_exit ("northwest", ROOM_PATH + "oforest15.c");

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
   THIS->move_player ( ROOM_PATH + "bridge35.c");
   return 1;
}
}



// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

