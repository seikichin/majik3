
#include "../path.h"

inherit ROOM;

create_room ()
{
    set_short ("Platform in the tree");
    set_long (
      "You're standing on a sturdy platform that has been built on co"
      + "uple of sturdy treelimbs of this pine. Narrow ropebridges lea"
      + "d west and south to similar platforms as this. The ropebridge "
      + "that leads west crosses a sparkling river that looks very invi"
      + "ting. A ropeladder hangs down from a platform higher in the tr"
      + "ee.");

    add_exit ("west", ROOM_PATH + "rover.c");
    add_exit ("south", ROOM_PATH + "watchbridge.c");

    set_outdoors (4);

}

init ()
{
    ::init ();
    add_action ( "do_climb", "climb" );
}

do_upwego()
{
    write ("You climb up the ropeladder to the platfrom above.\n");
    message ("3", query_cap_name() + " climbs up to the platform above.\n",
      ENV(THIS),THIS);
    message ("3", query_cap_name() + " climbs up from the platform below "
      +"you.\n", ROOM_PATH + "guardpost.c");
    THIS->move_player ( ROOM_PATH + "guardpost.c");
    return 1;
}

do_climb(string str)
{
    switch (str)
    {
    case "up"   : do_upwego(); return 1;
    default     : notify_fail ("Climb up?"); return 0;
    }
}
