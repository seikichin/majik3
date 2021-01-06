// DATE        : Sat Nov  1 23:31:53 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("On Gatestreet");
  set_long (
    "The Gate street connects the two east gates. The northern gate"
  + " is used mainly by the travelling merchants, and of course by"
  + " the young students at the Academy of Magic, while the southe"
  + "rn gate is used by the common people and travellers for it le"
  + "ads to the main street of the city. The Gate street continues"
  + " to the north where a market place filled with people can be "
  + "seen and to the south where it crosses the Majik street.");

  add_exit ("south", ROOM_PATH + "majik4.c");
  add_exit ("north", ROOM_PATH + "marketp2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
