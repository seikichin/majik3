#include "../path.h"

inherit ROOM;

create_room ()
{
    set_short ("A cliff above the waterfall");
    set_long (
      "Stones form a small ledge here over the waterfall. Below, you can hear the "
      +" water roaring. Cooling mist tingles your face and as the light is filtered "
      +"through the mist a small rainbow forms just a few feet from you in the midair."
      +" Maybe you could leap on it if you tried. Stairs lead down from here "
      +"towards the pool below.");

    add_sound ("The waterfall roars below you.\n");
    add_sound ("The rainbow is quite a magnificent sight.\n");
    add_exit ("down", ROOM_PATH + "atpool.c");
    add_item ("rainbow","The rainboaw floats in the mid air, quite an impressive"
      +"sight.\n");
}
init ()
{
    ::init ();
    add_action ( "do_leap", "leap" );
}
do_leap()
{
    write ("You leap down from the ledge and plummet through the rainbow"
      +" towards the pool below. You hit the surface of the pool with a tremendous splash and sink under the surface into the icy cold water.\n");
    message ("3", THIS->query_cap_name()+" leaps bravely down from the cliff.\n",
ENV(THIS),THIS);
    message ("3", THIS->query_cap_name()+" dives from the cliff above and hits"
      +" the surface of the pool splashing water over you.\n", ROOM_PATH +
"atpool.c");
message ("3", THIS->query_cap_name()+" dives from the cliff above you and splashes water over you as he hits the surface.\n", ROOM_PATH + "pool.c");
    message ("3", THIS->query_cap_name()+"dives under the water from above.\n",
      ROOM_PATH + "underpool.c");
    THIS->move_player ( ROOM_PATH + "underpool.c");
    return 1;
}
