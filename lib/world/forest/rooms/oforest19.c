// DATE        : Mon Nov 10 00:56:30 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  int i;

  set_short ("Dark Forest");
  set_long (
    "You are in a lush, green forest. It is thick with tall maples "
  + "and vegatation covers the forest floor. You hear the crackle "
  + "of burning wood to the east. As you look in that direction yo"
  + "u can feintly make out some smoke and a few flames. It is ver"
  + "y quiet in this part of the forest. There isn't a single anim"
  + "al in sight.");

  add_exit ("northeast", ROOM_PATH + "iforest8.c");
  add_exit ("north", ROOM_PATH + "iforest7.c");
  add_exit ("east", ROOM_PATH + "oforest21");
  add_exit ("northwest", ROOM_PATH + "oforest17.c");

  add_item ("floor forest_floor ground",
    "The forest floor is overgrown with vegatation and dead tree li"
  + "mbs.\n");

  add_item ("maples maple tree trees",
    "The forest is full of healthy, thick maple trees.  The t"
  + "rees are tall and appear to be in perfect health.\n");

  add_item ("canopy",
    "The tree br"
  + "anches mingle together to form an almost impenatrable rooftop"
  + ", blocking out whatever light may be trying to shine through."
  + "\n");

  add_sound ("A few wisps of smoke trail in from the east. ");
  add_sound ("A hollow voice echos in your head: Welcome to my nightmare. ");
  add_sound ("A frigid wind whips through the trees, freezing you to the bone. ");

  set_outdoors (4);
  set_light (-1);

  add_monster (MONSTER_PATH + "goblin");
  add_monster (MONSTER_PATH + "goblin");
}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

