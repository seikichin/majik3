// DATE        : Mon Nov  3 21:29:07 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Top of the tower");
  set_long (
    "This is the room of the ruling arch mage. The room is full of "
  + "books, scrolls and magical items. Runes of watching and prote"
  + "ction are engraved to the walls and floor. A glowing crystal "
  + "pinnacle at the center of the room radiates red light bright "
  + "enough to read by. If the atmosphere was tense at the bottom "
  + "of the tower it's solid here. The magic can be felt everywher"
  + "e in here. It tickles you and makes your neck hair stand. Sta"
  + "irs lead downstairs.");

  add_exit ("down", ROOM_PATH + "tower2.c");
  add_object (MONSTER_PATH + "cazares");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
