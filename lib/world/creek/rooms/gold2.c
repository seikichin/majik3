// DATE        : Sun Nov  2 22:12:15 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Gold street, at the bank");
  set_long (
    "You're standing before the Bank of Silvercreek. The street has"
  + " been named after it. Gold street leads north and south from "
  + "here. In west are the bank doors. On the both sides of the do"
  + "or is placed a statue of M'aenoe the demon of greed. It is to"
  + " remind the citizens of the dangers of being greedy. Above th"
  + "e door is hanging a sign.");

  add_exit ("south", ROOM_PATH + "gold1.c");
  add_exit ("north", ROOM_PATH + "arcane1.c");
  add_exit ("west", ROOM_PATH + "bank.c");

  add_item ("sign",
    "Above the bankdoor is hanging a sign:\n \n            THE BANK O"
  + "F\n                 ||\n                ****\n               **|"
  + "|**\n              ***|| **\n               **||\n              "
  + "  *** ILVERCREEK\n                 |***\n              ** ||***"
  + "\n               **|***\n                ****\n                 "
  + "||\n \n");

  add_item ("demon statue m'aenoe",
    "M'aenoe, the demon of greed is well known among the lege"
  + "nds of Silvercreek. The tale goes that once the demon lived n"
  + "ear the city gathering silver and gold in its cave. The demon"
  + " was so fond of the precious metals that it wanted to possess"
  + " the silvery creek which ran across the land. With a mighty s"
  + "pell it changed the waters course to its treasury and of cour"
  + "se the masses of water crushed and drowned the greedy bastard"
  + " and its unearthly treasures. Still there are some fool enoug"
  + "h to try to seek the demon's lair and all of those who have t"
  + "ried have shared the demon's fate.\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
