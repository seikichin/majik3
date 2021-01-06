#include "../path.h"
inherit ROOM;
create_room()
{
  set_area("temple");
  set_short("Outside a beatiful white temple");
  set_long("You are standing outside a enormous white temple.  "+
  "The top of which you cannot see because it raises up into "+
  "the clouds.  It is made completely of white shinny marble, "+
  "so bright you almost have to squint your eyes .  The windows "+
  "and ledges that surround its exterior are made of the most "+
  "beatiful shade of purple you have ever seen.  A large "+
  "drawbridge is lowered down for you to enter.\n");
  set_outdoors(4);
  add_item(({"cloud","clouds"}),"Clouds cover the top of the temple.\n");
  add_item(({"windows","window","ledge","ledges"}),"Beautiful windows"+
  " can be seen on the exterior of the temple.\n");
  add_item("drawbridge","A large wooden drawbridge is lowered down "+
  "for all to enter.\n");
  add_item("temple","This is the most beautiful temple you have ever"+
  " seen.  This must have been erected to worship one of the best "+
  "gods this land has ever seen.\n");
  set_sounds(40,"The clouds hover over the sharpe spire at the top "+
  "of the temple.\n");
  add_sound("The temple seems to be surrounded by a magical aura.\n");
  add_sound("You feel completely at peace looking upon the temple.\n");
  add_sound("Goodness and peace seem to radiate from the temple.\n");
  add_exit("enter",ROOM_PATH+"temple1.c");
  add_exit("northwest","/world/y49x35");
  add_object(MONSTER_PATH+"bull.c");  
}
 
