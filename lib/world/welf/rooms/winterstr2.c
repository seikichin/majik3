// DATE        : Tue Feb  3 19:14:47 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Winterstreet");
  set_long (
    "Winterstreet runs north from the holy swantemple towards the c"
  + "ity cemetary. Few elves will walk here for the death is somet"
  + "hing they won't take lightly. Elves come to the cemetary only"
  + " during the burial ceremonies and on a few rare occasions. Th"
  + "e street leads slightly downwards to the cemetary gates in no"
  + "rth. The cemetary behind the gates appears to be a grove of s"
  + "ome sort. The street leads south and in the east there is a b"
  + "uilding made of shining white stone. From the looks of it, th"
  + "e building must be a burial chapel.");

  add_exit ("south", ROOM_PATH + "winterstr.c");
  add_exit ("north", ROOM_PATH + "sylcem1.c");
  add_exit ("east", ROOM_PATH + "bchapel.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
