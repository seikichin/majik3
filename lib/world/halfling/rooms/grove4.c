// DATE        : Mon Dec  8 05:53:42 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Pear Orchard");
  set_long (
    "This is the northwestern end of the grove. This area is domina"
  + "ted with pear trees. The trees do not completly cover the are"
  + "a, so they must have been planted recently. A wooden fence su"
  + "rrounds the area to the north and west.");

  add_exit ("south", ROOM_PATH + "grove2.c");
  add_exit ("west", ROOM_PATH + "grove3.c");

  add_item ("fence",
    "The fence looks strong and is covered with barbed wire.\n");

  add_item ("tree trees",
    "The pe"
  + "ar trees looks young, but they are in good health.\n");

  add_sound ("You see something move near the fence, but you don't get a good look at it.");
  add_sound ("Some muffled voices come from the south.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
