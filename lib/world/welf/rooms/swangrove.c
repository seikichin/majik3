// DATE        : Fri Jan 16 11:26:59 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Swangrove");
  set_long (
    "Almost impossibly beautiful trees in full blossom surround thi"
  + "s evergreen grove of druids. The sound of the flowing stream "
  + "nearby in the east soothes you and a strong inner strength fi"
  + "lls your heart. At the center of the grove stands a circle of"
  + " eight ancient looking stonepillars and at the center of the "
  + "circle stands a runecovered stone altar. You can feel the alt"
  + "ar beckoning you to touch its smooth stone and drawing you ne"
  + "ar the center. A faint trail leads west through thick thorny "
  + "bushes into the forest of Sol'daran.");

  add_exit ("west", ROOM_PATH + "fpath4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
