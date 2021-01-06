// DATE        : Thu Feb  5 19:07:32 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Under a tall tree");
  set_long (
    "A tall and massive tree towers here above you casting its shad"
  + "ow over the whole streecorner. The ground here is covered wit"
  + "h a thick colorful leaf carpet and the air is filled with the"
  + " scent of the forest. Spiralling stairs lead up to the tree a"
  + "nd the street continues to the east and north where you can s"
  + "ee the totems of autumn and summer. The swantemple is near yo"
  + "u in the northeast.");

  add_exit ("north", ROOM_PATH + "autumn.c");
  add_exit ("up", ROOM_PATH + "treetop4.c");
  add_exit ("east", ROOM_PATH + "summer.c");

  add_item ("tree",
    "You can see somekind of a platform up in the tree. Swaying rop"
  + "ebridges lead to another treetops from there.\n");

  add_item ("temple swantemple",
    "The temple is m"
  + "ade of grey stone and looks ancient. A feeling of\nholiness an"
  + "d the presence of some deity surrounds the place. Four\npillar"
  + "s support its heavy gothic stylished roof and on the each\nfou"
  + "r sides of the temple are carved intricate leaf patterns.\n");

  add_sound ("A thick plume of smoke rises from the temple.");
  add_sound ("You inhale the fresh air of forest.");
  add_sound ("You can hear chanting coming from the temple.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
