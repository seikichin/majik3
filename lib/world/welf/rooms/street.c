// DATE        : Mon Dec 29 15:50:05 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Alquamen, the path of the swan");
  set_long (
    "You're walking along the main street of the Tanir city which r"
  + "uns from the gates to the holy swan temple in the north. The "
  + "street is covered with colourful leaves and flowers. Trees ar"
  + "ch over the street on both sides of the street casting soft s"
  + "hadows over you. Here and there you can see ladders and stair"
  + "s spiralling up to the trees where the elves build their hous"
  + "es. The ground is reserved for those foreigners who prefer th"
  + "e ground under their feet. Small paths lead east and west whi"
  + "le the street continues north and south.");

  add_exit ("south", ROOM_PATH + "street2.c");
  add_exit ("east", ROOM_PATH + "wello.c");
  add_exit ("north", ROOM_PATH + "summer.c");
  add_exit ("west", ROOM_PATH + "torchard.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
