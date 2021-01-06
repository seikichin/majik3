// DATE        : Thu Nov  6 19:44:05 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Chapel street");
  set_long (
    "Your walking on Chapel street which runs south towards the cit"
  + "y cemetary. In the north it joins the Arcane street. The buil"
  + "ding on your east side is the bank of the city.");

  add_exit ("south", ROOM_PATH + "chapel2.c");
  add_exit ("north", ROOM_PATH + "arcane6.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
