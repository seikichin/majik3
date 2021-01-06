// DATE        : Sun Nov  2 00:14:05 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Southern Temple street");
  set_long (
    "You're walking along the Southern Temple street which continue"
  + "s to the east and west. A short distance to the east you can "
  + "see a book shop. In the west a short street leads to the Merc"
  + "hant street where many of the city's shops are located. The p"
  + "ost office of Silvecreek is located north from here.");

  add_exit ("north", ROOM_PATH + "posti.c");
  add_exit ("east", ROOM_PATH + "gate3.c");
  add_exit ("west", ROOM_PATH + "market3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
