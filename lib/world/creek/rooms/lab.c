// DATE        : Mon Nov  3 20:31:11 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A small laboratory");
  set_long (
    "The room is filled with potions and vials, experimental device"
  + "s and strange apparatuses. A bookshelf is on the southern wal"
  + "l, the books in it are all blackened by failed chemical exper"
  + "iments, or rather blasts which result in such cases. A door l"
  + "eads north.");

  add_exit ("north", ROOM_PATH + "lib.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
