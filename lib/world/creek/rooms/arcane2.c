// DATE        : Sun Nov  2 22:19:30 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Arcane street");
  set_long (
    "You're walking along the Arcane street which runs in east-west"
  + " direction from the Academy to the Ivory Halls. The buildin"
  + "g in south is the Town Hall of Silvercreek. Around the corner"
  + " in west is the city bank.");

  add_exit ("east", ROOM_PATH + "arcane3.c");
  add_exit ("west", ROOM_PATH + "arcane1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
