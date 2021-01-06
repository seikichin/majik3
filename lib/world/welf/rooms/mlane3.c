// DATE        : Thu Feb 26 13:07:29 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Morninglane");
  set_long (
    "The street ends abruptly here at a magnificent statue. The sta"
  + "tue stands at least ten feet tall and is made of some lumines"
  + "cent white stone. It's sculpted to resemble a tall and majest"
  + "etic elven lord stretching his hands towards the sun. The par"
  + "t of the city in which you are now is where most of the commo"
  + "n folk of Sol'daran live. Beautifully yet simply designed tre"
  + "ehouses occupy most of the treetops around you. The street le"
  + "ads north and a small path leads west.");

  add_exit ("north", ROOM_PATH + "mlane2.c");
  add_exit ("west", ROOM_PATH + "birchop.c");

  add_item ("statue elf lord",
    "The statue is really impressing and you feel quite puny in fro"
  + "nt of the massive elven lord. A plaque in front of the statue"
  + " reads: ^cP
Talanthiel the morninglord^c0\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
