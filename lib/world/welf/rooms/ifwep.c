// DATE        : Fri Feb 13 15:24:13 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("In front of a weaponshop");
  set_long (
    "You're standing on a sturdy platform in front of a peculiar lo"
  + "oking treehouse. The platform rests on the top of a tall and "
  + "strong pine. The treehouse isn't as beautiful as the others y"
  + "ou have seen and it doesn't fit in as well either but nonethe"
  + "less it has been built here near the center of the city so it"
  + " must have some importance. A sign has been nailed above its "
  + "door. A narrow and very flimsy looking ropebridge leads west "
  + "from here to another treetop near the swantemple.");

  add_exit ("east", ROOM_PATH + "wep.c");
  add_exit ("west", ROOM_PATH + "rope5.c");

  add_item ("sign door",
    "              ,-------------------------.\n              |**   "
  + "       *   *        |\n              |*           *   *       "
  + " |\n              |** OL'DARAN * * * EAPONRY|\n              | "
  + "*          * * *        |\n              |**           * *    "
  + "     |\n              |                         |\n            "
  + "  `========================='\n");

  add_sound ("A cling of steel on steel echoes from the shop.");
  add_sound ("You here some muttering coming from the shop.");
  add_sound ("You can see a flock of birds flying high above the city.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
