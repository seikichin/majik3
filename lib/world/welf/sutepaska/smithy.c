// DATE        : Fri Oct 31 14:01:36 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The city smithy");
  set_long (
    "This room is full of tools for forging swords, shields and armou"
  + "rs. Its lit only by the dying embers giving it a red dim ligh"
  + "t. It's still awfully hot here yet the smith isn't working at "
  + "the moment. Everything is covered with a layer of coal dust. "
  + "A door leads east to the street.");

  add_exit ("east", ROOM_PATH + "street.c");

  add_sound ("The dying embers still glow with a deep red light.");
  add_sound ("It's awfully hot in here.");
  add_sound ("You wipe sweat from your forehead.");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
