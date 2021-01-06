#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Treetop near the river");
  set_long (
    "You're standing on a sturdy platform that has been built on th"
  + "e treetop of this tall pine. In the east there's a sparkling "
  + "river that flows towards south. A long and narrow ropebridge "
  + "leads east over the river to another tree on the other side a"
  + "nd a knotted rope that has been tied to one of the sturdy lim"
  + "bs of this tree providing easier way to climb down.");

  add_exit ("east", ROOM_PATH + "rover.c");

  set_outdoors (4);
}
init ()
{
    ::init ();
    add_action ( "do_climb", "climb" );
}
do_climb(string str)
{
  if (!str || str != "down") {
  notify_fail ("Climb where? Down perhaps?\n");
  return 0;
  }
  write ("You climb down.\n");
  message ("3", query_cap_name() + " climbs down.\n", ENV(THIS),THIS);
  message ("3", query_cap_name() + " climbs down from the tree.\n",
  ROOM_PATH + "friver2.c");
  THIS->move_player ( ROOM_PATH + "friver2.c");
  return 1;
}
