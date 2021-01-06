// DATE        : Sun Dec 28 01:09:23 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Small sideroom");
  set_long (
    "This room is a little shadowy. Only a small chandelier gives i"
  + "ts soft light to the room, though it is enough to make the si"
  + "lvery flowerpatterns painted on the walls to shimmer enchanti"
  + "ngly. Sturdy looking stairs lead upstairs. A doorway leads so"
  + "uth to the entrance hall and a door leads east from here. ");

  add_exit ("south", ROOM_PATH + "quentran.c");
  add_exit ("east", ROOM_PATH + "quese.c");
  add_exit ("up", ROOM_PATH + "questa5.c");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
