// DATE        : Sun Nov  2 21:14:13 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Blood Alley");
  set_long (
    "The Blood alley and the west gate area have a bad reputation. "
  + "It is here where most of the crimes in Silvercreek are commit"
  + "ted. The alley leads south and in the north is a bazaar of so"
  + "me sort.");

  add_exit ("south", ROOM_PATH + "blood3.c");
  add_exit ("north", ROOM_PATH + "bazaar1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
