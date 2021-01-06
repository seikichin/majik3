inherit ROOM;
#include "../path.h"

create_room()
{
  set_light(1);
  set_outdoors (0);

  set_short("Velinax's Supply Store");
  set_long(wrap("This is a small room in which most farmers come "+
  "to buy their items for planting and harvesting crops. The owner "+
  "of the shop named Velinax Belmonte. If he is in maybe he will "+
  "sell you a few things. Other than the sign on the wall there is really "+
  "nothing of interest in this room.\n"));
  add_object(MONSTER_PATH+"man2.c");
  add_item("sign","The sign reads:\n"+
                  "To see what Velinax has in store, type 'list'.\n"+
                  "To buy an item, type 'buy <item name>'.\n");
  add_exit("south",ROOM_PATH+"mill3.c");
}
