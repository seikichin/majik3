// DATE        : Sun Nov  9 23:51:29 1997
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
  + "two seperate directions from here. There is also a rope ladde"
  + "r hanging down from somewhere high in the tree above you.");

  add_exit ("northeast", ROOM_PATH + "bridge30.c");
  add_exit ("east", ROOM_PATH + "bridge32.c");

  add_item ("tree",
    "The tree is a maple and seems in very good health.  You notice"
  + " that whoever contructed this balcony paid careful attention "
  + "not to damage the tree.  No nails or other objects have penet"
  + "rated it's bark.  More importantly, you see that the branches"
  + " below you are arranged in such a way that they would be easy"
  + " to climb down.\n");

  add_item ("ladder rope ladder",
    "There is a rope ladder hanging from somewhere"
  + " high up in the tree.  The leaves and branches prevent you fr"
  + "om seeing where.  It appears to have been recently used becau"
  + "se the center of the steps are slightly worn and have some di"
  + "rt on them.\n");

  add_item ("bridge rope bridge ropes rope",
    "The ropes are a little thin for your liking, but "
  + "seem sturdy enough.  The material seems very smooth, possibly"
  + " silk.\n");

  add_item ("handrail wooden handrail",
    "The wooden handrail is of good construction.  It is ap"
  + "proximately 1.5 meters high and has two boards going crosswis"
  + "e, to prevent you from falling in between.\n");

  add_item ("balcony wooden balcony",
    "The balcony is mad"
  + "e of wooden planks that extend outward from the trunk of the "
  + "tree.  They aren't very thick, but they feel very sturdy.  It"
  + " is about 2 meters wide from the trunk to the handrail, allow"
  + "ing plenty of room for movement.\n");

  add_sound ("The wooden planks of the balcony groan in futile protest of your weight. ");
  add_sound ("The view is beautiful up here! ");
  add_sound ("The sounds of battle, metal clashing against metal and agonizing death cries, come from the forest floor below. ");
  add_sound ("The tree branches sway in the wind. ");

  set_outdoors (4);

  add_monster (MONSTER_PATH + "elfarcher");
  add_monster (MONSTER_PATH + "elfarcher");
}

init()
{
   ::init();
     add_action("do_climb","climb");
}

do_climb(string what)
{
     if (!what) {return 0;}
     if (what == "tree")
    {
     write("You easily climb down the tree to the forest floor below.\n");
     message("standard", capitalize(THIS->query_name()) + " climbs down the "
      "tree.\n", ENV(THIS), THIS);
     THIS->move_player ( ROOM_PATH + "oforest15.c");
     return 1;
  }
     if (what == "ladder")
  {
   write("You scale the ladder up into the tree and emerge inside a treehouse.\n");
   message("standard", capitalize(THIS->query_name()) + " climbs the ladder up the "
    "tree and out of your sight.\n", ENV(THIS), THIS);
   THIS->move_player ( ROOM_PATH + "thouse1.c");
   return 1;
}
if (what != "tree" || what != "ladder")
  {
    write("Climb what?");
    return 1;
  }

}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

