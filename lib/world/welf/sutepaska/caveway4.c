// DATE        : Thu Nov  6 19:24:45 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A sidepassage");
  set_long (
    "The stench becomes stronger here and you have second thoughts "
  + "of continuing onwards. The walls and floor are dry here, but "
  + "you can still here the echoes of dripping water coming from w"
  + "est. There's some light further in the cave in east. The pass"
  + "ageway leads east and west.");

  add_exit ("east", ROOM_PATH + "serpentcave.c");
  add_exit ("west", ROOM_PATH + "caveway2.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
