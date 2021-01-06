// DATE        : Mon Nov  3 20:49:45 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Outside the west gate");
  set_long (
    "You're standing at the west gate of Silvercreek. The gates are"
  + " usually open for anyone but in case of enemy they will hold "
  + "fast. They are made of pure adamantium and are almost undestr"
  + "uctable. A lamp is hanging on one wall giving some light duri"
  + "ng the nights. A road leads west from here.");

  add_exit ("east", ROOM_PATH + "underwgate.c");
  add_exit ("west", "/world/y87x345");

  add_object (MONSTER_PATH + "gateguard2");
  add_object (MONSTER_PATH + "gateguard2");
  add_object (MONSTER_PATH + "gateguard2");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
