// DATE        : Sun Nov  9 23:24:44 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Treetop intersection");
  set_long (
    "You stand on a wooden balcony of sorts. It is a circular struc"
  + "ture that goes around the tree before you. The floor consists"
  + " of wooden planks and there is a wooden handrail to keep you "
  + "from falling. A make shift bridge, made of rope, goes off in "
  + "four directions from here.");

  add_exit ("south", ROOM_PATH + "bridge15.c");
  add_exit ("southeast", ROOM_PATH + "bridge13.c");
  add_exit ("north", ROOM_PATH + "bridge17.c");
  add_exit ("northwest", ROOM_PATH + "bridge20.c");

  add_item ("tree",
    "The tree is a maple and seems in very good health.  You notice"
  + " that whoever contructed this balcony paid careful attention "
  + "not to damage the tree.  No nails or other objects have penet"
  + "rated it's bark.  More importantly, you see that the branches"
  + " below you are arranged in such a way that they would be easy"
  + " to climb down.\n");

  add_item ("bridge rope bridge ropes rope",
    "The ropes are a little thin for your liking, "
  + "but seem sturdy enough.  The material seems very smooth, poss"
  + "ibly silk.\n");

  add_item ("handrail wooden handrail",
    "The wooden handrail is of good construction.  It i"
  + "s approximately 1.5 meters high and has two boards going cros"
  + "swise, to prevent you from falling in between.\n");

  add_item ("balcony wooden balcony",
    "The balcony is"
  + " made of wooden planks that extend outward from the trunk of "
  + "the tree.  They aren't very thick, but they feel very sturdy."
  + "  It is about 2 meters wide from the trunk to the handrail, a"
  + "llowing plenty of room for movement.\n");

  add_sound ("The wooden planks of the balcony groan in futile protest of your weight. ");
  add_sound ("The view is beautiful up here! ");
  add_sound ("The sounds of battle, metal clashing against metal and agonizing death cries, come from the forest floor below. ");
  add_sound ("The tree branches sway in the wind. ");

  set_outdoors (4);

  add_monster (MONSTER_PATH + "elfarcher");
  add_monster (MONSTER_PATH + "elfarcher");
  add_monster (MONSTER_PATH + "elfarcher");
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
   write("You easily climb down the tree to the forest floor below.\n");
   message("standard", capitalize(THIS->query_name()) + " climbs down the "
    "tree.\n", ENV(THIS), THIS);
   THIS->move_player ( ROOM_PATH + "oforest14.c");
   return 1;
}
}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

