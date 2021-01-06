#include "/home/madrid/agriculture/guild/path.h"
inherit ROOM;
create_room()
{
  set_area("farmers");
  set_short("A small hallway");
  set_long(wrap("You have entered a small building made of brown wood.  "+
  "The floor is made of cobblestones which are oddly positioned on "+
  "the ground.  The smell of cooking food comes from farther inside "+
  "the building.  The hallway continues on to the east and west.\n"));
  add_exit("east",ROOM_PATH+"guild.c");
  add_exit("west",ROOM_PATH+"shop.c");
  set_light(2);
}
