// DATE        : Thu Nov  6 19:05:53 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Underwater");
  set_long (
    "You are now diving in water of a small pool. The crystal clear"
  + " water allows you to see perfectly. The water is icy cold but"
  + " so refreshing. You can see the sky through the surface, but "
  + "there is also a hole in the north side of the pool near the b"
  + "ottom.");

  add_exit ("up", ROOM_PATH + "pool.c");
  add_exit ("north", ROOM_PATH + "undertunnel.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
