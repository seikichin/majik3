// DATE        : Sun Jan 25 22:47:58 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Hall of Knowledge");
  set_long (
    "This hall has a high ceiling and tall pillars lining the walls"
  + ". They are all made of black obsidian and gleam in the reflec"
  + "tion of the lamps which are postioned around the hall on peda"
  + "stals. It runs on to the west and there are archways leading "
  + "east and south.");

  add_exit ("west", ROOM_PATH + "studyroom.c");
  add_exit ("south", ROOM_PATH + "univ1.c");
  add_exit ("east", ROOM_PATH + "unihall2.c");

  add_item ("pillar pillars",
    "The pillars line the walls about 2 meters away from them. They"
  + " are too numerous to count and you can only guess at their he"
  + "ight, since they reach all the way to the ceiling above.\n");

  add_item ("lamp lamps pedastal pedastals",
    "The "
  + "pillars stand about 1 meter high and on top of each is a larg"
  + "e oil lamp to provide some light for the immense hall.\n");

  add_item ("obsidian wall walls",
    "This e"
  + "ntire room is made of the gleaming black obsidian. You can al"
  + "most make out your relection in it.\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
