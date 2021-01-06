#include "../path.h"

inherit ITEM;

create_item ()
{
  set_name (({ "an elevator", "elevator" }));
  set_short ("a strange elevator is here");

  set_long ("The wooden elevator is used for lifting heavy items from the ground level to palace. A strong rope supports the elevator and seems to be strong enough to support the weight. The elevator is just big enough for one person to enter it.\n");

  set_material ("wood");
  set_dimensions (50, 200, 20);
  set_no_get (1);
}


init()
{
  add_action ("do_enter","enter");
}
do_enter(string str)
{
  if (!str || str != "elevator")
  {
  notify_fail ("Enter what?");
  return 0;
  }
write ("You hop into the elevator.\n");
message("3", THIS->query_cap_name() + " hops into the elevator.\n",ENV(THIS),THIS);

ROOM_PATH + "elevator"->add_exit ("out", file_name(ENV(THIS)));
ROOM_PATH + "elevator"->init(0);

THIS->move_player( ROOM_PATH + "elevator.c");
return 1;
}
