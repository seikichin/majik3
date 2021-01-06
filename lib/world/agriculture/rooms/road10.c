// DATE        : Sun Jan 18 02:53:43 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("In front of the cabin");
  set_long (
    "You stand on a dirt road before a small log cabin. The front d"
  + "oor, made of wood and rounded at the top, stands open. The ro"
  + "ad goes away north and there is a picket fence to the northea"
  + "st. Above the door is a white sign.");

  add_exit ("enter", ROOM_PATH + "cabin1.c");
  add_exit ("north", ROOM_PATH + "road9.c");
  add_object(MONSTER_PATH+"drakar.c");
  add_item ("sign",
    "School of Elemetary Agriculture\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
