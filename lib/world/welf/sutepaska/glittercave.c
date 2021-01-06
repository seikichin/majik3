#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A glittering cave");
  set_long (
    "The cave is about twenty feet high and large enough for a smal"
  + "l dragon to live in. Luckily, there are no dragons here. At t"
  + "he center of the cave is a pool of crystal clear water, its s"
  + "till surface reflecting everything perfectly. The walls of th"
  + "e cave seem to glow and glitter with soft blue light. The lig"
  + "ht reflects from the pools water and is shattered into myriad"
  + " shades of blue. A smaller caveway leads north from here.");

  add_exit ("north", ROOM_PATH + "caveway1.c");

  set_light (1);

}
init()
{
::init();
add_action ("do_dive","dive");
}
do_dive()
{
write ("You dive under the surface.\n");
message ("3", THIS->query_cap_name()+" dives under the surface.\n", ENV(THIS),THIS);
message ("3", THIS->query_cap_name()+"dives here from above.\n", ROOM_PATH + "undercave.c");
THIS->move_player ( ROOM_PATH + "undercave.c");
return 1;
}
