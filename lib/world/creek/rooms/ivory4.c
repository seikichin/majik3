// DATE        : Sun Nov  2 22:43:11 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Ivory street");
  set_long (
    "You're walking along Ivory street which leads north and south "
  + "towards the main entrance of the Ivory Halls. You can see t"
  + "he garden over the fence in west. A short street leads east t"
  + "o Chapel street in south.");

  add_exit ("south", ROOM_PATH + "ivory3.c");
  add_exit ("north", ROOM_PATH + "ivory5.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
