// DATE        : Tue Nov 11 21:40:15 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Entrance to Pook's Tower");
  set_long (
    "You have entered a thin, tall tower. The walls are solid, dark"
  + " blue and made of some material unknown to you. There are tor"
  + "ches, inside holders, along the walls to provide light. The o"
  + "nly other feature of the room is the huge staircase in front "
  + "of you and the archway behind you.");

  add_exit ("arch", "/world/y19x214.c");
  add_exit ("up", ROOM_PATH + "stair1.c");

  add_item ("stairs staircase",
    "The staircase is huge. It goes into the upper reaches of the t"
  + "ower.\n");

  add_item ("wall walls",
    "The walls are a dark blue and shine in the torchlight. "
  + "You cannot make out the material, but it appears very sturdy."
  + "\n");

  add_item ("torch torches",
    "There are four torches spaced evenly around the room. They a"
  + "re held in place with metal holders. They are lit, but do not"
  + " seem to burn away at all.\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
