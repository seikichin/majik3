// DATE        : Thu Nov  6 19:49:21 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A short alley");
  set_long (
    "You're in a short shady alley which connects the bazaar in wes"
  + "t and Gravestreet in east. Strange smells drift in from west "
  + "where the bazaar is. ");

  add_exit ("east", ROOM_PATH + "grave2.c");
  add_exit ("west", ROOM_PATH + "bazaar4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
