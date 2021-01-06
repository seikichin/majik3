#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Gamblers' corner");
  set_long (
    "This small and gloomy sideroom has been reserved for gambling. "
   +"Eight comfortable looking chairs have been placed around a big"
   +" round table at the center of the room. A lamp sculpted to res"
   +"emble a sunflower hangs over the table shedding its faint red "
   +"light to the hazy room. A small doorway leads south to the mai"
   +"nroom of the tavern.\n");

  add_item ("lamp sunflower","It's sculpted with apparent skill and"
   +" looks quite real resembling a big sunflower. It is made of po"
   +"lished brass and tainted red glass which filters the light the"
   +" lamp sheds so sparingly.\n");
 
  add_exit ("south", ROOM_PATH + "sunflower.c");

  add_sound ("You can barely see around you in this thick pipeweed "
   +"haze.");
  add_sound ("A funny song spiced up with lots of hiccups echoes fr"
   +"om the mainroom.");
  add_sound ("Loud laughter and cheers erupt in the mainroom.");

  add_monster ( MONSTER_PATH + "shady.c");
  set_light (1);
}
