// DATE        : Thu Feb  5 18:53:56 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Under a tall tree");
  set_long (
    "A tall evergreen tree towers above you casting a shadow over t"
  + "he whole streetcorner. The ground here is covered with a colo"
  + "rful leaf carpet and the air is filled with the scent of the "
  + "forest. Spiralling stairs lead up to the strange tree and the"
  + " street continues to the west and south where the totems of w"
  + "inter and spring can be seen. The holy swantemple is in the s"
  + "outhwest.");

  add_exit ("west", ROOM_PATH + "winter.c");
  add_exit ("south", ROOM_PATH + "spring.c");
  add_exit ("up", ROOM_PATH + "treetop2.c");

  add_item ("temple",
    "The temple is made of grey stone and looks ancient. A feeling "
  + "of\nholiness and the presence of some deity surrounds the plac"
  + "e. Four\npillars support its heavy gothic stylished roof and o"
  + "n the each\nfour sides of the temple are carved intricate leaf"
  + " patterns.\n");

  add_item ("tree",
    "You can see a platform up in the tree and ropebrid"
  + "ges running from a treetop to another.\n");

  add_sound ("A deep mournful chanting echoes from the temple.");
  add_sound ("A plume of smoke rises to the sky from the temple.");
  add_sound ("A cute little squirrel leaps from a treetop to another nearby.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
