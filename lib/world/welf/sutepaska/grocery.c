// DATE        : Tue Oct 28 22:34:09 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The City Grocery");
  set_long (
    "You enter a dimly lit wooden hut. The walls are lined with shelves "
  + "and items. A scent of spices and freshly baked bread fills the air"
  + ". A small sign has been nailed in the front of the desk at the bac"
  + "k of the room. A door leads out to the street in west.");

  add_exit ("west", ROOM_PATH + "street.c");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
