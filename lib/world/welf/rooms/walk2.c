// DATE        : Fri Dec 26 17:52:57 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("King's walk");
  set_long (
    "You're standing before one of the most gigantic trees you've s"
  + "een in your life. Huge stairs spiral up to the doors of Que-M"
  + "oran, the palace of the lord and lady of Sol'daran. White cob"
  + "blestoned street leads west from here towards the fountain sq"
  + "uare in west.");

  add_exit ("west", ROOM_PATH + "walk1.c");
  add_exit ("up", ROOM_PATH + "quegat.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
