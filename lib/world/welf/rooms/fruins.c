#include "../path.h"

inherit ROOM;

create_room ()
{
    set_short ("Ruins on the hilltop");
    set_long (
      "Some ancient ruins of a stonebuilding decorate the hilltop you"
      + " are standing on making it look like a rude caricature of a b"
      + "ald king with a stonecrown on his head. From the looks of the"
      + " ruins you guess that there must have been an old watchtower "
      + "on this hilltop in past. The masonry is cracked and partially"
      + " even crumbled to a fine sand. Whatever brought the building "
      + "to crash down must have been huge and terribly powerful. Stee"
      + "p ancient looking stone stairs lead south to the foot of"
      + " this hill. Sea of trees surrounds the hill on every directio"
      + "n as far as you can see. Far in the southeast you can spot th"
      + "e looming form of Que-Moran and the huge tree it is built on."
      + "");

    add_exit ("south", ROOM_PATH + "fpath6.c");

  add_item("ruins stones masonry ground","The ruins look ancient"
 +" and the building must have been in this shape for a long time."
 +" As you look more closely to the crumbled heap of stones you "
 +"notice that there are clear marks of burning and deep gashes, like if something had torn the building down with its giant claws.\n");
    set_outdoors (4);

}

init()
{
    add_action ("do_south","south");
}
do_south()
{
    write ("You walk down the ancient stone stairs to the foot of this hill.\n");
    message ("3", query_cap_name() + "walks down the ancient stonestairs.\n",
      ENV(THIS),THIS);
    message ("3", query_cap_name() + " arrives here from north glancing "
      +"the ruins on the hilltop for one more time.\n", ROOM_PATH + "fpath6.c");
    THIS->move_player ( ROOM_PATH + "fpath6.c" );
    return 1;
}

