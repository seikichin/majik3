// DATE        : Thu Mar 12 23:29:32 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Elegant hall");
  set_long (
    "This hall isn't quite as big as the one downstairs, but it is "
  + "every bit as elegant. A round polished mahogany table stands "
  + "at the center of the hall. Around the table has been placed e"
  + "ight chairs. A softly glowing crystal chandelier provides enc"
  + "hanting light to the hall making the shadows look deeper and "
  + "highlighting the many decorations. Small doorways lead north "
  + "and south.");

  add_exit ("west", ROOM_PATH + "quebed.c");
  add_exit ("south", ROOM_PATH + "questa8.c");
  add_exit ("north", ROOM_PATH + "questa7.c");

  add_item ("crystal chandelier",
    "You are not sure if it's the crystals or the candles that glow"
  + " so enchantingly, but the chandelier creates a magnificent at"
  + "mosphere to the room.\n");

  add_item ("chairs table",
    "The polished surface of the table refle"
  + "cts the domed and intricately decorated ceiling perfectly. Th"
  + "e eight chairs around the table look very comfortable.\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
