// DATE        : Tue Nov 11 22:36:10 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Temple Square");
  set_long (
    "You've arrived at the stairs of the High Temple of Truth. The "
  + "square before its doors is simply known as the temple square."
  + " A fountain gurgles happily at the center of the square. Peop"
  + "le hurry on their daily routines here and there, some of them"
  + " even greeting you. A granite statue stands here, its arms sp"
  + "read wide as if to embrace the sky. Streets continue to the"
  + " north, east and south from here and granite stairs lead west"
  + " to the doors of the temple.");

  add_exit ("west", ROOM_PATH + "temple.c");
  add_exit ("south", ROOM_PATH + "candle2.c");
  add_exit ("north", ROOM_PATH + "candle1.c");
  add_exit ("east", ROOM_PATH + "majik1.c");

  add_object (ITEM_PATH + "fountain");
  add_object (MONSTER_PATH + "cityguard");
  add_object (MONSTER_PATH + "lissa");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
