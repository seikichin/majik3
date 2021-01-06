// DATE        : Sun Nov  2 22:45:42 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Ivory Gardens");
  set_long (
    "Beautiful trees cast soft shadows over you as you walk on the "
  + "garden path. The calming sound of dripping water echoes throu"
  + "gh the gardens. A white marble fountain is gurgling happily i"
  + "n the north. Ivory statues are placed here and there in the g"
  + "arden. They make you feel safe, like if they were watching ov"
  + "er the garden. The garden path leads north to the fountain an"
  + "d a door leads west to the building. A fence blocks your way "
  + "in the east where the city streets are.");

  add_exit ("north", ROOM_PATH + "gardens3.c");
  add_exit ("west", ROOM_PATH + "gardens4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
