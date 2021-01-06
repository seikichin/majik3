// DATE        : Fri Dec 26 21:30:45 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Small sideroom");
  set_long (
    "Sturdy looking stairs spiral upstairs from here. This room has"
  + " only few pieces of furniture, a couple of benches and a smal"
  + "l table. Tall windows let the wind blow the fresh scent of fo"
  + "rest in from the west. A small doorway leads south to the ent"
  + "rance hall.");

  add_exit ("south", ROOM_PATH + "quentran.c");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
