#include "../path.h"
inherit "/home/madrid/agriculture/farm_room.c";
string buf;
create_farm()
{
   set_short("A farming plot");
  //set_save_file("/home/madrid/agriculture/mill_farm2.o");
  add_exit("north", ROOM_PATH + "mill_farm1.c");
  add_exit("south", ROOM_PATH + "mill_farm3.c");
}
