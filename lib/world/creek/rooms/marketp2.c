// DATE        : Sun Nov  2 20:31:25 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marketplace, the southeast corner");
  set_long (
    "You're actually on the Gate street for it runs from the Southe"
  + "rn gate to the northern gate but this is also part of the eno"
  + "rmous market place. The place is really crowded, salesmen aro"
  + "und the world have come here to show their products and sell "
  + "them for sky high prices. Exotic smells fill your nostrils as"
  + " you breathe the air. The northern gate is a short distance t"
  + "o the north from here. The gatestreet continues to the south "
  + "and the market place stretches far to the west and north.");

  add_exit ("south", ROOM_PATH + "gate1.c");
  add_exit ("north", ROOM_PATH + "marketp3.c");
  add_exit ("west", ROOM_PATH + "marketp4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
