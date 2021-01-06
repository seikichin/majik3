// DATE        : Thu Feb  5 18:19:17 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Main room");
  set_long (
    "This room is perfectly round and more spacious than you'd expe"
  + "cted when looking at the building from outside. A low kneehei"
  + "ght table is set at the center of the room and several pluffy"
  + " and colorful cushions lie around it. Several paintings of tr"
  + "anquil forest scenes decorate the walls. Two curtained doorwa"
  + "ys lead east and north.");

  add_exit ("north", ROOM_PATH + "bircham.c");
  add_exit ("east", ROOM_PATH + "birchal.c");

  add_item ("paintings walls painting wall",
    "They all depict the scenery of wild woodlands, tranquil stream"
  + "s and graceful animals.\n");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
