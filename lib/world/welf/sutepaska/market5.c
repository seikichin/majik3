// DATE        : Tue Dec 23 14:46:03 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marketplace");
  set_long (
    "This opening in the forest serves as a marketplace for the syl"
  + "van folk. If there weren't all those booths and tents you cou"
  + "ldn't tell a difference between this and a wild forest. Anima"
  + "ls trod freely among the people and seem to blend well in the"
  + " crowd. You can easily tell the difference between the tanir "
  + "booths and those of the foreign shopkeepers. The outlandish b"
  + "ooths look like rude imitations compared to the vine and flow"
  + "er covered booths of the tanir folk.");

  add_exit ("west", ROOM_PATH + "market3.c");
  add_exit ("south", ROOM_PATH + "market2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
