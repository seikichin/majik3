// DATE        : Sun Nov  2 20:31:07 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marketplace");
  set_long (
    "People hurry on their business here and the noise gives you a "
  + "headache. Salesmen shout their prices and the customers argue"
  + " too loudly with them. The Market place itself continues to t"
  + "he west, north and south. In the north the massive building o"
  + "f the Academy of Magic dominates the view. In the west you ca"
  + "n see a curious looking booth. The citygates are in the east."
  + "");

  add_exit ("south", ROOM_PATH + "marketp2.c");
  add_exit ("north", ROOM_PATH + "marketp12.c");
  add_exit ("east", ROOM_PATH + "underneg.c");
  add_exit ("west", ROOM_PATH + "marketp8.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
