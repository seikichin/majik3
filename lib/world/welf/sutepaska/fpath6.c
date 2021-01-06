#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Forest");
  set_long (
    "The forest gets thinner here at the foot a small hill that lie"
  + "s in the north. Steep ancient looking stonestairs climb north"
  + " up to the hilltop where you can spot some ruins of an abando"
  + "ned temple or perhaps the remains of an old watchtower. Faint"
  + " path leads west and east, where you can hear the sound of fl"
  + "owing water.");

  add_exit ("west", ROOM_PATH + "fpath5.c");
  add_exit ("north", ROOM_PATH + "fruins.c");
  add_exit ("east", ROOM_PATH + "friver2.c");

  set_outdoors (4);

}

init()
{
  add_action ("do_north","north");
}
do_north()
{
write ("You skip up the ancient stone stairs all the way to the hilltop.\n");
message ("3", query_cap_name() + " climbs up the ancient stairs to the "
        +"hilltop and the ruins.\n",ENV(THIS),THIS);
message ("3", query_cap_name() + " arrives from south panting heavily "
        +"at the last few steps.\n", ROOM_PATH + "fruins.c");
THIS->move_player ( ROOM_PATH + "fruins.c");
return 1;
}
