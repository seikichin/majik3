// DATE        : Tue Jan 20 05:19:47 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Meeting Room");
  set_long (
    "This is a spacious room with many couches and chairs. One high"
  + "-backed chair, imparticular is in the center of the room. Thi"
  + "s place may have been used as a meeting room, judging from th"
  + "e funiture inside. There are is also a window on the north si"
  + "de.");

  add_exit ("east", ROOM_PATH + "tower1.c");

  add_item ("high-backed_chair",
    "The chair in the center of the room is made of solid oak.  The"
  + " back is high\nand it doesn't look very comfortable.  On the b"
  + "ack side of the chair a\ndepiction of a full moon is carved.\n");

  add_item ("chair chairs",
    "T"
  + "here are many chairs in the room.  They are of the same make,"
  + " but of differnt sizes.  There is a chair here for a person o"
  + "f any stature.  They all are facing the center of the room, t"
  + "words the high-backed chair located there.\n");

  add_item ("couch couches",
    "There are couches "
  + "all over the room.  They are plush and look very comfortable."
  + "  They all are facing the center of the room, twords the high"
  + "-backed chair located there.\n");

  add_item ("window",
    "As you peer out the window, you "
  + "see the area just outside the tower.  The ground is covered w"
  + "ith dirt and there is a swirling green mist that surrounds th"
  + "e tower.\n");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
