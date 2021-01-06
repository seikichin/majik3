// DATE        : Sun Nov  2 22:38:50 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Grave street at a short alley");
  set_long (
    "You're walking along the Grave street. The street continues to"
  + " the north and south while a short alley leads west to a baza"
  + "ar. You hear some arguing and yelling from that direction. Yo"
  + "u see a chapel in the grave yard over the fence in east.");

  add_exit ("south", ROOM_PATH + "grave6.c");
  add_exit ("north", ROOM_PATH + "grave7.c");
  add_exit ("west", ROOM_PATH + "tobaz.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
