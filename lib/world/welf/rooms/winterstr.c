// DATE        : Fri Oct 31 14:38:09 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Winterstreet");
  set_long (
    "The Winterstreet runs north from the holy swan temple towards "
  + "the city cemetary. Few people walk here for the deaths of the"
  + "ir loved ones isn't something they take lightly. Elves come t"
  + "o the cemetary only during the burial ceremonies and on a few"
  + " occasions when they honor some long dead hero of the forest "
  + "realms. The street continues north to the gates of the cemeta"
  + "ry and to the south where you can see the totem of winter and"
  + " the swan temple.");

  add_exit ("south", ROOM_PATH + "winter.c");
  add_exit ("north", ROOM_PATH + "winterstr2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
