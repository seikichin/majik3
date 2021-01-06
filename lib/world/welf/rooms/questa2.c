// DATE        : Sun Dec 28 01:09:52 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Small sideroom");
  set_long (
    "This rooms is a little shadowy. Only a small chandelier gives "
  + "its soft ligt to the room, though it is enough to make the go"
  + "lden leafpatterns painted on the walls to glimmer faintly. St"
  + "urdy looking stairs lead upstairs. A doorway leads north to t"
  + "he entrance hall and a door leads east from here.");

  add_exit ("east", ROOM_PATH + "quegua.c");
  add_exit ("up", ROOM_PATH + "questa6.c");
  add_exit ("north", ROOM_PATH + "quentran.c");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
