// DATE        : Mon Nov  3 21:37:20 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Robber's Den");
  set_long (
    "Of all the taverns you have seen this is the most suspicious a"
  + "nd shady. All the customers look like criminals and murderers"
  + ", but they all are having fun and nobody's killing others. It"
  + " doesn't take much to figure out that it is here where the sc"
  + "um of Silvercreek gather and plot their crimes. A desk for or"
  + "dering drinks and food is at the back of the room. The room i"
  + "s lit with torches attached to the stone walls. A heavy curta"
  + "in of pipeweed smoke fills the whole room.");

  add_exit ("west", ROOM_PATH + "bazaar2.c");
  add_exit ("north", ROOM_PATH + "den2.c");

  add_object (MONSTER_PATH + "drunk");
  add_object (MONSTER_PATH + "friedrich");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
