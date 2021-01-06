// DATE        : Sat Nov  1 22:13:38 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Cemetary");
  set_long (
    "Ever blossoming trees and flowers fill the air with a fresh sc"
  + "ent of spring. The dead lie here in peace, nothing can distur"
  + "b them now, since they have been blessed by the high priests "
  + "of the temple of truth. Paved path leads through the cemetary"
  + " to a burial chapel, where the blessings are given to the dea"
  + "d. An adamantite fence surrounds the whole cemetary keeping t"
  + "he animals away. Some memorial statues line the path. The cem"
  + "etary path leads east, west and north.");

  add_exit ("north", ROOM_PATH + "ceme5.c");
  add_exit ("east", ROOM_PATH + "ceme2.c");
  add_exit ("west", ROOM_PATH + "ceme7.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
