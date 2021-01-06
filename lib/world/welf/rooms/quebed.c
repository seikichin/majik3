// DATE        : Tue Mar  3 23:26:15 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marvellous bedchamber");
  set_long (
    "A huge and luxurious doublebed with a finely embroidered canop"
  + "y takes up most of the space in this small chamber. Elaborate"
  + " tapestries have been hung on the walls and the ceiling has b"
  + "een painted with warm golden colors. A soft red carpet covers"
  + " the whole floor.");

  add_exit ("east", ROOM_PATH + "queleg.c");

  add_item ("tapestry tapestries",
    "They all seem to depict the swanhall of Que-Moran. Splendid fe"
  + "asts and parties, you wish you had been there then.\n");

  add_item ("bed doublebed canopy",
    "Fine and "
  + "soft silken blankets and pillows beckong you to sleep in the "
  + "luxurious doublebed, but you doubt the owner would like to fi"
  + "nd someone in his or her bed. An elaborately embroidered cano"
  + "py covers the bed.\n");

  add_item ("carpet",
    "The red carpet covers the whole floor and "
  + "feels nice under your feet. Must be nice to have such a fine "
  + "carpet during the cold winters.\n");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
