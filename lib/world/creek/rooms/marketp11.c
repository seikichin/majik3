// DATE        : Sun Nov  2 20:34:40 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marketplace, at the academy doors");
  set_long (
    "You're standing in front of the Academy of Magic. Its doors ar"
  + "e in the north, granite stairs lead up to them. The massive b"
  + "uilding casts a huge shadow over the market place. Some young"
  + " spell students hurry in and out of the Academy on their mast"
  + "ers' errands. Over the doors of the Academy is engraved an in"
  + "scription. The market place stretches itself to the east, wes"
  + "t and south, where a curious looking booth can be seen.");

  add_exit ("south", ROOM_PATH + "marketp8.c");
  add_exit ("north", ROOM_PATH + "acadent.c");
  add_exit ("east", ROOM_PATH + "marketp12.c");
  add_exit ("west", ROOM_PATH + "marketp10.c");

  add_object (MONSTER_PATH + "student");

  add_item ("inscription doors engraving",
    "Over the doors is engraved in gothic letters: 'Ars Longa, Vita"
  + " Brevis'\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
