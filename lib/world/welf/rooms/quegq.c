// DATE        : Thu Mar  5 22:11:34 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Guards' quarters");
  set_long (
    "Here the guards of Que-Moran can meditate and reverie without "
  + "anyone disturbing them. The floor of this small room is cover"
  + "ed with a comfortable soft carpet and several mattresses lie "
  + "scattered around the room. The walls are covered with brightl"
  + "y colored tapestries and a large green glasswindow provides a"
  + "n alluring view over the sylvan realm in south.");

  add_exit ("north", ROOM_PATH + "quegua.c");

  add_item ("window",
    "The city and the forest around it offer you a breathtaking vie"
  + "w.\n");

  add_item ("tapestry tapestries",
    "These ones depict several elven heroes in their polished m"
  + "ithril platemails battling orcs and trolls during the great w"
  + "ar.\n");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
