// DATE        : Sun Feb  8 19:28:54 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Small bridge");
  set_long (
    "You're standing on a small bridge that runs over a lovely fore"
  + "st stream. The stream catches the light in the most enchantin"
  + "g way and sparkles alluringly. Further in the north you spot "
  + "a perfect swimming spot where the river gets wider. A path le"
  + "ads west into the forest and a passage leads east towards the"
  + " swantemple and the city of Sol'daran.");

  add_exit ("east", ROOM_PATH + "pass2.c");
  add_exit ("west", ROOM_PATH + "fpath1.c");

  add_sound ("You can hear laughter and splashing of water in north.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
