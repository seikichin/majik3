// DATE        : Wed Mar  4 08:05:42 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Halfling Traders Union");
  set_long (
    "This is well built, straw hut. There are many windows allowing"
  + " a lot of sunshine and air into the place. Before you is a co"
  + "unter about 2 feet high. A large oil lamp is attached to the "
  + "ceiling and there is a poster on the wall behind the counter."
  + "");

  add_exit ("north", ROOM_PATH + "mroad1.c");

  add_item ("symbol carving",
    "The carving is a circle divided into three parts. One sections"
  + " is a depiction of a corn field, the next shows a sword over "
  + "a shield and the third is a pile of gold florins.\n");

  add_item ("poster",
    "^lsartog Th"
  + "e poster is written in sartog and reads:\nAttention! We are no"
  + "w accepting new members. Ask Matthew about merchants or contra"
  + "cts for more information.\n");

  add_item ("lamp oil_lamp",
    "The oil lamp is hung from the ceiling. It is qu"
  + "ite large and provides ample light for this room.\n");

  add_item ("window",
    "Outside you"
  + " see grassy, rolling plains and a dirt road. There are people"
  + " going back and forth on the road and some merchants with woo"
  + "den carts.\n");

  add_item ("counter",
    "The counter is made of wood and stands about 2 fee"
  + "t high. There is a wooden carving on it. Below the symbol it "
  + "says 'Halfling Traders Union'.\n");

  set_outdoors (1);
  set_light (1);

  add_monster (MONSTER_PATH + "matthew.c");
  add_object (ITEM_PATH + "traders_board");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.


