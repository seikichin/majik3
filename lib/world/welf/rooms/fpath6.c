#include "../path.h"

inherit ROOM;

create_room ()
{
    set_short ("Forest");
    set_long (
      "The forest gets thinner here at the foot of a small hill that li"
      +"es in the north. Steep ancient looking stonestairs climb up to "
      +"the hilltop where you can spot some ruins of an abandoned temple"
      +" or perhaps the remains of an old watchtower. Faint path leads "
      +"west and east.\n"
    );

    add_exit ("west", ROOM_PATH + "fpath5.c");
    add_exit ("north", ROOM_PATH + "fruins.c");
    add_exit ("east", ROOM_PATH + "friver2.c");

  add_sound ("You can hear the sound of flowing water in the east.\n");

  add_item ("ruins hilltop watchtower temple", "The barren hilltop "
 +"and the ruins on its top make you think of a crude caricature of"
 +" a bald king with a crown of stone on his head.\n");
    set_outdoors (4);

}

init()
{
    add_action ("do_west","west");
    add_action ("do_east","east");
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
do_east()
{
    message ("3", query_cap_name() + " leaves east.\n", ENV(THIS),THIS);
    message ("3", query_cap_name() + " arrives from west.\n", ROOM_PATH
      + "friver2.c");
    THIS->move_player ( ROOM_PATH + "friver2.c");
    return 1;
}
do_west()
{
    message ("3", query_cap_name() + " leaves west.\n", ENV(THIS),THIS);
    message ("3", query_cap_name() + " arrives from east.\n", ROOM_PATH +
      "fpath5.c");
    THIS->move_player ( ROOM_PATH + "fpath5.c");
    return 1;
}
