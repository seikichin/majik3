inherit ROOM;
#include "../path.h"
                   
create_room()
{
  set_short("Bob's Seed Shop");
  set_long(wrap("This is the shop for farmers to buy seeds for farming."+
  " The wooden walls here have nice green plants growing on them."+
  " There is a small counter just next to the eastern wall. There "+
  "are a few small jars of things on the counter.\n"));
  set_light(1);
  add_object(MONSTER_PATH+"man.c");
  add_item("sign","The sign reads:\n"+
                  "To see what Bob has in store, type 'list'.\n"+
                  "To buy a seed, type 'buy <seed name>'.\n");
  add_item(({"counter","jars","jar"}),"A wooden counter which has a "+
  "few ceramic jars on it, which are locked.  On top of the counter "+
  "is a small sign.\n");
  add_exit("north",ROOM_PATH+"mill2.c");
}
