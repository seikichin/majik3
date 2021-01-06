/*
 * Wizardhood application room
 * */

inherit ROOM;

#include "../path.h"

create_room()
{
    set_short("Damaged room");
    set_long("This room was obviously under the gods' flying room when it " +
      "crashed into the hilltop and was damaged badly. There are lots of " +
      "rubble everywhere, but the center of the room has been cleaned up " +
      "a bit so you are able to move here. In the corner there is a pile " +
      "of crumpled papers. Wooden ladder leads up through the ceiling.\n");

    set_light(1);
    set_outdoors(0);

    add_item("rubble", "The whole room has collapsed so badly that there are rubble piles" +
      "everywhere leaving only a small free spot to the middle of the room.\n");
    add_item("papers", "These crumpled papers seem to be partially filled applications.\n");

add_object(MONSTER_PATH + "hermit.c");
    add_exit("up", ROOM_PATH + "room9.c");
}

init ()
{
  ::init();

  add_action ("do_ask", "ask");
}

do_ask (string str)
{
  if(!present("hermit"))
  {
    message("0","But the hermit is not here!\n",THIS);
    return 1;
  }
  return present("hermit")->do_ask(str);
}
