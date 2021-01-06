// DATE        : Sun Nov  2 20:29:49 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marketplace");
  set_long (
    "You're pushing your way through the heavily crowded market pla"
  + "ce of Silvercreek. The massive building of the Academy of Mag"
  + "ic is in the north, its doors just a short distance in the ea"
  + "st. A curious looking booth is in the south. Young spell stud"
  + "ents are amusing themselves with illusions nearby and trying "
  + "to earn few coins with their tricks.");

  add_exit ("south", ROOM_PATH + "marketp5.c");
  add_exit ("east", ROOM_PATH + "marketp11.c");
  add_exit ("west", ROOM_PATH + "marketp9.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
