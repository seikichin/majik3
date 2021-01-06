#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Treetop over the stream");
  set_long (
    "You're sitting on a sturdy treelimb. As you watch your feet yo"
  + "u see the water below. Its sparkling waters look very allurin"
  + "g and refreshing and you almost fall down drawn by the water'"
  + "s sparkle. This tree forms nearly a perfect place for di"
  + "ving into the sparkly stream, if you'd only know how deep the"
  + " water is. A rope has been tied to the sturdiest limb of the "
  + "pine and hangs all the way to the riverbank allowing easy acc"
  + "ess to the treetop.");

  set_outdoors (4);

}

init ()
{
    ::init ();
    add_action ( "do_climb", "climb" );
    add_action ( "do_dive", "dive" );
}
do_climb(string str)
{
  if (!str || str != "down") {
  notify_fail ("Climb where? Down perhaps?\n");
  return 0;
  }
  write ("You climb down.\n");
  message ("3", query_cap_name() + " climbs down.\n", ENV(THIS),THIS);
  message ("3", query_cap_name() + " climbs down from the tree.\n", ROOM_PATH +
  "friver.c");
  THIS->move_player ( ROOM_PATH + "friver.c");
  return 1;
}
do_dive()
{
  write ("You dive into the stream below and hit the surface with a splendid splash.\n");
  message ("3", query_cap_name() + " jumps down to the river with a graceful"
  +" dive.\n",ENV(THIS),THIS);
  message ("3", query_cap_name() + " dives to the river from the tree and splashes"
  +" water over you.\n", ROOM_PATH + "river.c");
  message ("3", query_cap_name() + " leaps down from the treetop and dives into the river.\n",
  ROOM_PATH + "friver.c");
  THIS->move_player ( ROOM_PATH + "river.c");
  return 1;
}
