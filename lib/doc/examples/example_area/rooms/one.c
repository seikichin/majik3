// DATE        : Fri Jan 23 13:13:00 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : people

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("room in example area");
  set_long (
    "You are in second room room in exampample area. Thera is huge "
  + "statue in the middle on the room Ground has made solid stone "
  + "... when you do see this please do better desc...");

  add_exit ("north", ROOM_PATH + "entrance.c");
  add_item ("statue","It's a statue of great Namhas. Statue is huge atleast 20
feet high and it's pure gold.\n");

  set_outdoors (4);
  set_light (1);
  set_no_explore (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
