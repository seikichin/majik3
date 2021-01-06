// DATE        : Thu Mar 12 23:50:16 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Que-Moran's library");
  set_long (
    "You're standing in the library of Que-Moran, that is one of th"
  + "e most remarkable places for gathering information. Several h"
  + "uge bookcases are filled with thousands of books. A great rou"
  + "nd table has been placed at the center of the libraryhall and"
  + " around it stand several comfortable looking chairs. Several "
  + "brightly glowing crystals near the ceiling line provide enoug"
  + "h light to the hall to read by. The east wall and the ceiling"
  + " are both made of several windows providing excellent view to"
  + " the sky and the surrounding forest in east. Short stairs lea"
  + "d west to an observatory. Doorways lead north and south. ");

  add_exit ("west", ROOM_PATH + "queobs.c");
  add_exit ("south", ROOM_PATH + "questa10.c");
  add_exit ("north", ROOM_PATH + "questa9.c");

  add_item ("bookcases cases bookcase case books",
    "All of the bookcases are filled with at least a thousand of bo"
  + "oks all neatly arranged in chronological or alphabethical ord"
  + "er. You could spend a lifetime reading these books.\n");

  add_item ("crystal crystals",
    "These cry"
  + "stals glow very brightly and provide enough light to read by."
  + " They are obviously firmly attached to the walls and are in a"
  + "ny case too high for you to reach.\n");

  add_item ("table chairs",
    "At least twenty persons co"
  + "uld easily fit around the great table. The polished surface o"
  + "f the table reflects the image of the sky most enchantingly.\n"
  + "");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
