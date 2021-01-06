// DATE        : Mon Nov 10 01:04:43 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("inner_forest");
  set_short ("Deep inside the Dark Forest");
  set_long (
    "The forest has greatly thinned out here. There is a clearing f"
  + "ormed by the lack of trees and vegatation. In the center of t"
  + "he clearing is a stange mist with a green tinge to it. The op"
  + "en sky looms over head, but it is still very dark.");

  add_exit ("northeast", ROOM_PATH + "iforest3.c");
  add_exit ("north", ROOM_PATH + "iforest1.c");
  add_exit ("northwest", ROOM_PATH + "iforest2.c");
  add_exit ("west", ROOM_PATH + "iforest4.c");
  add_exit ("southwest", ROOM_PATH + "iforest7.c");
  add_exit ("south", ROOM_PATH + "iforest8.c");
  add_exit ("southeast", ROOM_PATH + "iforest9.c");
  add_exit ("east", ROOM_PATH + "iforest6.c");

  add_item ("mist",
    "The strange green mist slowly swirls in a circle.  The frigid "
  + "chill you have been feeling seems to eminate from here.  You "
  + "think you can see some kind of structure inside but you would"
  + " have to enter the mist to get a clear view.\n");

  add_item ("maples maple tree trees",
    "The forest is fu"
  + "ll of healthy, thick maple trees.  The trees are tall and app"
  + "ear to be in perfect health.\n");

  add_item ("floor forest floor ground",
    "The forest floor is only dirt ex"
  + "cept for a few blades of grass here and there.\n");

  add_sound ("A hollow voice echos in your head:  Leave now, or spend eternity in my hell. ");
  add_sound ("The temprature here is FREEZING, yet there isn't the slightest breeze. ");
  add_sound ("Thick, impenatrable darkness surrounds you. ");
  add_sound ("It is so dark, you feel like you're in a sea of blackness. ");

  set_light (-2);

  add_monster (MONSTER_PATH + "skeleton");
}

init()
{
   ::init();
     add_action("enter_mist","enter");
}

enter_mist(string what)
{
     if (what != "mist")
{
return 0;
}
   else
{
   write("You step into the mist feel the cool droplets of green liquid over your skin.\n");
   message("standard", capitalize(THIS->query_name()) + " steps into the green swirling "+
    "mist.\n", ENV(THIS), THIS);
   THIS->move_player ( ROOM_PATH + "mist1.c");
   return 1;
}
}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

