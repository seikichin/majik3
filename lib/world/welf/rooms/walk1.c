// DATE        : Wed Dec 24 23:24:02 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("King's walk");
  set_long (
    "The King's walk leads east from here towards the huge tree tha"
  + "t holds the palace of the lord and lady of the tanir realm on"
  + " its highest perches. The street here is made of some white a"
  + "nd silvery stones and covered in colourful flowers. The stree"
  + "t leads east and west.");

  add_exit ("west", ROOM_PATH + "square.c");
  add_exit ("east", ROOM_PATH + "walk2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
