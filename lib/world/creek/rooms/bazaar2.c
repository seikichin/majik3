// DATE        : Sun Nov  2 21:30:20 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Bazaar, at the Robber's Den");
  set_long (
    "You're now at the sign of a murky tavern called The Robber's D"
  + "en. The surrounding area is some kind of a bazaar. The tavern"
  + " being a place of meeting for the criminals and outlaws, the "
  + "surrounding area is quite dangerous for the common people. Yo"
  + "u can see the west gate of Silvercreek some distance in west."
  + " A door leads east to the tavern.");

  add_exit ("north", ROOM_PATH + "bazaar4.c");
  add_exit ("east", ROOM_PATH + "den1.c");
  add_exit ("west", ROOM_PATH + "bazaar1.c");

  add_object (MONSTER_PATH + "ruffian");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
