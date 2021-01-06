// DATE        : Mon Jan 19 01:16:18 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("South side of the mill");
  set_long (
    "You are standing next to the southern wall of the mill. The wa"
  + "terwheel's huge size makes you feel tiny. The river comes aro"
  + "und from the east side of the building and flows rapidly by y"
  + "ou, spinning the wheel at a great speed. ");

  add_exit ("northwest", ROOM_PATH + "mill1.c");

  add_item ("wheel waterwheel",
    "The waterwheel is attached to wall of the mill and the bottom "
  + "quarter of it is below the water level of the river. The pace"
  + " of the river causes it to spin rapidly around.\n");

  add_item ("river",
    "The river is "
  + "flowing quite fast and sprays you with some drops of water ev"
  + "ery few seconds.\n");

  add_sound ("The waterwheel spins so fast you think it may break off of the wall and run you down.");
  add_sound ("The waterwheel is quite noisy as it spins unceasingly.");
  add_sound ("A mist sprays up from the river into your face.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
