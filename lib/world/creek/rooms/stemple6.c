// DATE        : Mon Nov  3 22:02:22 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Southern Temple street");
  set_long (
    "You're walking on Southern Temple street which runs in east-we"
  + "st direction. In the north you can see the city cemetary over"
  + " the adamantite fence. A loud banging echoes from the buildin"
  + "g in south, must be the city smithy.");

  add_exit ("west", ROOM_PATH + "stemple2.c");
  add_exit ("east", ROOM_PATH + "stemple1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
