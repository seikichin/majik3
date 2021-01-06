// DATE        : Fri Nov  7 05:51:16 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("market");
  set_short ("Market Road");
  set_long (
    "You are on a dirt road known as Market Road. The halfling vill"
  + "age, the Shire, is to the east. The rest of the area is just "
  + "grassy, rolling plains. The road heads west, out of the Shire"
  + ".");

  add_exit ("west", "/world/y473x192.c");
  add_exit ("east", ROOM_PATH + "mroad1.c");

  add_object (ITEM_PATH + "sign.c");

  set_outdoors(4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
