// DATE        : Tue Feb  3 19:35:30 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("In front of a small cabin");
  set_long (
    "You're standing in front of a small cabin. It blends so well w"
  + "ith the surrounding forest that it's difficult to notice it e"
  + "ven at a distance as near as now. Moss, lichen and bushes gro"
  + "w on its roof and the walls are all painted in woodland green"
  + ". A revealing plume of smoke however rises from a pipe on the"
  + " roof and a scent of cooked rabbit drifts here from inside th"
  + "e cabin. A faint trail leads north through the forest.");

  add_exit ("north", ROOM_PATH + "fpath2.c");
  add_door ("south", ROOM_PATH + "hunter.c","door", "wooden", ITEM_PATH + "hunterkey.c", 30, 1);

  add_item ("cabin moss lichen bushes",
    "You can't but wonder how well the cabin is camouflaged. Whethe"
  + "r the nature has done it over a long period of time or the on"
  + "e who did it was genius the work is magnificent. Bushes, moss"
  + " and lichen grow naturally on the roof and the paint has been"
  + " well chosen to fit the surroundings. The aroma of cooked rab"
  + "bit drifts from inside making you lick you lips hungrily.\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
