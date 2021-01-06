// DATE        : Sun Nov  2 23:27:00 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Merchant street");
  set_long (
    "You're standing in front of the pet shop now. The smell and no"
  + "ise of the animals is quite irritating. The pet shop is in ea"
  + "st and in the west there's a grocery. The Merchant street lea"
  + "ds west from here.");

  add_exit ("east", ROOM_PATH + "petshop.c");
  add_exit ("west", ROOM_PATH + "merchant5.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
