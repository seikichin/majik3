// DATE        : Mon Nov 10 00:32:16 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  int i, j;

  set_short ("Dark Forest");
  set_long (
    "You are in a lush, green forest. It is thick with tall maples "
  + "and vegatation covers the forest floor. The air is more moist"
  + " here than other parts of the forest. There are some tracks l"
  + "eft in the ground, which is a little muddy.");

  add_exit ("south", ROOM_PATH + "oforest15.c");
  add_exit ("northeast", ROOM_PATH + "oforest7.c");
  add_exit ("southeast", ROOM_PATH + "oforest13.c");
  add_exit ("east", ROOM_PATH + "oforest10.c");

  add_item ("floor forest_floor ground",
    "The forest floor is very muddy and there are some tracks here."
  + "  Then a snake slithers by and jump back quickly.\n");

  add_item ("tracks",
    "The wet gro"
  + "und makes the tracks here obvious.  You see two distinctly di"
  + "fferent types, besides your own.  One type is made goblins.  "
  + "You can tell this by the deep tracks made from heavy foot ste"
  + "ps and the shape of the ugly, deformed feet.  The other type "
  + "is made by a more graceful and lightfooted humaniod, possibly"
  + " elven.\n");

  add_item ("maples maple tree trees",
    "The forest is full of healthy, thick maple trees.  Th"
  + "e trees are tall and appear to be in perfect health.\n");

  add_item ("canopy",
    "The tree"
  + " branches mingle together to form an almost impenatrable roof"
  + "top, blocking out whatever light may be trying to shine throu"
  + "gh.\n");

  add_sound ("Horrible cries of pain echo all around you. ");
  add_sound ("A hollow voice echos in your head: Welcome to my nightmare. ");
  add_sound ("A frigid wind whips through the trees, freezing you to the bone. ");

  set_outdoors (4);
  set_light (-1);

  j = random(5) + 1;
 
  for (i = 0; i < j; i++) 
      {
        add_monster (MONSTER_PATH + "elffighter");
      }

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

