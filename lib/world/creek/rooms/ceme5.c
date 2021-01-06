// DATE        : Sat Nov  1 22:17:08 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Cemetary, at the sparkling fountain");
  set_long (
    "Ever blossoming trees and flowers fill the air with a fresh sc"
  + "ent of spring. The dead lie here in peace, nothing can distur"
  + "b them now, since they have been blessed by the high priests "
  + "of the temple of truth. An adamantite fence surrounds the who"
  + "le cemetary keeping the animals away. A sparkling fountain gu"
  + "rgles happily here, its sound soothing you. A burial chapel i"
  + "s in the west. The cemetary path leads north and south.");

  add_exit ("south", ROOM_PATH + "ceme3.c");
  add_exit ("north", ROOM_PATH + "ceme4.c");
  add_exit ("west", ROOM_PATH + "chapel.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
