// DATE        : Thu Nov  6 21:28:06 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Gold street");
  set_long (
    "You're walking along the Gold street which connects the Northe"
  + "rn Temple street and Arcane street. The city bank is just a f"
  + "ew streps north from here.");

  add_exit ("south", ROOM_PATH + "ntemple3.c");
  add_exit ("north", ROOM_PATH + "gold2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
