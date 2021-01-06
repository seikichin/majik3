// DATE        : Sun Nov  2 00:01:17 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the crossing of Gate street and Southern Temple street");
  set_long (
    "You've standing at the corner where the two streets join. The "
  + "gate street stretches to the north and the temple street to t"
  + "he west. A book shop is in the east. Above the door is hangin"
  + "g a curious looking sign. A banging of hammer on anvil echoes"
  + " from southeast where the smithy is located. A plume of smoke"
  + " can be seen rising that way.");

  add_exit ("north", ROOM_PATH + "gate2.c");
  add_exit ("east", ROOM_PATH + "books.c");
  add_exit ("west", ROOM_PATH + "stemple4.c");

  add_item ("sign",
    "A rather curious looking sign is hanging above the shopdoor..."
  + "\n \n    ,=========.\n    | Ye Olde |\n    | Bookke  |\n    | Shop"
  + "pe  |\n    | * * * * |\n    |  * * *  |\n    `---------'\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
