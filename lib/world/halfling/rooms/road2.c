// DATE        : Sat Nov  1 22:03:31 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("shire");
  set_short ("Fishermans's Lane");
  set_long (
    "You are on the southern side of Fisherman's Lane. It is a simp"
  + "le dirt road. To the north is an intersection of roads. There"
  + " is a large, for halfling standards, hut to the east and a ga"
  + "rden to the west. The road goes north and south.");

  add_exit ("north", ROOM_PATH + "intersection.c");
  add_door ("east", ROOM_PATH + "bar", "door", "wooden", 0, 0, 0);  
  add_exit ("south", ROOM_PATH + "road3.c");

  set_outdoors(4);

  add_item ("fence",
    "The fence is made of wood and painted white. It stands about 2"
  + " feet tall.\n");

  add_item ("sign",
    "The Old Jaffers Pub.\n");

  add_item ("hut",
    "The hut is about normal size"
  + " for humans, which is rather large for halflings. It has quit"
  + "e a few windows and there is a sign next to the door.\n");

  add_item ("garden",
    "The gar"
  + "den is about 30 by 30 feet and is surrounded by a wooden pick"
  + "et fence. There is a burrow to the south that must house the "
  + "owners.\n");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
