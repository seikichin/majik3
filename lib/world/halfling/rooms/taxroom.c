// DATE        : Fri Dec  5 07:22:26 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Collection Office");
  set_long (
    "This room is pretty small for the amout of materials in it. Th"
  + "ere is book after book lined across the back wall, behind a c"
  + "ounter. A sign hangs above the counter and there is a poster "
  + "on north wall. There is a window on south wall.");

  add_exit ("west", ROOM_PATH + "thall.c");

  add_item ("books wall",
    "There are many books and scrolls on the shelves and spread out"
  + " on the tables behind the counter.\n");

  add_item ("window",
    "Outside the window there are people strolling up and down Mark"
  + "et Road.\n");

  add_item ("counter",
    "The counter stands about 1 "
  + "meter high and is made of wood.\n");

  add_item ("sign",
    "Collection Office and Town Re"
  + "cords\n");

  add_item ("law poster",
    "Rules of Conduct Required of Citizens and Visitors to the Shire:\n"
  + "There is not a standing army in the Shire, but there is a police"
  + "force. Law will be upheld by the people. If someone feels anothe"
  + "r has committed a crime they should report it to the mayor and h"
  + "e will decide on the matter. The sheriff and his deputies will s"
  + "troll the streets watching for criminals, but they cannot see ev"
  + "erything.\n"
  + "General laws:\n"
  + "Physical violence not tolerated inside the town borders, except "
  + "in self defence.\n"
  + "People in the town are expected to be clothed decently. You cann"
  + "ot walk around naked.\n"
  + "The Shire is built upon an economy of trade, so honesty is expec"
  + "ted when doing buisness here. People attempting scams or rip-off"
  + "s will be prosecuted.\n\n"
  + "These are general rules, meaning they are not the only laws. Spe"
  + "cial cases will be handled by the Mayor or another offical of th"
  + "e Shire.\n");


  set_outdoors (1);
  set_light (1);

  add_monster (MONSTER_PATH + "taxwoman.c");
  add_object (ITEM_PATH + "regbook.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

