// DATE        : Sat Nov  1 21:09:20 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A quieter room in the tavern");
  set_long (
    "This room is reserved for the rich and important people who li"
  + "ke to eat alone without being interrupted by noisy customers "
  + "who are boozing here. The walls are painted light green and a"
  + "re decorated with golden leaf patterns. Several lamps are pla"
  + "ced on the walls to give the small room light. A table and fo"
  + "ur seats around it have been placed in the middle of the room"
  + ". A doorway leads north to the main room.");

  add_exit ("north", ROOM_PATH + "sunflower.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
