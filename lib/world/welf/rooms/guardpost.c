#include "../path.h"

inherit ROOM;

create_room ()
{
    set_short ("Guardpost");
    set_long (
      "The view over the city of Sol'daran seen from this high is mar"
      + "vellous and leaves you completely awestruck. The platform you"
      + "'re standing on is used for watching over the city and guardi"
      + "ng it from possible invaders or raiding orcs. A ropeladder ha"
      + "ngs down from one side of the platform making it easier to cl"
      + "imb down to the platform below this one.");

    set_outdoors (4);

}
init ()
{
    ::init ();
    add_action ( "do_climb", "climb" );
}
do_downwego();
do_climb(string str)
{
    switch (str)
    {
    case "down"   : do_downwego(); return 1;
    default     : notify_fail ("Climb down?");return 0;
    }
}

do_downwego()
{
    write ("You climb down the ropeladder and descend to the platfrom below.\n");
    message ("3", query_cap_name() + " climbs down to the platform below.\n",
      ENV(THIS),THIS);
    message ("3", query_cap_name() + " climbs down from the platform above you.\n",
      ROOM_PATH + "rtreetop2.c");
    THIS->move_player ( ROOM_PATH + "rtreetop2.c");
    return 1;
}
