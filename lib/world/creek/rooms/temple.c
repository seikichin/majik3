// DATE        : Sun Nov  2 23:39:19 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Temple of Truth");
  set_long (
    "Dazzled by the light of Goodness you stagger around the great "
  + "domed hall. Shining crystals float near the domed ceiling and"
  + " provide very bright light to the whole great hall. The whole"
  + " hall radiates such pure goodness that you want to pray and give"
  + " away the evil thoughts forever. On the walls are placed pain"
  + "tings and icons of good deities. Arched doorways lead to all "
  + "four directions.");

  add_exit ("south", ROOM_PATH + "prayer.c");
  add_exit ("north", ROOM_PATH + "cleric.c");
  add_exit ("east", ROOM_PATH + "templesq.c");
  add_exit ("west", ROOM_PATH + "gifts.c");

  add_item ("crystals ceiling dome",
    "The crystals glow with a light almost blindingly bright. They "
  + "hover near the dome ceiling of the hall. The ceiling itself i"
  + "s painted full of ornaments with rich golden colors.\n");

  add_item ("archways archway",
    "All deco"
  + "rated with the golden colours of the sun and the silvery shin"
  + "e of\nAfay. An inscription over the one leading out says: 'In "
  + "Majik We Trust'\n");

  add_item ("deities icons paintings",
    "Icons of all the good gods are placed on the "
  + "walls, they all glow softly.\nThe scrutinizing eyes of the god"
  + "s make you feel nervous.\n");

  add_object (ITEM_PATH + "board");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
