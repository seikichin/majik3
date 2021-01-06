// DATE        : Fri Feb 13 15:30:33 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Narrow ropebridge over the mainstreet");
  set_long (
    "You're walking on a narrow ropebridge that sways dangerously u"
  + "nder your feet. It seems to be sturdy enough to hold your wei"
  + "ght, but the creaking noises it makes now and then make you f"
  + "eel nervous. Below the ropebridge you can see the mainstreet "
  + "of Sol'daran that leads from the gates in south to the swante"
  + "mple in north. On the east side of the bridge there's a balco"
  + "ny of the local tavern and on the west side there's a strange"
  + " moss covered treehouse.");

  add_exit ("east", ROOM_PATH + "balcony.c");
  add_exit ("west", ROOM_PATH + "herbadoor.c");

  add_sound ("The way the bridge sways under your steps makes you nervous.");
  add_sound ("The bridge creaks dangerously.");
  add_sound ("You can hear the bustle below you where people hurry on their errands.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
