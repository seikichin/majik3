// DATE        : Sun Nov  2 21:05:14 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Blood Alley");
  set_long (
    "You're walking on a dark passage way called Blood alley. It is"
  + " here where the most of Silvercreeks crimes are committed. Th"
  + "e west gate area and the bazaar before it have a bad reputati"
  + "on. The alley leads east and west. In south the city walls ri"
  + "se before you.");

  add_exit ("east", ROOM_PATH + "grave4.c");
  add_exit ("west", ROOM_PATH + "blood2.c");

  add_object (MONSTER_PATH + "ruffian");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
