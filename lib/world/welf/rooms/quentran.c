// DATE        : Fri Mar 13 00:00:08 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Entrance hall");
  set_long (
    "You're standing in a beautifully decorated entrance hall of Qu"
  + "e-Moran, the treepalace of the lord and lady of Sol'daran. Th"
  + "e walls are painted full of intricate flower and leaf pattern"
  + "s and the floor here is covered with a soft green mosslike ca"
  + "rpet. A strange green dimly glowing crystal is embedded on th"
  + "e ceiling bathing the room in a soft green light. Small doorw"
  + "ays lead north and south.");

  add_exit ("west", ROOM_PATH + "quegat.c");
  add_exit ("south", ROOM_PATH + "questa2.c");
  add_exit ("north", ROOM_PATH + "questa1.c");
  add_exit ("east", ROOM_PATH + "queswo.c");

  add_item ("carpet",
    "The carpet feels like moss under your feet and that's probably"
  + " what it is made of.\n");

  add_item ("patterns walls decorations",
    "The walls are painted full of silvery le"
  + "aves and golden flowers that flow in intricate patterns.\n");

  add_item ("crystal",
    "The "
  + "crystal glows softly with a green light bathing the hall in a"
  + "n alluring way.\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
