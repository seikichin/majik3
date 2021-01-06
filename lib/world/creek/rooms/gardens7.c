// DATE        : Mon Nov  3 21:14:33 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Hall of Honour");
  set_long (
    "This hall is full of paintings and statues. All of the heroes "
  + "and glory. The paintings are describing the wars the knights "
  + "have fought - and won. The statues are made to honour some ve"
  + "ry important persons in the history of order. A door leads no"
  + "rth.");

  add_exit ("north", ROOM_PATH + "gardens5.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
