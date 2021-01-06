// DATE        : Thu Feb 12 19:49:27 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The House of Herbs");
  set_long (
    "This place must be among the most curious ones you've ever vis"
  + "ited. The dimly lit room is full of spices, herbs and flowers"
  + ". The smell is more than slightly intoxiating and you are abo"
  + "ut to enter a state of euphoria. Small pots and jars fill the"
  + " shelves and tables and here and there are scattered scrolls "
  + "and recipes. A small chandelabra gives its flickering light t"
  + "o the room managing only to make the shadows deeper and gloom"
  + "ier. You're so deeply in your thoughts that you bump into a t"
  + "reetrunk in the middle of the room. The house has been built "
  + "around it. There's a note nailed to the tree.");

  add_exit ("north", ROOM_PATH + "herbarope.c");
  add_exit ("east", ROOM_PATH + "herbadoor.c");

  add_item ("note poster",
    " \n===========\n| WANTED  |  The poster says: Tom Timbletoe, the"
  + " hobbit\n|  ,;;:.  |  WANTED!!! For stealing my favourite pipe"
  + "!\n| 8(o o)8 |  Will reward the one who catches this nuisance\n"
  + "|   |U|   |  and returns my belowed pipe.\n|   (O)   |        "
  + "  ***\n:    `    :  Galena Erbos, the herbalist\n===========\n");

  add_sound ("The scent of herbs makes you feel high.");
  add_sound ("You almost trip on a jar full of some sticky liquid.");
  add_sound ("You can hear the wind blowing in the trees outside.");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
