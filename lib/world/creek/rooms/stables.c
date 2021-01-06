// DATE        : Sun Nov  2 22:52:15 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Inn stables");
  set_long (
    "The stables aren't much more than four walls and a roof, but y"
  + "ou can still call it a building and it will suit the horses a"
  + "nd drunks. Few horses have been tied on poles in here. Piles "
  + "of hay lie in corners. A lamp is hanging from the ceiling to "
  + "give some light to the dark stable. A doorway leads out to th"
  + "e Inn yard. A banging of hammer on anvil echoes from the othe"
  + "r side of the building where the city smithy is located.");

  add_exit ("west", ROOM_PATH + "innyard.c");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
