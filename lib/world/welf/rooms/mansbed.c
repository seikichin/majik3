// DATE        : Sat Feb 21 16:44:42 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Bedroom");
  set_long (
    "You stand within a simple and plain bedchamber. A doublebed wi"
  + "th a canopy and a small table next to it have been placed bes"
  + "ide the south wall. A green crystal glows dimly on the table."
  + " There's also a strange mirror on the wall.");

  add_exit ("east", ROOM_PATH + "mansden.c");

  add_item ("bed canopy",
    "A huge and luxurious bed with an elaborate red canopy over it."
  + " The bed looks very comfortable with its pluffy embroidered p"
  + "illows.\n");

  add_item ("table crystal",
    "Small multifaceted crystal that glows dimly with a gr"
  + "een light.\n");

  add_item ("mirror",
    "Flowing elven runes have been carved on the mirror"
  + "'s mahogany frames. They read: ^lalande No matter how long yo"
  + "u stare at your reflection. The true beautiness remains in yo"
  + "ur heart.\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
