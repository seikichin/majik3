// DATE        : Thu Feb 12 19:27:20 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("In front of a strange treehouse");
  set_long (
    "You're standing in front of a strange treehouse, if one can ca"
  + "ll it a house in the first place. It is by all means more lik"
  + "e a big chunk of moss and bushes that from some reason happen"
  + " to grow in the treetop of a tall pine. A curious looking sig"
  + "n has been hung above the door. Creaking stairs spiral down a"
  + "round the treetrunk and a narrow yet sturdy looking ropebridg"
  + "e leads east over the street to another treetop.");

  add_exit ("east", ROOM_PATH + "innrope.c");
  add_exit ("down", ROOM_PATH + "herbal.c");
  add_exit ("west", ROOM_PATH + "herbalist.c");

  add_item ("sign",
    " ,===================.\n |  _._  Herbs and   |\n | ;_,_: mushroo"
  + "ms   | \n |  ( )     ***      |\n | \"\"\"\"\" Galena Erbos| \n "
  + "`-----------------\n");

  add_item ("house moss bushes",
    "Whatever it is, it is built cleverly aroun"
  + "d the treetrunk and it has four walls and a roof. A strange s"
  + "cent drifts out from its open windows. The sign above the doo"
  + "r indicates the treehouse to be some sort of a herbshop.\n");

  add_sound ("A really strange scent drifts out from the treehouse.");
  add_sound ("Someone is giggling inside the treehouse.");
  add_sound ("A bird flies to rest on the chimney of the building and suddenly drops to the ground.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
