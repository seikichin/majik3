// DATE        : Sun Jan 18 21:24:42 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("farmers");
  set_short ("Old Mill Road");
  set_long (
    "This road is well trodden, but not as much as the others in th"
  + "e area. Weeds and grass roots are popping up here and there a"
  + "nd some plantlife is growing around the edges of the road. "+
    "In front of you to the north stands an enormous marble building"+ 
    " with its large double doors wide open.  Th"+
   "e road runs west out to the countryside, towards a large, wood"
  + "en structure. Some fields are off to the north and south.");

  add_exit("west", "/world/y93x357");
  add_exit ("north", ROOM_PATH + "univ1.c");
  add_exit ("east", ROOM_PATH + "road8.c");

  add_item ("structure",
    "Off to the east you see a large structure, surrounded by a sma"
  + "ll picket fence. Also, you can see a gigantic wooden wheel of"
  + " sorts attached to the side of it.\n");

  add_sound ("A loud and annoying noise, like the creaking of and old wagon wheel, comes from the building to the east.");
  add_sound ("The air is unusually moist here.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
