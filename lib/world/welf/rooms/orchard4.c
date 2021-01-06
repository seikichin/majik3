// DATE        : Thu Feb 26 20:52:48 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Orchard");
  set_long (
    "You're walking among beautiful small plum and appletrees. They"
  + " cast soft shadows on the flower covered orchard ground and r"
  + "ustle quietly in the wind. A short distance in south you can "
  + "make out a small shed built on the treetop. The orchard conti"
  + "nues east and south.");

  add_exit ("south", ROOM_PATH + "orchard3.c");
  add_exit ("east", ROOM_PATH + "orchard1.c");

  add_item ("shed",
    "The shed is probably used by the gardener of this orchard.\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
