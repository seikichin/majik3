// DATE        : Sat Nov  1 21:54:28 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("shire");
  set_short ("Fisherman's lane");
  set_long (
    "This is a dirt road that runs north and south. The locals call"
  + " it Fisherman's lane because of the watering hole at the nort"
  + "h end of it. To the south is an intersection at the center of"
  + " the village. There is a hut to the east and a small hill wit"
  + "h a door on the side of it to the west.");

  add_exit ("south", ROOM_PATH + "intersection.c");
  add_exit ("north", ROOM_PATH + "waterhole.c");
  add_exit ("east", ROOM_PATH + "hut1.c");
  add_exit ("west", ROOM_PATH + "burrow1.c");

  set_outdoors(4);

  add_item ("hut",
    "There is a small hut to the east. It is made of wood and straw"
  + " and has a window on either side of the wooden door in the ce"
  + "nter.\n");

  add_item ("hill",
    "To the west is a small hill that appears to be a living"
  + " space for someone. There is a wooden door built right into t"
  + "he side of the hill. Also, there is a small circular window t"
  + "o the right of the door. The hill is only about 5 feet high a"
  + "nd it is completly covered with grass.\n");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
