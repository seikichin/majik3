// DATE        : Sun Nov  2 20:39:31 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marketplace, the northwest corner");
  set_long (
    "You're walking among the crowd in the Silvercreek's Market pla"
  + "ce. People push you rudely aside as they hurry by you. The Ma"
  + "rket place continues to east and south. The Academy of Magic "
  + "is on your northern side, blocking the view. The massive buil"
  + "ding casts a huge shadow over the Market place. Its doors are"
  + " a short distance in the east.");

  add_exit ("south", ROOM_PATH + "marketp7.c");
  add_exit ("east", ROOM_PATH + "marketp10.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
