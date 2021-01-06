// DATE        : Sat Nov  1 21:13:33 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Balcony of the tavern");
  set_long (
    "The balcony is more like a platform for there aren't any raili"
  + "ngs. It's built on one of the huge oak's limbs like several o"
  + "f the accommodation rooms of the tavern. The oak's dense canopy "
  + "forms a roof over the balcony and the light beams are filtere"
  + "d green when they reach the balcony. A narrow ropebri"
  + "dge leads west from here to another treehouse. The tavern's r"
  + "eception room is in the east.");

  add_exit ("west", ROOM_PATH + "innrope.c");
  add_door ("east", ROOM_PATH + "reception.c", "door", "wooden", 0, 0, 0);

  add_sound("You can hear the loud merrymaking downstairs.");
  add_sound("Birds chirp happily on the nearby branches.");
  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
