// DATE        : Mon Nov 10 00:42:40 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Dark Forest");
  set_long (
    "You are in a lush, green forest. It is thick with tall maples "
  + "and vegatation covers the forest floor. There are some tracks"
  + " on the ground here which all seem to go in the same directio"
  + "n. You hear the crackle of wood burning to the south and smel"
  + "l something comming from that direction also.");

  add_exit ("west", ROOM_PATH + "iforest6.c");
  add_exit ("southwest", ROOM_PATH + "iforest9.c");
  add_exit ("south", ROOM_PATH + "oforest18.c");
  add_exit ("northeast", ROOM_PATH + "oforest12.c");
  add_exit ("north", ROOM_PATH + "oforest11.c");
  add_exit ("east", ROOM_PATH + "oforest16.c");
  add_exit ("northwest", ROOM_PATH + "iforest3.c");

  add_item ("floor forest_floor ground",
    "The forest floor is overgrown with vegatation and dead tree li"
  + "mbs.  There are some tracks here also.\n");

  add_item ("tracks",
    "The tracks all seem to"
  + " go in the same direction, which is towords one of the trees."
  + "\n");

  add_item ("maples maple tree trees",
    "The forest is full of healthy, thick maple trees.  The trees"
  + " are tall and appear to be in perfect health.  One tree, howe"
  + "ver, has extremely low hanging branches.  They would be easy "
  + "to grasp and climb up.\n");

  add_item ("canopy",
    "The tree branches mingle together to f"
  + "orm an almost impenatrable rooftop, blocking out whatever lig"
  + "ht may be trying to shine through.\n");

  add_sound ("Horrible cries of pain echo all around you. ");
  add_sound ("A hollow voice echos in your head: Welcome to my nightmare. ");
  add_sound ("A frigid wind whips through the trees, freezing you to the bone. ");
  add_sound ("You hear the clanck of metal against bone nearby. ");
  add_sound ("A few wisps of smoke trail in from the south. ");

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
   THIS->move_player ( ROOM_PATH + "bridge14.c");
   return 1;
}
}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

