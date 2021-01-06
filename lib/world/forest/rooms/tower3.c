// DATE        : Mon Nov 10 02:24:52 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Library");
  set_long (
    "The walls are covered with bookcases. Every inch of every case"
  + " has a book in it. The room is very large and there are no wi"
  + "ndows. The funiture consists of tables and chairs. The tables"
  + " are lined up in perfect order and there is exactly 4 chairs "
  + "to each. There are a few books laying on some of the tables, "
  + "but most are in the cases. Tis a small, oil lamp hanging from"
  + " the ceiling.");

  add_exit ("west", ROOM_PATH + "tower1.c");

  add_item ("tables table",
    "The tables are made of oak.  There are a few books on the tabl"
  + "es.\n");

  add_item ("bookcases bookcase",
    "The huge oaken cases line the room and are filled with bo"
  + "oks.  They reach all the way up to the ceiling.  Perhaps you "
  + "could take a book from the shelf and read it.\n");

  add_item ("chairs chair",
    "The chairs do n"
  + "ot have any cushioning or pads.  They don't very comfortable."
  + "\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
