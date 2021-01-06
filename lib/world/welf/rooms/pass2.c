// DATE        : Tue Mar  3 23:02:00 1998
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
  + "ir lifts your spirits up and makes you smile. Some distance i"
  + "n the east you can still spot the swantemple while in the wes"
  + "t a small bridge leads over a river towards the surrounding f"
  + "orest.");

  add_exit ("east", ROOM_PATH + "pass1.c");
  add_exit ("west", ROOM_PATH + "fbridge.c");

  add_sound ("You hear the sound of flowing water nearby in the west.");
  add_sound ("You can hear the splashing of water somewhere in west.");
  add_sound ("A plume of smoke rises to the skies from the temple in east.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
