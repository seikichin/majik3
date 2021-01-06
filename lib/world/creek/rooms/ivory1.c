// DATE        : Mon Nov  3 23:53:02 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Ivory street");
  set_long (
    "You're walking on Ivory street now which runs in north south d"
  + "irection. Just a short distance in south you can see some kin"
  + "d of a bazaar. In the north is the entrance to the Ivory Gard"
  + "ens, and the halls of Ivory.");

  add_exit ("south", ROOM_PATH + "bazaar4.c");
  add_exit ("north", ROOM_PATH + "ivory2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
