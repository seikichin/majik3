// DATE        : Sun Dec 28 01:06:29 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Swanhall");
  set_long (
    "The throne room of Que-Moran is always filled with light and l"
  + "aughter. Several chandeliers illuminate the hall and bring ou"
  + "t the splendour of elven artists. The walls and ceiling are p"
  + "ainted full of forests, animals and immortal legends. The pol"
  + "ished parquet floor is always free for dancers and musicians."
  + " Opulent throne resembling a majestetic swan rests on the far"
  + " end of the hall. An arched doorway leads west and two smalle"
  + "d doors lead north and south.");

  add_exit ("south", ROOM_PATH + "questa4.c");
  add_exit ("north", ROOM_PATH + "questa3.c");
  add_exit ("west", ROOM_PATH + "queswo.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
