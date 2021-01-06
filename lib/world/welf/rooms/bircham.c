// DATE        : Thu Feb  5 18:06:24 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Small chamber");
  set_long (
    "This chamber is most propably a place for meditating and resti"
  + "ng. A large window on the north wall gives a nice view over t"
  + "he city and you can hear birds chirping happily in the nearby"
  + " trees. A thick green carpet covers the whole floor and some "
  + "flower pots have been placed on pedestals at the corners of t"
  + "he room. A curtained doorway leads south.");

  add_exit ("south", ROOM_PATH + "birchma.c");

  add_item ("window",
    "The view is splendid. You can see the fountain square and the "
  + "Que-Moran's treepalace in the north.\n");

  add_item ("carpet",
    "It's red and soft and fe"
  + "els very comfortable. It's ideal for sitting crosslegged and "
  + "meditating, or just for taking a nap on it.\n");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
