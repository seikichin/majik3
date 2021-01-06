// DATE        : Mon Dec  8 05:16:44 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Market Road");
  set_long (
    "You are walking along Market Road, on the east side of the Shi"
  + "re. The road is dirt, and well paved. To the west you can see"
  + " many buildings, while to the east is a grove of trees.");

  add_exit ("east", ROOM_PATH + "grove1.c");
  add_exit ("west", ROOM_PATH + "road5.c");

  add_item ("buildings",
    "You see many buildings off to the west. It must be the city ce"
  + "nter of the Shire.\n");

  add_item ("grove trees",
    "There is a dense grove of trees directly t"
  + "o the east.\n");

  add_sound ("You hear the chatter of many voices coming from the west.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
