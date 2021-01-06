// DATE        : Mon Nov 10 01:09:49 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("inner_forest");
  set_short ("Deep inside the Dark Forest");
  set_long (
    "The forest has thinned out slightly here. There are huge plume"
  + "s of smoke rising up from the south. Plus to the northeast yo"
  + "u can see some kind of swirling smoke cloud, different than t"
  + "o the south. The forest continues on in all the other directi"
  + "ons.");

  add_exit ("northeast", ROOM_PATH + "oforest14.c");
  add_exit ("north", ROOM_PATH + "iforest6.c");
  add_exit ("northwest", ROOM_PATH + "iforest5.c");
  add_exit ("west", ROOM_PATH + "iforest8.c");
  add_exit ("southwest", ROOM_PATH + "oforest21.c");
  add_exit ("south", ROOM_PATH + "oforest20.c");
  add_exit ("southeast", ROOM_PATH + "iforest6.c");
  add_exit ("east", ROOM_PATH + "oforest18.c");

  add_item ("floor forest_floor ground",
    "The forest floor is full of vegatation yet, it is cleared out "
  + "in a few places forming a few walking trails.\n");

  add_item ("maples maple tree trees",
    "The forest is f"
  + "ull of healthy, thick maple trees.  The trees are tall and ap"
  + "pear to be in perfect health.  One of the trees has lower bra"
  + "nches than the others.  Maybe you could go up there and get a"
  + " better view of the area.\n");

  add_item ("canopy treetops",
    "The canopy of treetops is moderatel"
  + "y thick here, allowing you a few glimpes sky above.  Also, yo"
  + "u notice a few ropes strung from tree to tree.  Perhaps they "
  + "form a crude bridge of some sort.\n");

  add_item ("bridge ropes rope",
    "There are ropes in sets of "
  + "three connected to the treetops.  They look like a type of br"
  + "idge.  If you could only find some way up there.\n");

  add_sound ("A hollow voice echos in your head:  Leave now, or spend eternity in my hell. ");
  add_sound ("The temprature here is FREEZING, yet there isn't the slightest breeze. ");
  add_sound ("Thick, impenatrable darkness surrounds you. ");
  add_sound ("It is so dark, you feel like you're in a sea of blackness. ");

  set_light (-2);

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
   THIS->move_player ( ROOM_PATH + "bridge7.c");
   return 1;
}
}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

