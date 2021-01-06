// DATE        : Mon Nov  3 21:28:01 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Midway up the tower");
  set_long (
    "Oh boy, are these stairs steep and endless. You just couldn't "
  + "keep counting the steps at thousand. The atmosphere here is v"
  + "ery tense, the air itself seems to be full of wild magic. The"
  + " stone from which the walls and stairs are made glows occasio"
  + "nally with all the colours of the rainbow. A gush of wind com"
  + "es from nowhere and blows softly on your face. A constant tap"
  + "ping sound echoes from somewhere. The stairs lead up and down"
  + " from here.");

  add_exit ("down", ROOM_PATH + "tower1.c");
  add_exit ("up", ROOM_PATH + "tower3.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
