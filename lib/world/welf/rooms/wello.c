// DATE        : Mon Dec 29 15:45:43 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Well opening");
  set_long (
    "This is the well opening where people of Sol'daran can get fre"
  + "sh water. An old looking stone well stands at the center of t"
  + "he forest surrounded opening. A path leads west to the mainst"
  + "reet of the city.");

  add_exit ("west", ROOM_PATH + "street.c");

  add_object ( ITEM_PATH + "well.c");

  add_item ("well",
    "The well is built from small blocks of stone. The well is deep"
  + " enough to get you killed in the fall so there's no point in "
  + "jumping down, but you can drink from it like the rest of the "
  + "people.\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
