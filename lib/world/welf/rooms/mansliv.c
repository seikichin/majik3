// DATE        : Tue Feb 24 19:39:45 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Livingroom");
  set_long (
    "You stand in a homely and warm chamber. A small fireplace has "
  + "been built into the south wall and a fabulous crystal chandel"
  + "ier hangs from the ceiling. Luxurious chairs and a very comfo"
  + "rtable looking sofa have been placed around a round wooden ta"
  + "ble at the center of the floor.");

  add_exit ("west", ROOM_PATH + "mansbed2.c");
  add_exit ("north", ROOM_PATH + "mansmain.c");

  add_item ("table chairs chair sofa",
    "The table, chairs and sofa are all first class furniture. Eleg"
  + "ant and luxurious and coated with gold and silver they make y"
  + "ou feel like a noble.\n");

  add_item ("fireplace fire blaze",
    "The fireplace has been built of some gr"
  + "ey round stones the size of your fist. A blazing fire has bee"
  + "n built into it and a flickering red glow bathes the room in "
  + "a soothing way.\n");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
