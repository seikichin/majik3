// DATE        : Sun Feb 22 00:29:44 1998
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
  + "ing from the east and heading your way fast. There are flames"
  + " everywhere, but for some reason it is still rather dark here"
  + ".");

  add_exit ("northwest", ROOM_PATH + "iforest7.c");
  add_exit ("west", ROOM_PATH + "oforest19.c");
  add_exit ("northeast", ROOM_PATH + "iforest9.c");
  add_exit ("north", ROOM_PATH + "iforest8.c");
  add_exit ("east", ROOM_PATH + "oforest20.c");

  add_item ("maples maple tree trees",
    "The beautiful maples are getting destroyed by the flames.\n");

  add_item ("floor forest_floor ground",
    "The "
  + "forest floor is ablaze and the fire is comming your way.\n");

  add_item ("canopy",
    "The "
  + "intense heat from the fire is licking the natural forest roof"
  + "top.\n");

  add_sound ("The fire is rapidly consuming the forest. ");
  add_sound ("A hollow voice echos in your head: Welcome to my nightmare. ");
  add_sound ("A frigid wind whips through the trees and the blaze flares up in response. ");
  add_sound ("Wild cheers in some muffled voices come from the east. ");

  set_outdoors (4);
  set_light (-1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
