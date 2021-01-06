// DATE        : Sun Nov  2 22:50:57 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the sign of the Drunken Dragon's Inn");
  set_long (
    "You've arrived to the sign of the famous Drunken Dragon's Inn."
  + " Merry voices and cheers and occasional songs welcome you in."
  + " The house itself is painted in red and the sign above the do"
  + "or is made to resemble a drinking dragon. A short street lead"
  + "s north and in the east you can see the inn stables.");

  add_exit ("north", ROOM_PATH + "alley1.c");
  add_exit ("east", ROOM_PATH + "stables.c");
  add_exit ("west", ROOM_PATH + "inn1.c");

  add_item ("sign",
    "Above the door is hanging a sign:\n \n                       *\n "
  + "                    **\n               *   ****   *\n          "
  + "    **    **   **     THE DRUNKEN DRAGON'S INN\n            **"
  + "***  *** *****    -------------------------\n           ******"
  + "************   CHEAP ROOMS AND EXCELLENT\n           *** *****"
  + "**** *****  SERVICE! ALSO CHEAPEST &\n          ***    ****** "
  + "   ***  BEST ALE IN SILVERCREEK!!\n          **      *****    "
  + " **  -------------------------\n          *       ****       *"
  + "\n                  ***   *\n                  **   **\n        "
  + "           ** **\n                    ***\n                    "
  + " *\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
