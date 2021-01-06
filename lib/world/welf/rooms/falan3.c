// DATE        : Sun Feb  8 19:21:05 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Falan's way");
  set_long (
    "You're standing on Falan's way which runs through Endalen, the"
  + " part of the city where the nobility of Sol'daran live. Every"
  + "where around you treehouses and luxurious palaces rest on the"
  + " sturdiest treetops and numerous lanterns and lights bathe th"
  + "e area in a soft and calming light. Musical laughter echoes t"
  + "hrought the surrounding forest and you can hear almost painfu"
  + "lly beautiful singing coming from the nearest treehouse. The "
  + "street leads east and south.");

  add_exit ("south", ROOM_PATH + "falan2.c");
  add_exit ("east", ROOM_PATH + "falan4.c");

  add_sound ("A musical laughter echoes through the surrounding forest.");
  add_sound ("You can hear beautiful singing coming from the nearest treehouse.");
  add_sound ("A flock of swans flies high above the city towards west.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
