// DATE        : Tue Mar  3 23:36:47 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the doors of Que-Moran");
  set_long (
    "You're standing before the doors of Que-Moran, the palace of t"
  + "he lord and lady of Sol'daran. The palace is built on the tre"
  + "etop of a great tree that towers about 200 feet in height and"
  + " several tens in diameter. The palace itself is as great and "
  + "wonderful sight as the tree. Its marvellous woodwork and aeri"
  + "ous design label it as an architectural miracle. Huge stairs "
  + "spiral around the tree towards the ground far below you.");

  add_exit ("down", ROOM_PATH + "walk2.c");
  add_exit ("east", ROOM_PATH + "quentran.c");

  add_sound ("The height makes you feel dizzy.");
  add_sound ("Wind tugs at your clothes.");
  add_sound ("The view is marvellous here.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
