// DATE        : Fri Feb 13 15:02:48 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Narrow ropebridge");
  set_long (
    "You're walking on a swaying ropebridge that connects the two t"
  + "reetops in north and south. A strange moss covered treehouse "
  + "has been built on the treetop in south and in the north there"
  + " is a sturdy looking platform. Up here you can see the mainst"
  + "reet of the city below you in the east and some distance in t"
  + "he west there's a blooming orchard of apple and plumtrees.");

  add_exit ("south", ROOM_PATH + "herbalist.c");
  add_exit ("north", ROOM_PATH + "treetop4.c");

  add_item ("house treehouse",
    "The house is covered with moss and lichen and on its roof grow"
  + "s several small bushes. Strangely blue smoke rises from a chi"
  + "mney among those bushes and a scent of herbs drifts in from t"
  + "here to welcome you. A sign above the door indicates the hous"
  + "e as a herbal shop.\n");

  add_item ("orchard",
    "Ripe apples and plums just waiting to be "
  + "picked up. You bet no one would notice if you went there to e"
  + "at some of them.\n");

  add_sound ("The ropebridge sways slowly from side to side, but seems to carry your weight easily enough.");
  add_sound ("The birds chirp happily in the near by tree.");
  add_sound ("Blue smoke rises from the chimney of the treehouse in south.");
  add_sound ("A mixed scent of apples, plums, mushrooms and exotic herbs makes you sneeze.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
