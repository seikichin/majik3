// DATE        : Sat Nov  1 21:12:30 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Reception room");
  set_long (
    "You are standing in front of the inn's reception desk. There's"
  + " a note on it. The room is dimly lit so that the customers wo"
  + "n't complain that they can't sleep because of the bright ligh"
  + "ts. And the receptionist has made quite clear that no bullyin"
  + "g noisy customers are allowed upstairs. Stairs lead down to t"
  + "he main room. There's a balcony in the west.");

  add_exit ("down", ROOM_PATH + "sunflower.c");
  add_door ("west", ROOM_PATH + "balcony.c", "door", "wooden", 0, 0, 0);

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
