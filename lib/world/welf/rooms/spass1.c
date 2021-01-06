// DATE        : Thu Dec 25 19:30:55 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Spring pass");
  set_long (
    "Lush darkgreen plants line the sides of the cobblestone street"
  + " which leads east from the holy swantemple. At the far end of"
  + " the street in east you can see a nice looking fountain squar"
  + "e where the people of this sylvan paradise can meet and relax"
  + ". A strong scent of springflowers fills your nostrils as you "
  + "trod along the street.");

  add_exit ("west", ROOM_PATH + "spring.c");
  add_exit ("east", ROOM_PATH + "spass2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
