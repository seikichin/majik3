// DATE        : Sat Nov  1 23:44:31 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("On Gate Street");
  set_long (
    "The Gate street connects the two east gates. The northern gate"
  + " is used mainly by the travelling merchants, and of course by"
  + " the students at the Academy of Magic, while the southern gat"
  + "e is used by the common people and travellers for it leads to"
  + " the main street of the city. The Gate street continues to th"
  + "e north where it crosses the Majik street and to the south wh"
  + "ere it joins to the southern Temple street.");

  add_exit ("south", ROOM_PATH + "gate3.c");
  add_exit ("north", ROOM_PATH + "majik4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
