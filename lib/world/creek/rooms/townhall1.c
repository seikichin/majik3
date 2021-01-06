// DATE        : Mon Nov  3 20:55:34 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Town Hall");
  set_long (
    "You're standing in a big entrance hall. On the granite floor i"
  + "s written in big golden letters the word Silvercreek. Several"
  + " doors lead to the other parts of the town hall. A door in th"
  + "e west leads to the common office. If you have any ideas or s"
  + "uggestions how to improve the city or if you want to complain"
  + " about something not working, you can leave a message in ther"
  + "e.");

  add_exit ("west", ROOM_PATH + "townhall2.c");
  add_exit ("east", ROOM_PATH + "candle6.c");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
