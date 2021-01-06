// DATE        : Thu Nov  6 19:22:17 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A caveway");
  set_long (
    "he caveway makes a steep climb upwards here. And you can feel "
  + "the draft of fresh air. The floor and walls are moist and the"
  + " sound of dripping water echoes around the cave walls. A side"
  + " passage leads east from here and a strange quite pungent ste"
  + "nch comes from there. The main caveway leads north and west.");

  add_exit ("west", ROOM_PATH + "caveway1.c");
  add_exit ("east", ROOM_PATH + "caveway4.c");
  add_exit ("north", ROOM_PATH + "caveway3.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
