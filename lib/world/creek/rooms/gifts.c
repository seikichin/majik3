// DATE        : Sat Nov  1 21:48:07 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Innern part of the temple, the hall of gifts");
  set_long (
    "The hall of gifts is for the true believers who want to sacrif"
  + "ice something valuable to their gods. A white altar is placed"
  + " on a pedestal at the center of the hall, stairs lead to it. "
  + "The altar has been put higher so that it would be nearer the "
  + "heavens and the gods. Arched doorways lead to all four direct"
  + "ions. You can see the cemetary to the north and south through"
  + " the arched doorways.");

  add_exit ("south", ROOM_PATH + "ceme2.c");
  add_exit ("north", ROOM_PATH + "ceme1.c");
  add_exit ("east", ROOM_PATH + "temple.c");
  add_exit ("west", ROOM_PATH + "last.c");

  add_item ("altar pedestal stairs",
    "White marble stairs lead to the pedestal and the altar, the hi"
  + "gher the better\nwhen dealing with the gods said a famous prop"
  + "het Cal-Nishar once.\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
