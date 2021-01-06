// DATE        : Sun Nov  2 20:30:43 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marketplace");
  set_long (
    "You've arrived to the Market place of Silvercreek. The Market "
  + "place is filled with people, customers and salesmen, thieves "
  + "and tricksters, and they all are in a hurry doing whatever th"
  + "ey can in this crowd. The Market place stretches itself to th"
  + "e east, west and north. In the north the massive building of "
  + "the Academy of Magic dominates the view. A curious looking bo"
  + "oth is nearby in the north.");

  add_exit ("north", ROOM_PATH + "marketp8.c");
  add_exit ("east", ROOM_PATH + "marketp2.c");
  add_exit ("west", ROOM_PATH + "marketp1.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
