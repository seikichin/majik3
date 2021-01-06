// DATE        : Mon Nov 10 00:22:24 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  int i;

  set_short ("Dark Forest");
  set_long (
    "You are deep into the forest. You see a campfire just to the e"
  + "ast and you can smell something cooking on it. You can also h"
  + "ear some voices comming from that direction. The trees contin"
  + "ue to dominate the scenery and the ground is still covered wi"
  + "th vegatation.");

  add_exit ("north", ROOM_PATH + "oforest3.c");
  add_exit ("northwest", ROOM_PATH + "oforest1.c");
  add_exit ("west", ROOM_PATH + "oforest5.c");
  add_exit ("southwest", ROOM_PATH + "iforest1.c");
  add_exit ("south", ROOM_PATH + "iforest3.c");
  add_exit ("southeast", ROOM_PATH + "oforest11.c");
  add_exit ("east", ROOM_PATH + "oforest8.c");

  add_item ("maples maple tree trees",
    "The forest is full of healthy, thick maple trees.  The trees a"
  + "re tall and appear to be in perfect health.One of the trees h"
  + "as lower branches than the others.  Maybe you could go up the"
  + "re and get a better view of the area.\n");

  add_item ("canopy",
    "The tree branches mingl"
  + "e together to form an almost impenatrable rooftop, blocking o"
  + "ut whatever light may be trying to shine through.\n");

  add_item ("floor forest floor ground",
    "The forest "
  + "floor is overgrown with vegatation and dead tree limbs.  A fe"
  + "w forest critters scurry by as look down.\n");

  add_sound ("Horrible cries of pain echo all around you. ");
  add_sound ("A hollow voice echos in your head: Welcome to my nightmare. ");
  add_sound ("A frigid wind whips through the trees, freezing you to the bone. ");
  add_sound ("You hear the clanck of metal against bone nearby. ");

  set_outdoors (4);
  set_light (-1);

  add_monster (MONSTER_PATH + "elffighter");
  add_monster (MONSTER_PATH + "elffighter");
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
   THIS->move_player ( ROOM_PATH + "bridge23.c");
   return 1;
}
}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

