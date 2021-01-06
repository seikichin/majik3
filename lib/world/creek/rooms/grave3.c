// DATE        : Sun Nov  2 22:41:26 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The crossing of Grave and Southern Temple streets");
  set_long (
    "You're now at the crossing of Grave street and Southern Temple"
  + " street. Temple street stretches itself to the east and Grave"
  + " street leads north and south. You can hear merry making from"
  + " a building near you in the south east. The city cemetary is "
  + "in the north east. A plume of smoke rises from the smithy in "
  + "south east.");

  add_exit ("south", ROOM_PATH + "grave5.c");
  add_exit ("north", ROOM_PATH + "grave6.c");
  add_exit ("east", ROOM_PATH + "stemple3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
