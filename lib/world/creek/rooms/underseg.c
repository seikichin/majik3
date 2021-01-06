// DATE        : Mon Nov  3 20:17:07 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the southern east gate inside the city");
  set_long (
    "You're now standing at the Southern East Gate. Majik street ru"
  + "ns west from here to the Temple Square and the High Temple of"
  + " Truth. On the east is the gate itself. Made from adamantium,"
  + " it's almost unbreakable. Two glowing lamps hang on both side"
  + "s of the gate providing light for the guards and travellers d"
  + "uring the night time. The gates are seldom locked, and when t"
  + "hey are the city is prolly under siege. A door leads north to"
  + " a gatehouse. ");

  add_exit ("east", ROOM_PATH + "outsegate.c");
  add_exit ("west", ROOM_PATH + "majik4.c");
  add_exit ("north", ROOM_PATH + "egatehouse.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
