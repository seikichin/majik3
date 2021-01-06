// DATE        : Sat Dec  6 22:49:25 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Visiting Room");
  set_long (
    "This room is connected directly to the town jail cell. There i"
  + "s a bench along the wall on one side with the bars of the cel"
  + "l on the opposite. There is an oil lamp attached to the wall "
  + "and a small, round table in the center of the room.");

  add_exit ("east", ROOM_PATH + "thall.c");
  add_exit ("north", ROOM_PATH + "cell.c");

  add_item ("lamp",
    "The oil lamp hangs from a large nail in the wall. It provides "
  + "decent light in the room.\n");

  add_item ("bench",
    "The bench streches the full length "
  + "of the wall. It is a sturdy, wood structure which was not des"
  + "igned for comfort.\n");

  add_item ("table",
    "The table is a half-ass made thing, but it"
  + " does the job.\n");

  add_item ("cell bars",
    "The bars of the jail cell are thick steel, but"
  + " are beginning to show signs of wear and tear. The cover one "
  + "entire wall of the room from floor to ceiling.\n");

  add_sound ("It smells a little nasty in here.");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
