// DATE        : Sun Dec 28 01:46:48 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Neatly furnished room");
  set_long (
    "This small bedroom is neatly furnished. A comfortable looking "
  + "bed has been placed before the window on the south wall. A bo"
  + "okcase, writing desk and a chair are the rest of the furnitur"
  + "e here. A soft fuzzy carpet covers the floor. A door leads no"
  + "rth.");

  add_exit ("north", ROOM_PATH + "queha4.c");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
