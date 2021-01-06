// DATE        : Sat Dec  6 22:49:04 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Jail Cell");
  set_long (
    "The cell is clean and in good shape. A hard, wooden bench runs"
  + " the length of the back wall. The bars form the south wall. Y"
  + "ou can see the visitors lobby through the bars. There are no "
  + "windows inside the cell.");

  add_exit ("south", ROOM_PATH + "jailview.c");

  add_item ("bench",
    "The bench is hard, polished wood. It's not very comfortable to"
  + " sit or sleep on, but it's your only option besides the floor"
  + ".\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
