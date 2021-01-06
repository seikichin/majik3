// DATE        : Sat Nov  1 22:44:47 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Burial Chapel");
  set_long (
    "This is the chapel where the high priests of the temple bless "
  + "the dead for the last time. After the dead have been blessed "
  + "no magic can bring them back thus they will finally get the f"
  + "inal rest. The chapel is brightly lit with chandeliers. A sme"
  + "ll of incense fills the air. A door leads out of the chapel t"
  + "o the east.");

  add_exit ("east", ROOM_PATH + "ceme5.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
