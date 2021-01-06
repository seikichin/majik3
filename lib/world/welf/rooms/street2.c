// DATE        : Thu Dec 25 19:20:17 1997
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
  + "street is covered in colourful leaves. The street is lined wi"
  + "th trees arching over it and here and there you can see ladde"
  + "rs and stairs spiralling up to the trees where the elves buil"
  + "d their houses. The ground is reserved for the travellers, in"
  + "ns and shops. There's a strange building built in the tree we"
  + "st from here and stairs spiral up to it's door. On the eastsi"
  + "de of the street there is a curious looking inn and stables. "
  + "The street continues to north and south.");

  add_exit ("south", ROOM_PATH + "gates.c");
  add_exit ("west", ROOM_PATH + "herbal.c");
  add_exit ("east", ROOM_PATH + "innyard.c");
  add_exit ("north", ROOM_PATH + "street.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
