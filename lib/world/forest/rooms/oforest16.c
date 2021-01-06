// DATE        : Mon Nov 10 00:47:47 1997
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
  + " There is something drawn in the dirt here. There is no disce"
  + "rnable path or footprints in sight.");

  add_exit ("west", ROOM_PATH + "oforest14.c");
  add_exit ("southwest", ROOM_PATH + "oforest18.c");
  add_exit ("north", ROOM_PATH + "oforest12.c");
  add_exit ("northwest", ROOM_PATH + "oforest11.c");

  add_item ("drawing",
    "There is a depiction of a cresent moon carved into the dirt.\n");

  add_item ("floor forest_floor ground",
    "T"
  + "he forest floor is overgrown with vegatation and dead tree li"
  + "mbs.  You notice some kind of drawing in the dirt.\n");

  add_item ("maples maple tree trees",
    "The forest"
  + " is full of healthy, thick maple trees.  The trees are tall a"
  + "nd appear to be in perfect health.  One of the trees has lowe"
  + "r branches than the others.  Maybe you could go up there and "
  + "get a better view of the area.\n");

  add_item ("canopy",
    "The tree branches mingle toget"
  + "her to form an almost impenatrable rooftop, blocking out what"
  + "ever light may be trying to shine through.\n");

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
   THIS->move_player ( ROOM_PATH + "bridge12.c");
   return 1;
}
}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

