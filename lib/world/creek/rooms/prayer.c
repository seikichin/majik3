// DATE        : Sat Nov  1 21:44:01 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Innern part of the temple, the hall of prayers");
  set_long (
    "A room for the ones who like to pray without being interrupted"
  + " all the time. The voices said in here are heard only in the "
  + "heavens above and by gods only. Only few chandeliers burn her"
  + "e, giving the hall a dim light and peacefull atmosphere. An a"
  + "rched doorway leads north to the entrance hall.");

  add_exit ("north", ROOM_PATH + "temple.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
