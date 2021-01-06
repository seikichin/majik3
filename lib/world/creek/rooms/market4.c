// DATE        : Sat Nov  1 23:51:39 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("On Market street");
  set_long (
    "The Market street runs in north south direction. Quite a dista"
  + "nce in the north you can see the market place. The cobbleston"
  + "ed street is filled with litter. You can hear the sound of me"
  + "tal clanging against metal echoing from the smithy some dista"
  + "nce in the south west. Some people hurry past you obviusly th"
  + "inking you are a ruffian of some sort. The Merchant street is"
  + " in the south and the Southern Temple street in the north.");

  add_exit ("south", ROOM_PATH + "merchant1.c");
  add_exit ("north", ROOM_PATH + "market3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
