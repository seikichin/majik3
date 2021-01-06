// DATE        : Fri Nov  7 02:51:37 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("shire");
  set_short ("Jaffer's Pub");
  set_long (
    "There is a large, square bar in the center of the room. Barsto"
  + "ols line every side of it and there are also chairs and table"
  + "s all around the room. There is a sign above the bar with a l"
  + "ist of drinks and food items on it. The structure is made com"
  + "pletly of wood and was contructed very well.");

  add_door ("west", ROOM_PATH + "road2", "door", "wooden", 0, 0, 0);  

  set_light(1);

  add_item ("stools stool",
    "There are barstools surrounding the bar. They are about 1 and "
  + "1/2 feet high.\n");

  add_item ("chairs tables chair table",
    "There are many chairs and tables around the ro"
  + "oms. The people of the village must drink alot because this p"
  + "lace could probably hold them all at once.\n");

  add_item ("bar",
    "The bar is square "
  + "and sits in the center of the room. It is made of solid oak a"
  + "nd is buffed to a beautiful shine. There are a few lanterns p"
  + "laced around the bar.\n");

  add_item ("sign list",
    "These are the things you m"
  + "ay order from Jaffer:\nItem:                               Cos"
  + "t:\nBeer                                2 Gold\nWine           "
  + "                     4 Gold\nShot                             "
  + "   1 Gold\nTo order something type order <name>.\n");

  add_monster (MONSTER_PATH + "jaffer.c");
  add_monster (MONSTER_PATH + "patan.c");
  add_monster (MONSTER_PATH + "joel.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

