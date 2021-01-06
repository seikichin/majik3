// DATE        : Sun Nov  9 23:27:57 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("On the rope bridge");
  set_long (
    "You are standing, barely, on a rope bridge. It is hardly a bri"
  + "dge, however, since it is only made up of three ropes. You st"
  + "and on one, while you brace yourself with the two on either s"
  + "ide of you. The ropes stretch from the treetops and provide f"
  + "or quick movement around the forest, avoiding the blockage of"
  + " the trees and vegatation. The forest floor is quite far belo"
  + "w you. A fall from this height would mean certain death.");

  add_exit ("south", ROOM_PATH + "bridge10.c");
  add_exit ("north", ROOM_PATH + "bridge15.c");

  add_item ("bridge rope bridge ropes rope",
    "The ropes are a little thin for your liking, but seem sturdy e"
  + "nough.  The material seems very smooth, possibly silk.\n");

  add_item ("floor forest floor ground",
    "There "
  + "ground is very far below you.  You had better be careful up h"
  + "ere.\n");

  add_sound ("A fierce winds comes suddenly from nowhere, violently tossing the bridge about. ");
  add_sound ("The sounds of battle, metal clashing against metal and agonizing death cries, come from the forest floor below. ");
  add_sound ("The rope bends from the stress of your weight and your heart skips a beat. ");
  add_sound ("The view is beautiful up here! ");
  add_sound ("Your knuckles are turning bright white from gripping the rope so tensely. ");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
