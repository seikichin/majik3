// DATE        : Mon Nov  3 21:25:40 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Dragon's Flame armoury");
  set_long (
    "The room is decorated in dwarven style, glittering jewels and "
  + "golden ornaments everywhere. The shop desk itself is made fro"
  + "m some strange stone which glows softly being the only light "
  + "source in here. Shining armours and shields are stacked on wa"
  + "lls and shelves. A door leads south back to the streets.");

  add_exit ("south", ROOM_PATH + "merchant3.c");
  add_object (MONSTER_PATH + "khirz");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
