// DATE        : Fri Feb 13 15:15:07 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Small cabin");
  set_long (
    "There isn't much furniture in here, only a sturdy and long woo"
  + "den table, a long bench on both sides of it and a small uncom"
  + "fortable looking bed placed near the fireplace in south. A bl"
  + "azing fire has been built in the fireplace and a deep red glo"
  + "w illuminates the small room. An oil lantern has been hung on"
  + " the beam that supports the earthen roof of the cabin.");


  add_item ("fireplace fire",
    "A blazing hearth fills the room with comfortable warmth and il"
  + "luminates the room in a deep red glow.\n");

  add_sound ("It's in fact quite cozy and warm in here.");
  add_sound ("It smells like cooked rabbit in here.");

  add_door ("north", ROOM_PATH + "athunter.c","door","wooden", ITEM_PATH +
  "hunterkey.c",30,1);
  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
