// DATE        : Tue Feb 17 05:59:53 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Apple Orchard");
  set_long (
    "You are surrounded by apple trees. They are packed close toget"
  + "her and do not allow for easy movement around. The orchard co"
  + "ntinues on to the north and east, the west leaves out of it. "
  + "There is also a fence running along the south edge of the gro"
  + "ve.");

  add_exit ("north", ROOM_PATH + "grove3.c");
  add_exit ("east", ROOM_PATH + "grove2.c");
  add_exit ("west", ROOM_PATH + "road6.c");

  add_item ("fence",
    "The fence forms a perimeter to the south side. It is wrapped w"
  + "ith barbed wire and would be very difficult to get through wi"
  + "thout being seriously injured.\n");

  add_item ("tree trees",
    "The trees are pretty large and"
  + " could probably provide twice the apples needed to support th"
  + "e Shire.\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
