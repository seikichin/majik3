// DATE        : Tue Mar  3 22:27:53 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Autumn passage");
  set_long (
    "As you walk along the leafcovered passageway you notice how co"
  + "lorful the nature can be during autumn. Myriad shades of red,"
  + " green and brown decorate the treetops and the fresh autumn a"
  + "ir lifts your spirits up and makes you smile. A short distanc"
  + "e in the east you spot the holy swantemple and in the west th"
  + "e passageway continues towards the surrounding forest.");

  add_exit ("east", ROOM_PATH + "autumn.c");
  add_exit ("west", ROOM_PATH + "pass2.c");

  add_item ("temple swantemple",
    "The temple looks quite ancient with its weatherbeaten stonewor"
  + "k and gothic design. You sense an aura of peace and serenity "
  + "surrounding it.\n");

  add_sound ("A plume of smoke rises from the temple in east.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
