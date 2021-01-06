// DATE        : Mon Nov 10 02:28:47 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Staircase");
  set_long (
    "The staircase is circular and is so wide it must take up the w"
  + "idth of the tower. You are beginning to wonder if this will e"
  + "ver end. From the view outside it seems that you should be on"
  + " the roof by now. The painting on the wall is the only thing "
  + "of interest here.");

  add_exit ("down", ROOM_PATH + "tower6.c");
  add_exit ("up", ROOM_PATH + "tower8.c");

  add_item ("painting",
    "The paintings that line the stairway seem to be telling someki"
  + "nd of story or of some event.  This one shows three sections "
  + "of quarter moon.  They are in each corner of the picture, exc"
  + "ept the lower left.  As before, the moon sections are glowing"
  + ".\n");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
