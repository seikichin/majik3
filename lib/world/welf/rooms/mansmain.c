// DATE        : Thu Feb 26 12:42:35 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Mainhall of the mansion");
  set_long (
    "You stand withing a beautiful mainhall. Upon the wooden walls "
  + "of the hall have been hung several tapestries depicting glori"
  + "ous legends of the elven realm. Green glowing crystals attach"
  + "ed to holders on the walls create an enchanting atmosphere to"
  + " the room. A large, expertly carved wooden table and six chai"
  + "rs dominate the midst of the hall. There are also few shelves"
  + " with sculptures on them and two big windows allowing the day"
  + "light to flood in. A red carpet covers most of the floor.");

  add_exit ("north", ROOM_PATH + "manskit.c");
  add_exit ("east", ROOM_PATH + "mansent.c");
  add_exit ("west", ROOM_PATH + "mansden.c");
  add_exit ("south", ROOM_PATH + "mansliv.c");

  add_item ("shelves sculptures",
    "The shelves are all full of sculptures. Most of the sculptures"
  + " look worthless and you guess the sculptor hasn't been much o"
  + "f an artist.\n");

  add_item ("table chairs",
    "The chairs and the table are all carved full of "
  + "small intervowen patterns formed of animal shapes. Whoever ha"
  + "s carved them must have been an expert.\n");

  add_item ("windows",
    "The view is nice and "
  + "you could spend a long time watching the activities in the su"
  + "rrounding city and the forest.\n");

  add_item ("crystal crystals",
    "Multifaceted luminescent stone"
  + "s that glow with bright green light. They are all firmly atta"
  + "ched to the holders on the walls.\n");

  add_item ("carpet",
    "The carpet is emroidered wi"
  + "th intricate designs of flowers surrounding a blazing sun.\n");

  add_item ("tapestries",
    "Th"
  + "ey all seem to depict numerous legends of the tanir realm. As"
  + " fine as they look you doubt they'd be of any worth to non-el"
  + "ven people.\n");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
