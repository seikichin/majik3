// DATE        : Mon Nov  3 22:06:13 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Southern Temple street");
  set_long (
    "You're walking along the Southern Temple street now. Being the"
  + " longest street in city many shops have risen along it. In th"
  + "e north you can see the cemetary of the city over the fence. "
  + "Sounds of merry making echo from the building in south.");

  add_exit ("east", ROOM_PATH + "stemple7.c");
  add_exit ("west", ROOM_PATH + "grave3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
