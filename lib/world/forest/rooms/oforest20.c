// DATE        : Mon Nov 10 00:57:21 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  int i;

  set_short ("Dark Forest");
  set_long (
    "This area is completly devoid of any plant life. The ground sh"
  + "ows the scars of a forest fire. There is a shabby, hastily er"
  + "ected tent in the center of the clearing. The sky above is wi"
  + "de open yet the impenatrable darkness remains. The smell of b"
  + "urned wood and plants is fresh in the air and you can vaguely"
  + " see flames in the distance all around you.");

  add_exit ("west", ROOM_PATH + "oforest21.c");
  add_exit ("northeast", ROOM_PATH + "oforest18.c");
  add_exit ("north", ROOM_PATH + "iforest9.c");
  add_exit ("northwest", ROOM_PATH + "iforest8.c");

  add_item ("tent",
    "The tent is a piece of shit.  Whoever made it wasn't very skil"
  + "led.\n");

  add_item ("floor forest_floor ground",
    "The forest floor completly barren.\n");

  add_sound ("You are amazed at the complete and utter destruction of the forest. ");
  add_sound ("A hollow voice echos in your head: Welcome to my nightmare. ");

  set_outdoors (4);
  set_light (-1);

  add_monster (MONSTER_PATH + "rayak");
  add_monster (MONSTER_PATH + "goblin");
  add_monster (MONSTER_PATH + "goblin");
}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

