// DATE        : Sun Nov  2 22:32:38 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The crossing of Northern Temple street and Grave street");
  set_long (
    "You're now at the other end of the Northern Temple street wher"
  + "e it joins the Grave street. The Temple street continues to t"
  + "he east and the Grave street leads south. You can see a chape"
  + "l in the cemetary over the fence.");

  add_exit ("south", ROOM_PATH + "grave7.c");
  add_exit ("east", ROOM_PATH + "ntemple5.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
