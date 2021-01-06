// DATE        : Sat Feb 21 21:19:19 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Under a tall tree");
  set_long (
    "A massive tree towers above you casting its shadow over the wh"
  + "ole streetcorner. The ground here is covered with a colorful "
  + "leaf carpet and the air is filled with the scent of the fores"
  + "t. Spiralling stairs lead up to the tree and the street conti"
  + "nues to the west and north where the totems of spring and sum"
  + "mer are located. The swantemple is near you in northwest.");

  add_exit ("west", ROOM_PATH + "summer.c");
  add_exit ("north", ROOM_PATH + "spring.c");
  add_exit ("up", ROOM_PATH + "treetop3.c");

  add_item ("temple swantemple",
    "The temple is made of grey stone and looks ancient. A feeling "
  + "of\nholiness and the presence of some deity surrounds the plac"
  + "e. Four\npillars support its heavy gothic stylished roof and o"
  + "n the each\nfour sides of the temple are carved intricate leaf"
  + " patterns.\n");

  add_item ("tree",
    "You can see a platform up in the tree and ropebrid"
  + "ges leading to another treetops from there.\n");

  add_sound ("A plume of smoke rises from the temple.");
  add_sound ("You can hear some chanting from within the temple.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
