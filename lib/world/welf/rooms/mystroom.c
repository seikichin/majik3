// DATE        : Thu Feb 26 19:01:26 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Octagonal room");
  set_long (
    "The place remains quite dusky though eight chandeliers have be"
  + "en placed on the corners of this octagon shaped room. A thick"
  + " exotic looking carpet covers most of the floor and here and "
  + "there are scattered various pots and jars. A writing desk has"
  + " been placed near one of the walls and beside it a large book"
  + "case. Some shelves and boxes have been placed neatly beside t"
  + "he other walls.");

  add_exit ("west", ROOM_PATH + "mysthouse.c");

  add_item ("box boxes shelf shelves",
    "The shelves and boxes are all filled with strange and exotic s"
  + "tuff, probably to be used with spells.\n");

  add_item ("bookcase",
    "The bookcase is neatly"
  + " filled with books, each of them has a symbol of a golden lea"
  + "f on its back. Unfortunately the books are written in some ki"
  + "nd of a code you can't begin to understand. Whatever secrets "
  + "they have, will remain secret.\n");

  add_item ("pots jars pot jar",
    "You can't but guess what the j"
  + "ars and pots hold inside, but they smell strange. You wouldn'"
  + "t risk tasting the stuff inside, could very well be poison.\n");

  add_item ("carpet",
    "T"
  + "hick and fuzzy, it feels like a mosscover under your feet. A "
  + "golden leaf symbol has been embroidered on its center.\n");

  add_item ("desk",
    "An ord"
  + "inary wooden writing desk with no drawers in it.\n");

  add_item ("chandelier chandeliers",
    "There are ei"
  + "ght of the chandeliers and each of them has eight purple cand"
  + "les on them. They bathe the room in a deep red glow, that fee"
  + "ls quite unnerving.\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
