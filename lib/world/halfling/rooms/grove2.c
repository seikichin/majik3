// DATE        : Tue Feb 17 06:11:10 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Strawberry fields");
  set_long (
    "This area is covered with plants which produce strawberries. Y"
  + "ou can see a large wooden fence to the east and south. Thicke"
  + "r trees form the boundries to the north and west.");

  add_exit ("north", ROOM_PATH + "grove4.c");
  add_exit ("west", ROOM_PATH + "grove1.c");

  add_item ("fence",
    "The fence forms a perimeter to the south and east. It is wrapp"
  + "ed with barbed wire and would be very difficult to get throug"
  + "h without being seriously injured.\n");

  add_item ("plants",
    "The strawberry plants are "
  + "very numerous and are well kept.\n");

  add_sound ("You feel very relaxed in this place.");
  add_sound ("A furry varmint scurries through past your feet.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
