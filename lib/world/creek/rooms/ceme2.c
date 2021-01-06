// DATE        : Sat Nov  1 22:03:46 1997
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
  + "b them now, once they have been blessed by the high priests o"
  + "f the temple of truth. Paved path leads through the cemetary "
  + "to a burial chapel, where the blessings are given to the dead"
  + ". An adamantite fence surrounds the whole cemetary keeping th"
  + "e animals away. Some memorial statues line the path. The ceme"
  + "tary path leads west and to north you see a doorway to the te"
  + "mple.");

  add_exit ("north", ROOM_PATH + "gifts.c");
  add_exit ("west", ROOM_PATH + "ceme3.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
