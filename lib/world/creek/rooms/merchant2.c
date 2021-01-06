// DATE        : Sun Nov  2 23:03:10 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Merchant street, at the smithy");
  set_long (
    "You're on the Merchant street, where the most of Silvercreeks "
  + "shops are located. A loud banging of metal against metal come"
  + "s from the smithy in west. Above the door is hanging a sign. "
  + "The merchant street leads east. In south the city wall blocks"
  + " your view.");

  add_exit ("east", ROOM_PATH + "merchant1.c");
  add_exit ("west", ROOM_PATH + "smith.c");

  add_item ("sign",
    "A sign above the door reads:\n \n --,-.----.-.--.---.----.--.--."
  + "-.-.\n          |  ,---.              | |\n ------'--|  | --|  "
  + "            |-'\n          |  |-- |MITHY OF      |\n          |"
  + "  `---'  SILVERCREEK |\n          |                     |\n    "
  + "      |   Open: 07-22    |  |\n          |                    "
  + " |\n          |   |              |  |\n          `---'---------"
  + "-'---`--'\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
