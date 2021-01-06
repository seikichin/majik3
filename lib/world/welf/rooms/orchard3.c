// DATE        : Thu Feb 26 20:54:01 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Orchard");
  set_long (
    "Small apple and plumtrees surround you in this elven orchard. "
  + "The trees are all in full blossom and make quite a sight. The"
  + " orchard continues in east and north. There's a small shed bu"
  + "ilt on a treetop south from here.");

  add_exit ("south", ROOM_PATH + "ushed.c");
  add_exit ("north", ROOM_PATH + "orchard4.c");
  add_exit ("east", ROOM_PATH + "orchard2.c");

  add_item ("shed",
    "Just a short distance in south you can see the tree the shed i"
  + "s built on. The shed is most probably used by the gardener.\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
