// DATE        : Sun Dec 28 00:50:02 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Servants' quarters");
  set_long (
    "This is the room where the servants of Que-Moran can rest and "
  + "reverie for elves need not to bother themselves with sleeping"
  + ". The floor is covered with a soft mosslike carpet and the wa"
  + "lls are decorated with a couple of paintings. Large window on"
  + " the north wall gives a nice view to the forest below. A door"
  + " leads south from here.");

  add_exit ("south", ROOM_PATH + "quese.c");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
