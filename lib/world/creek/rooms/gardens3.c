// DATE        : Sun Nov  2 22:47:12 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Ivory Gardens, at the fountain");
  set_long (
    "Beautiful trees cast soft shadows over you as you walk on the "
  + "garden path. The calming sound of dripping water echoes throu"
  + "gh the gardens. A white marble fountain is gurgling happily i"
  + "n here. Ivory statues are placed here and there in the garden"
  + ". They make you feel safe, like if they were watching over th"
  + "e garden. The garden path leads south. A fence blocks your wa"
  + "y in the east where the city streets are.");

  add_exit ("south", ROOM_PATH + "gardens2.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
