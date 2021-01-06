// DATE        : Thu Nov  6 19:09:50 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("An underwater tunnel");
  set_long (
    "You are under water in a small passage way. The water is cryst"
  + "al clear and you can see perfectly here. How long you can hol"
  + "d your breath is another question. Light floods in from north"
  + " and south where you think you can get to the surface once ag"
  + "ain.");

  add_exit ("south", ROOM_PATH + "underpool.c");
  add_exit ("north", ROOM_PATH + "undercave.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
