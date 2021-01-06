// DATE        : Mon Dec  8 05:41:12 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Apple Orchard");
  set_long (
    "The apple trees are plentiful in this section of the grove. Yo"
  + "u can see even more apple trees off to the south and some oth"
  + "er type of trees to the east. There is a fence which covers t"
  + "he western and northern borders of the grove.");

  add_exit ("south", ROOM_PATH + "grove1.c");
  add_exit ("east", ROOM_PATH + "grove4.c");

  add_item ("fence",
    "The fence lines the west and north side of the grove. It is wr"
  + "apped with barbed wire.\n");

  add_item ("tree trees",
    "The trees are strong and healthy. The"
  + "y must be tended to regularly.\n");

  add_sound ("A blue jay flies overhead.");
  add_sound ("You smell a sweet fragrance in the air.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
