// DATE        : Thu Feb 26 12:58:36 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Morninglane");
  set_long (
    "The laneway you're walking on runs through the part of Sol'dar"
  + "an where most of the common tanir dwell. Though the treehouse"
  + "s all around you on the treetops aren't as luxurious as the o"
  + "nes in Endalen they easily match the beauty of the treemansio"
  + "ns in their simple and somehow a bit rustic design. Wild flow"
  + "ers and vines drape from some of the houses and some of the h"
  + "ouses are built around the trees so well that it is hard to t"
  + "ell which part is house and which the tree itself. The lanewa"
  + "y leads south and north and a well kept path leads east.");

  add_exit ("north", ROOM_PATH + "mlane1.c");
  add_exit ("east", ROOM_PATH + "mystgarden.c");
  add_exit ("south", ROOM_PATH + "mlane3.c");

  add_sound ("A sweet scent of a blooming garden drifts in from the east.");
  add_sound ("You can hear someone playing a beautiful tune with a harp somewhere nearby.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
