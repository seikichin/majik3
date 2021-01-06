// DATE        : Sun Jan 18 20:32:57 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("farmers");
  set_short ("Farmers' Drive");
  set_long (
    "The road is heading north and south. East of you is a wooden p"
  + "icket fence surrounding a large structure. To the south is a "
  + "small log cabin with a sign above the door. Off to the west a"
  + "re rows and rows of fields.");

  add_exit ("south", ROOM_PATH + "road10.c");
  add_exit ("north", ROOM_PATH + "road8.c");

  add_item ("cabin",
    "The log cabin is rather small. The front door is standing open"
  + ".\n");

  add_item ("sign",
    "You can't make you the words from here.\n");

  add_item ("structure",
    "The large structure"
  + " is to the northeast of you. There is a huge water wheel in t"
  + "he river with flows around the southeastern side of the build"
  + "ing.\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
