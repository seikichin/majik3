// DATE        : Sun Dec 28 01:04:37 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Hall of swords");
  set_long (
    "This long hall is brightly lit by two magnificent crystal chan"
  + "deliers. Each wall is full of swords and shields bearing the "
  + "coat of arms of various clans and families in Sol'daran. A lo"
  + "ng red carpet covers almost the entire floor. An arched doorw"
  + "ay leads east to the throne room of Que-Moran. A sturdy door "
  + "leads west to the entrance hall.");

  add_exit ("east", ROOM_PATH + "queswan.c");
  add_exit ("west", ROOM_PATH + "quentran.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
