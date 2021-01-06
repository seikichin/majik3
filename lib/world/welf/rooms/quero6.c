// DATE        : Sun Dec 28 01:48:19 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Simply furnished room");
  set_long (
    "This small room has only few pieces of furniture. A writing de"
  + "sk and a chair are placed before the window on the south wall"
  + ". East and west walls are almost completely covered by two bo"
  + "okcases. A door leads north from here.");

  add_exit ("north", ROOM_PATH + "questa6.c");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
