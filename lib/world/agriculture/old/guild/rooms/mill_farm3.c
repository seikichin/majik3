#include "../path.h"
inherit "/home/madrid/agriculture/farm_room.c";
create_farm()
{
  set_short("A farming plot");
  add_exit("north", ROOM_PATH + "mill_farm2.c");
  add_exit("west", ROOM_PATH + "mill_farm4.c");
}
