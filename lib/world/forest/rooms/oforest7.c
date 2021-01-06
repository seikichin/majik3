// DATE        : Mon Nov 10 00:25:39 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Swamp");
  set_long (
    "You are in the middle of a shallow swamp on the western side o"
  + "f the forest. The water here is up to your knees. There are m"
  + "any trees scattered around the swamp. The water seems to be a"
  + "t it's deepest here and leaving in any direction would lead y"
  + "ou to higher ground. Leaving may be a good idea since you are"
  + " slowly sinking into the swamp.");

  add_exit ("southwest", ROOM_PATH + "oforest9.c");
  add_exit ("south", ROOM_PATH + "oforest10.c");
  add_exit ("northeast", ROOM_PATH + "oforest2.c");
  add_exit ("southeast", ROOM_PATH + "iforest2.c");
  add_exit ("east", ROOM_PATH + "oforest4.c");

  add_item ("maples maple tree trees",
    "The swamp has a few trees scattered about.  There is one tree "
  + "that catches your eye over the others.  It is a wicked, twist"
  + "ed tree in the center of the swamp.\n");

  add_item ("wicked_tree twisted_tree wicked_twisted_tree",
    "This tree is huge with ma"
  + "ny, low hanging branches.\n");

  add_item ("floor forest_floor ground swamp water",
    "The swamp water is about up to your"
  + " knees.  It is murky and smells something awful.  The ground "
  + "is so wet that you are slowly sinking into it.\n");

  add_item ("canopy",
    "The tree branc"
  + "hes mingle together to form an almost impenatrable rooftop, b"
  + "locking out whatever light may be trying to shine through.\n");

  add_item ("branches branch",
    "So"
  + "me of the branches from the twisted tree in the center of the"
  + " swamp hang very low to the water.  You could possibly climb "
  + "them to get out of the murky water.\n");

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
   THIS->move_player ( ROOM_PATH + "bridge1.c");
   return 1;
}
}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

