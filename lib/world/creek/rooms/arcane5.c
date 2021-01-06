// DATE        : Sun Nov  2 22:16:21 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Arcane street");
  set_long (
    "You're now walking along the Arcane street which runs in east-"
  + "west direction from the Academy to the Ivory Halls. The bui"
  + "lding in south is the Bank of the city. Its doors are in the "
  + "Gold street around the corner in the east. City walls rise be"
  + "fore you in the north blocking the view there.");

  add_exit ("east", ROOM_PATH + "arcane1.c");
  add_exit ("west", ROOM_PATH + "arcane6.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
