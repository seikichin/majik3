// DATE        : Sun Dec 28 01:32:32 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Long hallway");
  set_long (
    "The long hallway you're standing in runs in east-west directio"
  + "n. The floor is covered with a long green carpet. Few oil lam"
  + "ps on the walls provide light to the hallway and at the both "
  + "ends of the hallway is a large colorstained glasswindow. Stur"
  + "dy stairs lead downstairs. A door leads south.");

  add_exit ("south", ROOM_PATH + "quero6.c");
  add_exit ("east", ROOM_PATH + "queha5.c");
  add_exit ("down", ROOM_PATH + "questa2.c");
  add_exit ("west", ROOM_PATH + "queha4.c");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
