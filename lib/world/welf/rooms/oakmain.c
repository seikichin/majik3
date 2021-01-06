// DATE        : Thu Feb 26 19:59:13 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Mainroom");
  set_long (
    "This hall-like room looks very homely. Oil lanterns hang down "
  + "from the beams that support the ceiling and bathe the room in"
  + " a deep crimson glow. A stove, built so that it won't burn th"
  + "e house to ashes, has been built into the west wall. At the c"
  + "enter of the floor rests a long sturdy oak table and two long"
  + " benches. An arched doorway leads east.");

  add_exit ("east", ROOM_PATH + "oakhouse.c");

  add_item ("table benches bench",
    "Several people could fit to sit around the table for a feast.\n"
  + "");

  add_item ("lanterns lantern",
    "They bathe the hall in a deep red glow, that makes you think "
  + "of a sunset.\n");

  add_item ("beams",
    "They look sturdy enough to support the heavy roo"
  + "f of the hall.\n");

  add_item ("stove",
    "You peek into the stove and find out there's n"
  + "othing but a blaze in it.\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
