// DATE        : Tue Jan 27 20:15:18 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Narrow ropebridge");
  set_long (
    "You're standing on a very narrow and flimsy looking ropebridge"
  + " that connects the two platforms on the both ends. The platfo"
  + "rm at the west end of the bridge rests on a treetop of a tall"
  + " pine and the one at the east end is some kind of a terrace b"
  + "efore a peculiar looking treehouse.");

  add_exit ("east", ROOM_PATH + "ifwep.c");
  add_exit ("west", ROOM_PATH + "treetop2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
