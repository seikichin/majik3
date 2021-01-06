// DATE        : Sun Nov  2 19:50:20 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A short alley leading to market place");
  set_long (
    "You're now at a short alley between the Academy of Magic and t"
  + "he City Guard headquarters. The massive building of the Acade"
  + "my on your northern side and the City Guard HQ in south. The "
  + "terribly crowded Market place is in the east and in the west "
  + "is Candle street which leads south to the Temple Square.");

  add_exit ("east", ROOM_PATH + "marketp7.c");
  add_exit ("west", ROOM_PATH + "candle5.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
