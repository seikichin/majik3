// DATE        : Mon Nov 10 01:03:58 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("inner_forest");
  set_short ("Deep inside the Dark Forest");
  set_long (
    "The number of trees has thinned out slightly here. The forest "
  + "continues on in all directions. To the west it appears to be "
  + "your average forest and to the east it seems like something d"
  + "ifferent, but you're not quite sure what. Some force unknown "
  + "to you seems to be drawing you there, deeper into the forest."
  + "");

  add_exit ("northeast", ROOM_PATH + "iforest1.c");
  add_exit ("north", ROOM_PATH + "iforest2.c");
  add_exit ("northwest", ROOM_PATH + "oforest10.c");
  add_exit ("west", ROOM_PATH + "oforest13.c");
  add_exit ("southwest", ROOM_PATH + "oforest17.c");
  add_exit ("south", ROOM_PATH + "iforest7.c");
  add_exit ("southeast", ROOM_PATH + "iforest8.c");
  add_exit ("east", ROOM_PATH + "iforest5.c");

  add_item ("maples maple tree trees",
    "The forest is full of healthy, thick maple trees.  The trees a"
  + "re tall and appear to be in perfect health.\n");

  add_item ("canopy treetops",
    "The canopy of tre"
  + "etops is moderately thick here, allowing you a few glimpes sk"
  + "y above.  Also, you notice a few ropes strung from tree to tr"
  + "ee.  Perhaps they form a crude bridge of some sort.\n");

  add_item ("bridge ropes rope",
    "There are"
  + " ropes in sets of three connected to the treetops.  They look"
  + " like a type of bridge.  If you could only find some way up t"
  + "here.\n");

  add_item ("floor forest floor ground",
    "The forest floor is full of vegatation yet, it is clear"
  + "ed out in a few places forming a few walking trails.\n");

  add_sound ("A hollow voice echos in your head:  Leave now, or spend eternity in my hell. ");
  add_sound ("The temprature here is FREEZING, yet there isn't the slightest breeze. ");
  add_sound ("Thick, impenatrable darkness surrounds you. ");
  add_sound ("It is so dark, you feel like you're in a sea of blackness. ");

  set_light (-2);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

