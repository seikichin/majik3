// DATE        : Sun Nov  2 21:41:38 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Ivory street");
  set_long (
    "You're now walking along Ivory street which has been named aft"
  + "er the knights of Ivory, the gallant defenders of Silvercreek"
  + " and the nobles of the city. The street continues to the nort"
  + "h and south. A short street leads east to Chapel street. A fe"
  + "nce blocks your way in the west. You can see the garden behin"
  + "d it.");

  add_exit ("south", ROOM_PATH + "ivory2.c");
  add_exit ("north", ROOM_PATH + "ivory4.c");
  add_exit ("east", ROOM_PATH + "tochap1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
