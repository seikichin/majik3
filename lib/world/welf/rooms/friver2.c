#include "../path.h"

inherit ROOM;

create_room ()
{
    set_short ("Riverside");
    set_long (
      "The path ends here at a sparkling stream. The current looks qu"
      + "ite strong at this spot so it would be impossible to swim ove"
      + "r the river to the east side. A sturdy looking ropebridge how"
      + "ever crosses the river from the treetop of a pine that grows "
      + "on this side of the river to another one on the east side. A"
      + " knotted rope has been tied to one of its limbs allowing easi"
      + "er way to climb up to its perches. A faint path leads west fr"
      + "om here.");

    add_exit ("west", ROOM_PATH + "fpath6.c");

  add_sound("The sound of flowing water makes you relax.\n");
  add_sound("The current looks quite strong here.\n");
  add_sound("You can hear splashing of water some distance in south.\n");
    set_outdoors (4);

}


init ()
{
    ::init ();
    add_action ( "do_climb", "climb" );
}
do_climb(string str)
{
    if (!str || str != "tree") {
	notify_fail ("Climb where? To the tree perhaps?\n");
	return 0;
    }
    write ("You climb up to the tree.\n");
    message ("3", query_cap_name() + " climbs up to the tree.\n", ENV(THIS),THIS);
    message ("3", query_cap_name() + " arrives from down and pants heavily.\n",
      ROOM_PATH +
      "rtreetop1.c");
    THIS->move_player ( ROOM_PATH + "rtreetop1.c");
    return 1;
}
