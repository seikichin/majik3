// DATE        : Mon Nov  3 21:03:40 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A burrow");
  set_long (
    "This is one of the halfling's burrows. There must be a full fa"
  + "mily living here because, besides the fireplace and table in "
  + "the room, there are three beds. One is large enough for two h"
  + "alfings while the other two are bunk beds.");

  add_exit ("east", ROOM_PATH + "yard.c");

  set_outdoors(1);

  add_item ("bed beds",
    "There is one large bed here, made for two people. Also, there "
  + "is a bunk bed. They all have straw mattress and pillows.\n");

  add_item ("window",
    "You "
  + "can see a garden outside the window. It is surrounded by a wh"
  + "ite picket fence.\n");

  add_item ("table",
    "The table is empty is made of wood and is e"
  + "mpty.\n");

  add_item ("fireplace",
    "The fireplace and chimmney are made of stone. It is not"
  + " currently lit.\n");

  add_monster (MONSTER_PATH + "sammy.c");
  add_monster (MONSTER_PATH + "manny.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

