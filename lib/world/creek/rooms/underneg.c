// DATE        : Mon Nov  3 20:17:28 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the northern east gate of the city");
  set_long (
    "You're now standing at the Northern East Gate. The Market plac"
  + "e is just west from here and the Academy of Magic on its nort"
  + "hern side. In the east is the gate itself. Made from adamanti"
  + "um, it's almost unbreakable. Two glowing lamps hang on both s"
  + "ides of the gate providing light for the guards and traveller"
  + "s during the night time. The gates are seldom locked, and whe"
  + "n they are the city is prolly under siege. A door leads south"
  + " to a gatehouse. ");

  add_exit ("east", ROOM_PATH + "outnegate.c");
  add_exit ("west", ROOM_PATH + "marketp3.c");
  add_exit ("south", ROOM_PATH + "egatehouse.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
