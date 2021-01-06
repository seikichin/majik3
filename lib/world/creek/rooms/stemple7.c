// DATE        : Mon Nov  3 22:04:16 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Southern Temple street");
  set_long (
    "You're walking on the south side of the city cemetary along th"
  + "e Southern Temple steet. In the north the adamantite fence bl"
  + "ocks your way. Cheers and laughter echo from around the corne"
  + "r in east where the famous Drunken Dragon's inn is located.");

  add_exit ("west", ROOM_PATH + "stemple3.c");
  add_exit ("east", ROOM_PATH + "stemple2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
