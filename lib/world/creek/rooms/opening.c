// DATE        : Mon Nov  3 20:22:08 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("An opening before the city of Silvercreek");
  set_long (
    "You've arrived to an opening before Silvercreek, the city of l"
  + "ight and justice. A statue made of some grey stone is standin"
  + "g at the center of the opening. Roads lead north and south to"
  + " the gates of the city while the mainroad leads east out of t"
  + "he city.");

  add_exit ("south", ROOM_PATH + "outsegate.c");
  add_exit ("north", ROOM_PATH + "outnegate.c");

  add_item ("statue",
    "A statue of a grey swan, the symbol of Silvercreek. You can't "
  + "remember why it is the swan that is the symbol, but you figur"
  + "e out that it has to do something with the founder of the pla"
  + "ce.\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
