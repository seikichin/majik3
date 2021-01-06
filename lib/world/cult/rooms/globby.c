// DATE        : Tue Dec  2 18:57:38 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Study Lounge");
  set_long (
    "You have entered a study lounge. There are chairs and tables a"
  + "ll around so students can sit and comfortably study. The are "
  + "many arches cut into the stone that lead to various sections "
  + "of the study. There are oil lamps placed at various places ar"
  + "ound the room.");

  add_exit ("east", ROOM_PATH + "stair1.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
