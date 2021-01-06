// DATE        : Sun Nov  2 23:27:27 1997
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
  + " here. The city grocery is in the north while in the east the"
  + "re is a pet shop. The animals are nervous for some reason and"
  + " make a loud noise in there. The street continues to the west"
  + " The city wall blocks your way in south.");

  add_exit ("north", ROOM_PATH + "grocer.c");
  add_exit ("east", ROOM_PATH + "merchant6.c");
  add_exit ("west", ROOM_PATH + "merchant4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
