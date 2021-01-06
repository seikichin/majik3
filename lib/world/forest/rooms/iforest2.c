// DATE        : Mon Nov 10 01:02:27 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("inner_forest");
  set_short ("Deep inside the Dark Forest");
  set_long (
    "The forest has thinned out slightly here. The ground is slight"
  + "ly wet and you're leaving very obvious tracks in the muddy gr"
  + "ound. The trees still cover the area but, there seems to be s"
  + "ome visible trails among them. The thick canopy formed by tre"
  + "etops seems to thin out a bit here, allowing you a few glimps"
  + "es of the sky overhead. However, it seems to have gotten dark"
  + "er here instead of lighter. Your feelings of fear combined wi"
  + "th curiosity grow as you near the center of the forest.");

  add_exit ("northeast", ROOM_PATH + "oforest5.c");
  add_exit ("north", ROOM_PATH + "oforest4.c");
  add_exit ("northwest", ROOM_PATH + "oforest7.c");
  add_exit ("west", ROOM_PATH + "oforest10.c");
  add_exit ("southwest", ROOM_PATH + "oforest13.c");
  add_exit ("south", ROOM_PATH + "iforest4.c");
  add_exit ("southeast", ROOM_PATH + "iforest5.c");
  add_exit ("east", ROOM_PATH + "iforest1.c");

  add_item ("floor forest_floor ground",
    "The forest floor is full of vegatation yet, it is cleared out "
  + "in a few places forming a few walking trails.\n");

  add_item ("maples maple tree trees",
    "The forest is f"
  + "ull of healthy, thick maple trees.  The trees are tall and ap"
  + "pear to be in perfect health.\n");

  add_item ("canopy treetops",
    "The canopy of treetops is moder"
  + "ately thick here, allowing you a few glimpes sky above.  Also"
  + ", you notice a few ropes strung from tree to tree.  Perhaps t"
  + "hey form a crude bridge of some sort.\n");

  add_item ("bridge ropes rope",
    "There are ropes in sets"
  + " of three connected to the treetops.  They look like a type o"
  + "f bridge.  If you could only find some way up there.\n");

  add_sound ("A hollow voice echos in your head:  Leave now, or spend eternity in my hell. ");
  add_sound ("The temprature here is FREEZING, yet there isn't the slightest breeze. ");
  add_sound ("Thick, impenatrable darkness surrounds you. ");
  add_sound ("It is so dark, you feel like you're in a sea of blackness. ");

  set_light (-2);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

