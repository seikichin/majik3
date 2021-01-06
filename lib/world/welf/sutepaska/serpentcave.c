// DATE        : Thu Nov  6 19:26:42 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The serpent's cave");
  set_long (
    "The passageway ends here in a large cave. A strong disgusting "
  + "stench floats in the air and makes you feel sick. The floor o"
  + "f the cave is wholly covered with a chilly mist that floats t"
  + "here with an eerie effect on the atmosphere. Strange moss and"
  + " fungi grow on the walls and ceiling glowing with soft purple"
  + " light. Gory remains of some unfortunate animals decorate one"
  + " corner. A passage leads west from here.");

  add_exit ("west", ROOM_PATH + "caveway4.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
