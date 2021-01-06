// DATE        : Mon Nov  3 22:06:58 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Southern Temple street");
  set_long (
    "You're standing on the Southern Temple street. North from here"
  + " you can see the city cemetary over the fence. The adamantite"
  + " fence will keep the animals away, and the holy symbols engra"
  + "ved on it will stand against any evil intent towards the dead"
  + ". The street continues to the east and west. A short street l"
  + "eads south to an Inn.");

  add_exit ("east", ROOM_PATH + "stemple6.c");
  add_exit ("west", ROOM_PATH + "stemple7.c");
  add_exit ("south", ROOM_PATH + "alley1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
