// DATE        : Sun Dec 28 01:43:06 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Strangely furnished room");
  set_long (
    "The small room you are standing in is furnished kind a strange"
  + "ly. Two walls are fully covered by bookcases and the north wa"
  + "ll has a large window on it. Before the window is placed a st"
  + "one pedestal and on it rests a thick old tome. A big pluffy p"
  + "illow rests at the center of the floor. A door leads south.");

  add_exit ("south", ROOM_PATH + "questa5.c");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
