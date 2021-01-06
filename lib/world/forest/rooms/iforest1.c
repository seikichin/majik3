// DATE        : Mon Nov 10 01:01:39 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("inner_forest");
  set_short ("Deep inside the Dark Forest");
  set_long (
    "The forest has thinned out slightly here. The trees still cove"
  + "r the area but, there seems to be some visible trails among t"
  + "hem. The thick canopy formed by treetops also seems to thin o"
  + "ut a bit here, allowing you a few glimpses of the sky overhea"
  + "d. However, it seems to have gotten darker here instead of li"
  + "ghter. Your feelings of fear combined with curiosity grow as "
  + "you near the center of the forest.");

  add_exit ("northeast", ROOM_PATH + "oforest6.c");
  add_exit ("north", ROOM_PATH + "oforest5.c");
  add_exit ("northwest", ROOM_PATH + "oforest4.c");
  add_exit ("west", ROOM_PATH + "iforest2.c");
  add_exit ("southwest", ROOM_PATH + "iforest4.c");
  add_exit ("south", ROOM_PATH + "iforest5.c");
  add_exit ("southeast", ROOM_PATH + "iforest6.c");
  add_exit ("east", ROOM_PATH + "iforest3.c");

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

  add_monster (MONSTER_PATH + "skeleton");
  add_monster (MONSTER_PATH + "skeleton");
}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.
