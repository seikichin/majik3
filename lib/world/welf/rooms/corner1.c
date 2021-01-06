// DATE        : Thu Feb  5 18:49:28 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Under a tall tree");
  set_long (
    "A tall evergreen tree towers above you casting its shadow over"
  + " the whole streetcorner. The ground here is covered with a co"
  + "lorful leaf carpet and the air is filled with the scent of th"
  + "e forest. Spiralling stairs lead up to the massive tree and t"
  + "he street continues to the east and south where you can see t"
  + "he totems of winter and autumn. The holy swantemple is near y"
  + "ou in southeast.");

  add_exit ("south", ROOM_PATH + "autumn.c");
  add_exit ("up", ROOM_PATH + "treetop1.c");
  add_exit ("east", ROOM_PATH + "winter.c");

  add_item ("temple",
    "The temple is made of grey stone and looks ancient. A feeling "
  + "of\nholiness and the presence of some deity surrounds the plac"
  + "e. Four\npillars support its heavy gothic stylished roof and o"
  + "n the each\nfour sides of the temple are carved intricate leaf"
  + " patterns.\n");

  add_item ("tree",
    "Up on the treetop you can see somekind of a platfo"
  + "rm and ropebridges leading from a treetop to another.\n");

  add_sound ("A plume of smoke rises from the temple.");
  add_sound ("Deep chanting echoes from within the temple.");
  add_sound ("You can see a flock of swans passing by high above the city.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
