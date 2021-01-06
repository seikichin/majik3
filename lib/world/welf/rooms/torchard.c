// DATE        : Mon Dec 29 15:49:43 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Small path");
  set_long (
    "The small path you're walking along leads west where you can s"
  + "pot some apple and plumtrees. Slightly arching birches line t"
  + "he path on both sides and cast their soft shadows over you. T"
  + "he path joins the mainstreet of Sol'daran in west.");

  add_exit ("east", ROOM_PATH + "street.c");
  add_exit ("west", ROOM_PATH + "orchard1.c");

  add_sound ("Sweet smell drifts in from west.");
  add_sound ("You can hear people hurrying in east.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
