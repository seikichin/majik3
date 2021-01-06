// DATE        : Sat Nov  1 21:37:35 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Cleric's Sanctuary");
  set_long (
    "Thousand white candles burn here with the flame of holiness. P"
  + "ictures of saints and legends from the dawn of time decorate "
  + "the white painted room. The rich smell of incense fills the a"
  + "ir here and the heavenly voices echo from the hall south from"
  + " here.");

  add_exit ("south", ROOM_PATH + "temple.c");

  add_item ("paintings pictures",
    "Pictures of legends and saints long forgotten by the normal pe"
  + "ople decorate\nthe sanctuary. You recognize one among them tho"
  + "ugh, Elya the Holy, founder\nof the Temple of Truth.\n");

  add_item ("candles flame",
    "Thousand "
  + "candles which burn with the flame of holiness. They are said "
  + "to\nburn eternally.\n");

  set_light (1);

  add_object (MONSTER_PATH + "octavius");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
