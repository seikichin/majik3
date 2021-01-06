#include "../path.h"
inherit ITEM;
create_item()
{
  set_name(({"bull","white bull","marble bull","white marble bull"}));
  set_short("A glowing white marble bull");
  set_long("This is a perfectly crafted white bull of marble.  It "+
  "glows white and is almost weightless.  Upon its white head "+
  "sit two purple gmes which serve as its eyes.  It body is "+
  "extremely smooth with a long tail.  Two horns protrude from "+
  "the bulls head and are made of purple marble.  As you hold "+
  "this item you feel inner peace and tranquility.\n");
  set_weight(1);
}
init()
{
  add_action("do_go","go");
}
do_go(string what)
{
  if(what == "altar")
  {
      write("You grab the bull by the horns as Madrid has taught you "+
      "to and it becomes alive.  The bull expands to life size and "+
      "stands before you.  You hop onto him and he carries you "+
      "away into the skies.\n");
      message("standard",THIS->query_cap_name()+" grabs his white "+
      "marble bull by the horns.  Suddenly the ground begins to "+
      "shake and tremble.  It turns into the largest white "+
      "bull you have ever seen and stands before you.  "+
      THIS->query_cap_name()+" sits on its back and rides "+
      "off into the the sky.\n",ENV(THIS),THIS);
      THIS->move_player(ROOM_PATH+"altar.c");
      return 1;
  }
return 0;
}
