// DATE        : Sun Nov  2 20:30:34 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marketplace");
  set_long (
    "The Market street ends here at the market place, or rather sta"
  + "rts from here stretching far to the south towards the Merchan"
  + "t street. The Market place itself is filled with people, sale"
  + "smen and the customers. Tens of booths and tents have been ma"
  + "de here and all kinds of things are on sale here. The Academy"
  + " of Magic can be seen on the north side of the market place, "
  + "its towers dominating the view in north. The market place con"
  + "tinues to the east, west and north.");

  add_exit ("south", ROOM_PATH + "market1.c");
  add_exit ("north", ROOM_PATH + "marketp5.c");
  add_exit ("east", ROOM_PATH + "marketp4.c");
  add_exit ("west", ROOM_PATH + "marketp6.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
