// DATE        : Fri Oct 31 14:32:14 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Stables");
  set_long (
    "The shadowy room has few poles and piles of hay for the horses"
  + " and more uncommon mounts. Strong smell of animals and old ha"
  + "ypiles floating in the air is quite nauseous. A small lantern"
  + " gives its light to the room leaving the corners dark. A door"
  + "way leads north to the inn yard.");

  add_exit ("north", ROOM_PATH + "innyard.c");

  add_sound ("The strong smell of horses and other animals is making your head ache.");
  add_sound ("Small black flies buzz around the lantern near the ceiling line.");
  add_sound ("You can hear the loud sounds of merrymaking in the Tavern.");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
