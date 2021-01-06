// DATE        : Mon Jan  5 08:04:29 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Old Mill Road");
  set_long (
    "This road is well trodden, but not as much as the others in th"
  + "e Shire. Weeds and grass roots are popping up here and there "
  + "and some plantlife is growing around the edges of the road. T"
  + "he road runs west to Fisherman's Lane and east, twords a larg"
  + "e, wooden structure.");

  add_exit ("east", ROOM_PATH + "road8.c");
  add_exit ("west", ROOM_PATH + "road3.c");

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
