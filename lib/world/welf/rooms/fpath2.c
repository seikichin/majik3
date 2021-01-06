// DATE        : Tue Feb 10 20:03:10 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Trail in the forest");
  set_long (
    "You're standing on a faint trail in the forest of Sol'daran. T"
  + "he trail leads east to a small clearing and in the south it e"
  + "nds in front of a small cabin that blends almost perfectly wi"
  + "th the surrounding forest. Were it not the revealing plume of"
  + " smoke rising from the cabin's chimney you would most propabl"
  + "y have missed it. Tall trees surround you everywhere and behi"
  + "nd them the forest gets denser.");

  add_exit ("south", ROOM_PATH + "athunter.c");
  add_exit ("east", ROOM_PATH + "fclearing.c");

  add_item ("cabin smoke plume",
    "The cabin is indeed hidden amazingly well. Moss, lichen and sm"
  + "all bushes grow on its roof and its walls are all painted in "
  + "woodland green. The smoke and the scent of cooked rabbit drif"
  + "ting from that direction however make it a lot easier to spot"
  + ".\n");

  add_sound ("A nightingale perks its head and looks at you from its perch on a tall pine.");
  add_sound ("A plume of smoke rises from the cabin's chimney in south.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
