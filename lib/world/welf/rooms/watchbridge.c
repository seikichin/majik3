#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Narrow ropebridge");
  set_long (
    "The ropebridge is quite narrow and you have some troubles to h"
  + "old it from swaying too much. The bridge leads north and sout"
  + "h to sturdy looking wooden platforms that have been built on "
  + "the treetops. You can see the roof of the swantemple below yo"
  + "u some way in south.");

  add_exit ("south", ROOM_PATH + "treetop1.c");
  add_exit ("north", ROOM_PATH + "rtreetop2.c");

  set_outdoors (4);

}

