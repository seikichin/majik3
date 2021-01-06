// DATE        : Mon Nov 10 00:54:06 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Dark Forest");
  set_long (
    "A wave of searing heat blasts you as you enter the area. The f"
  + "orest is on fire and being devoured rapidly. The fire is comm"
  + "ing from the southwest and heading your way fast. There are f"
  + "lames everywhere, but for some reason it is still rather dark"
  + " here.");

  add_exit ("west", ROOM_PATH + "iforest9.c");
  add_exit ("southwest", ROOM_PATH + "oforest20.c");
  add_exit ("northeast", ROOM_PATH + "oforest16.c");
  add_exit ("north", ROOM_PATH + "oforest14.c");
  add_exit ("northwest", ROOM_PATH + "iforest6.c");

  add_item ("floor forest_floor ground",
    "The forest floor is ablaze and the fire is comming your way.\n");

  add_item ("maples maple tree trees",
    "M"
  + "ost of the trees are on fire and the few that aren't are goin"
  + "g to be soon.  The beautiful forest is rapidly disappearing.\n"
  + "");

  add_item ("canopy",
    "The intense heat from the fire is licking the natural forest "
  + "rooftop.\n");

  add_sound ("The fire is rapidly consuming the forest. ");
  add_sound ("A hollow voice echos in your head: Welcome to my nightmare. ");
  add_sound ("A frigid wind whips through the trees and the blaze flares up in response. ");
  add_sound ("Wild cheers in some muffled voices come from the southwest. ");

  set_outdoors (4);
  set_light (-1);

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
   write("You grab a branch and start to climb the tree.  You hurry quickly as the flames "+
    "lick at your heels.  Luckily you make it up to a balcony above with only a few singed "+
    "hairs.\n");
   message("standard", capitalize(THIS->query_name()) + " climbs up the "+
    "tree.\n", ENV(THIS), THIS);
   THIS->move_player ( ROOM_PATH + "bridge10.c");
   return 1;
}
}



// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

