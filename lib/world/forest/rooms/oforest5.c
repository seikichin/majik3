// DATE        : Sun Feb 22 00:02:30 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Dark Forest");
  set_long (
    "You are in a lush, green forest. It is thick with tall maples "
  + "and vegatation covers the forest floor. In the distance you c"
  + "an hear some feint sounds coming from the east. You can hear "
  + "muffled voices as well as the crackle of a campfire. As you l"
  + "ook south, deeper into the forest, you get shivers up your sp"
  + "ine though you not quite sure why. You are not able to get a "
  + "clear view south from here.");

  add_exit ("northwest", ROOM_PATH + "oforest2.c");
  add_exit ("west", ROOM_PATH + "oforest4.c");
  add_exit ("southwest", ROOM_PATH + "iforest2.c");
  add_exit ("south", ROOM_PATH + "iforest1.c");
  add_exit ("southeast", ROOM_PATH + "iforest3.c");
  add_exit ("east", ROOM_PATH + "oforest6.c");
  add_exit ("northeast", ROOM_PATH + "oforest3.c");
  add_exit ("north", ROOM_PATH + "oforest1.c");

  add_item ("maples maple tree trees",
    "The forest is full of healthy, thick maple trees.  The trees a"
  + "re tall and appear to be in perfect health.\n");

  add_item ("floor forest_floor ground",
    "The forest floor "
  + "is overgrown with vegatation and dead tree limbs.  The ground"
  + " seems to become more moist to the east.\n");

  add_item ("canopy",
    "The tree branches mi"
  + "ngle together to form an almost impenatrable rooftop, blockin"
  + "g out whatever light may be trying to shine through.\n");

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
