#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Riverside");
  set_long (
    "You're standing on the west side of a nice stream. The stream "
  + "gets wider at this point forming a perfect swimming place sur"
  + "rounded by beautiful birches and glittering stones on the riv"
  + "erbanks. A taller pinetree stands near the riverbed and archs"
  + " slightly over the river. A sturdy rope hangs down from one of "
  + "its strongest limbs allowing easier way to climb up on its pe"
  + "rches. A small path runs south along the stream.");

  add_exit ("east", ROOM_PATH + "river.c");
  add_exit ("south", ROOM_PATH + "fpath1.c");

  add_sound("The sound of flowing water is very relaxing.\n");
  add_sound("The sound of flowing water is very relaxing.\n");
  add_sound("The water sparkles very invitingly.\n");
  add_sound("It wouldn't do bad to swim in the river...\n");
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
  notify_fail ("Climb where? The tree perhaps?\n");
  return 0;
  }
  write ("You climb up to the tree.\n");
  message ("3", query_cap_name() + " climbs up to the tree.\n", ENV(THIS),THIS);
  message ("3", query_cap_name() + " climbs up the rope and pants heavily.\n", ROOM_PATH +
  "rivertree.c");
  THIS->move_player ( ROOM_PATH + "rivertree.c");
  return 1;
}
