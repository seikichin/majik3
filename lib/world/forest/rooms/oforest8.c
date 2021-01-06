// DATE        : Mon Nov 10 00:28:19 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("camp");
  set_short ("Dark Forest");
  set_long (
    "You have entered a campsite. There is a large campfire in the "
  + "center of a clearing. There is a large spit over the fire wit"
  + "h some meat cooking on it. There are a few blankets strewn ar"
  + "ound the campfire in a random order. An unnatural darkness em"
  + "inates from the southwest. The ground here is mostly dirt as "
  + "the plants and grass have been worn.");

  add_exit ("west", ROOM_PATH + "oforest6.c");
  add_exit ("southwest", ROOM_PATH + "iforest3.c");
  add_exit ("south", ROOM_PATH + "oforest11.c");
  add_exit ("southeast", ROOM_PATH + "oforest12.c");
  add_exit ("northwest", ROOM_PATH + "oforest3.c");

  add_item ("spit animal meat",
    "There is a pig on the spit being cooked over the fire.");

  add_item ("footprints",
    "The foot"
  + "prints are too overlapped to make any sense of them.\n");

  add_item ("campfire fire",
    "The camp"
  + "fire blazing brightly.  There is a spit over it with some ani"
  + "mal cooking there.\n");

  add_item ("maples maple tree trees",
    "The forest is full of healthy, thick maple"
  + " trees.  The trees are tall and appear to be in perfect healt"
  + "h.  One of the trees has lower branches than the others.  May"
  + "be you could go up there and get a better view of the area.\n");

  add_item ("canopy",
    "T"
  + "he tree branches mingle together to form an almost impenatrab"
  + "le rooftop, blocking out whatever light may be trying to shin"
  + "e through.\n");

  add_item ("floor forest floor ground",
    "The forest floor is clear of almost all plant life"
  + ".  There are many footprints going this way and that.\n");

  add_sound ("The smell from the campfire is very appitizing. ");
  add_sound ("A hollow voice echos in your head: Welcome to my nightmare. ");
  add_sound ("A frigid wind whips through the trees, freezing you to the bone. ");
  add_sound ("You hear the clanck of metal against bone nearby. ");

  set_outdoors (4);
  set_light (-1);

  add_monster(MONSTER_PATH + "elvanna.c");

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
   THIS->move_player ( ROOM_PATH + "bridge19.c");
   return 1;
}
}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

