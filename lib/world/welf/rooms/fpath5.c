// DATE        : Tue Feb 10 20:55:56 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Forest");
  set_long (
    "The forest seems to continue infinitely and vast it is indeed,"
  + " vast and wild. Tall tree surround you everwhere making you h"
  + "esitate at directions. Luckily the treecanopy is not so dense"
  + " here and some light can shine through it, otherwise it would"
  + " be impossible to navigate in here. A small path leads east a"
  + "nd south.");

  add_exit ("south", ROOM_PATH + "fpath4.c");
  add_exit ("east", ROOM_PATH + "fpath6.c");

  add_sound ("The trees creak in the wind.");
  add_sound ("A gloomy hoot of an owl echoes in the forest.");
  add_sound ("Birds shriek their alarms as you stumble forvard and step on a twig.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
