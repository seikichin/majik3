// DATE        : Sun Nov  2 20:48:52 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A short alley");
  set_long (
    "You're in a dark alley leading south to the Inn doors and to t"
  + "he north where it joins the Southern Temple street. You can s"
  + "ee the cemetary gates a short distance in the north. Some mer"
  + "ry making and cheers echo from the Inn building. A loud bangi"
  + "ng of hammer on anvil comes from the building in the east, mu"
  + "st be the city smithy.");

  add_exit ("south", ROOM_PATH + "innyard.c");
  add_exit ("north", ROOM_PATH + "stemple2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
