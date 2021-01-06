// DATE        : Mon Nov  3 21:32:41 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A quiet room in the inn");
  set_long (
    "This room is a bit more quiet than the main room. You can eat "
  + "here in peace or just relax and think about the life. Candles"
  + " are put on tables to give the room a cosy feeling. A doorway"
  + " leads south to the main room.");

  add_exit ("south", ROOM_PATH + "inn1.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
