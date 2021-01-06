// DATE        : Thu Oct 30 23:46:29 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Totem of Summer");
  set_long (
    "The ground here is full of colourful flowers and the rich scen"
  + "t of the forest fills the air. In the center of the square st"
  + "ands a tall wooden totem of summer reaching for the sun above"
  + ". The totem is painted with the vivid colours of summer and i"
  + "t is carved to resemble an elf sitting on a shoulder of the g"
  + "reat bear. The bear is quite an imposing sight but the impres"
  + "sion on the face of the totem elf is so relaxed that you feel"
  + " quite certain there's no danger in the bear. The forest surr"
  + "ounds the square and leafcovered paths lead to the east, west"
  + " and south. A temple is waiting for you to enter it in the no"
  + "rth.");

  add_exit ("south", ROOM_PATH + "street.c");
  add_exit ("north", ROOM_PATH + "temple.c");
  add_exit ("east", ROOM_PATH + "corner3.c");
  add_exit ("west", ROOM_PATH + "corner4.c");

  add_item ("bear totem beartotem karhu",
    "       A,A\n      (O o)     The brightly coloured bear stands e"
  + "rect and\n    __( U )__   expressionless and doesn't seem as l"
  + "ively\n   |   |-|   |  as on the first sight. In fact it looks"
  + " like\n   | | ''' | |  a huge wooden totem, and that's what it"
  + " is,\n   | |     | |  yet to the tanir folk it's a symbol of s"
  + "ummer,\n    -|     |-   nature and strength. During the warm s"
  + "ummer\n     |  |  |    nights when Afay is shining bright on t"
  + "he sky\n     |  |  |    and the darkwalkers quiver in fear the"
  + " elves\n  ___|__|__|__  dance around the totem and celebrate.."
  + ".\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
