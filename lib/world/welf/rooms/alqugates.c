// DATE        : Fri Oct 31 15:34:01 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Outside the Gates of Alquarie, the Great City of Tanir");
  set_long (
    "Before you stand the gates of Alquarie, the city of woodelves."
  + " The huge wooden gates won't let anyone with a tainted heart "
  + "to enter the sacred city. Above you on the tall wooden wall y"
  + "ou can see elven archers aim their arrows at you. And from wh"
  + "at you have heard of their skills, you are quite sure they wo"
  + "uldn't miss. You can enter the city in the north and the vast"
  + " forest spreads itself in every other direction.");

  add_exit ("north", ROOM_PATH + "gates.c");
  add_exit ("south", "/world/y29x123");
  add_exit ("east", "/world/y29x123");
  add_exit ("west", "/world/y29x123");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
