#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("In a small pool");
  set_long (
    "You're swimming in a pool of crystal clear water. Birchtrees f"
  + "orm archs over the pools water. The water is cold but refresh"
  + "ing. Its surface reflects the sky perfectly. A small waterfal"
  + "l gushes from a ledge in north, its waters pouring into the p"
  + "ool with a roar sending a tingling spray of water in the air."
  + "");

  add_exit ("east", ROOM_PATH + "atpool.c");

  set_outdoors (4);

}

init()
{
::init();
add_action ("do_dive","dive");
}
do_dive()
{
write ("You dive into the icy waters.\n");
message ("3", THIS->query_cap_name()+" dives into the icy waters.\n", ENV(THIS),THIS);
message ("3", THIS->query_cap_name()+" arrives here from above.\n", ROOM_PATH + "underpool.c");
THIS->move_player ( ROOM_PATH + "underpool.c");
return 1;
}
