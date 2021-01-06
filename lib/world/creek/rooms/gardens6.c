// DATE        : Mon Nov  3 21:10:14 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Hall of Justice");
  set_long (
    "You've standing in a big hall again. The walls are made from t"
  + "he same strange white stone as everything in here. The walls "
  + "here are laid full of different weapons, shields and armours."
  + " The weapons are bolted firmly to the wall so don't think of "
  + "stealing them. Obviously the knights of Ivory prefer good wea"
  + "pons over words in defending the city. A door leads south.");

  add_exit ("south", ROOM_PATH + "gardens4.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
