// DATE        : Sun Dec 28 01:49:20 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Elegant bedroom");
  set_long (
    "You're standing in an elegant bedchamber a large soft looking "
  + "curtained bed takes up most of the space here. A large window"
  + " on the south wall gives a splendid view over the forest belo"
  + "w. Few paintings have been placed on the walls and above them"
  + " is a shield bearing the coat of arms of the Velendur family."
  + " A door leads north.");

  add_exit ("north", ROOM_PATH + "queha5.c");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
