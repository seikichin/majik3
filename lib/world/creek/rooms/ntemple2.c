// DATE        : Sun Nov  2 19:11:12 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Northern Temple street");
  set_long (
    "You're now walking along the Northern Temple street. The massi"
  + "ve building of the town house is on your other side and the T"
  + "emple of Truth on the other. The street continues to the east"
  + " and west. Some people are walking here and chatting, as they"
  + " notice you they quickly turn around and hurriedly continue t"
  + "o the other way.");

  add_exit ("east", ROOM_PATH + "candle3.c");
  add_exit ("west", ROOM_PATH + "ntemple1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
