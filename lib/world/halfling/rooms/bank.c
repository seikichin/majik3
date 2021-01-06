// DATE        : Thu Mar  5 04:00:44 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("First Bank of the Shire");
  set_long (
    "As you enter this room, you notice a large counter in front of"
  + " you, which cuts the room in half. There are windows on the e"
  + "ast and west sides. This half of the room is devoid of any fu"
  + "rniture except the large oil lamp attached to the ceiling. Pl"
  + "us, you notice a poster attached to the east wall.");

  add_door ("south", ROOM_PATH + "road4", "door", "wooden", 0, 0, 0);  

  add_item ("lamp oil_lamp",
    "The oil lamp is quite large and provides ample light for this "
  + "room.\n");

  add_item ("window windows",
    "Outside, you see halfling traveling this way and that, "
  + "as well as a few people of other races. The Shire appears to "
  + "be a place full of traffic.\n");

  add_item ("poster",
    "^lsartog Available commands are:\n"+
      "  deposit <amount>\n"+
      "  withdraw <amount>\n"+
      "  loan <amount>\n"+
      "  transfer <amount> to <player>\n"+
      "  balance\n");



  set_outdoors (4);

  add_monster (MONSTER_PATH + "jules.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

