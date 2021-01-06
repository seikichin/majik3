// DATE        : Sun Nov  2 23:06:41 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Merchant street, at the armourer's sign");
  set_long (
    "You're walking along the Merchant street which is the commerci"
  + "al part of the city. The most of the shops of Silvercreek are"
  + " here. The Armourer's shop is in the north. In the window are"
  + " placed shiny new armours and shields. The street continues t"
  + "o the east and west. The city wall blocks your way in south.");

  add_exit ("north", ROOM_PATH + "armourer.c");
  add_exit ("east", ROOM_PATH + "merchant4.c");
  add_exit ("west", ROOM_PATH + "merchant1.c");

  add_item ("window sign",
    "   ,-----------------------------------------.    +---- --- --"
  + " -\n   |                                         |    | +-----"
  + "-- -- -\n   |         Dragon's Flame Armoury          |    | |"
  + "\n   |         ----------------------          |    | |   Drag"
  + "on's flame\n   | ,----.    :::::::                  .    |    "
  + "| H       Armoury\n   | |----|    ::::  |   .. ...:     ..... "
  + "  |    | |\n   |--.() |    |_____|   .  : .:  ........   |    "
  + "| |\n   |  |  /'       |      :.  :::  :    :::   |    | |\n   "
  + "|__|`'______=--+--____:....::_____________|    | |\n   `------"
  + "-----------------------------------'    | H\n                 "
  + "                                 | |\n                        "
  + "                          | :\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
