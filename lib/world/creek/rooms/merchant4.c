// DATE        : Sun Nov  2 23:08:33 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Merchant street");
  set_long (
    "You're walking along the Merchant street which is the commerci"
  + "al part of the city. The most of the shops of Silvercreek are"
  + " here. The Armourer's shop is in the west. In the east you ca"
  + "n see the city Grocery and the Pet shop. The street continues"
  + " to the east and west. The city wall blocks your way in south"
  + ". A short street leads north where Market street begins.");

  add_exit ("north", ROOM_PATH + "market4.c");
  add_exit ("east", ROOM_PATH + "merchant5.c");
  add_exit ("west", ROOM_PATH + "merchant3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
