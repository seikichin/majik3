// DATE        : Sun Nov  2 20:30:58 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marketplace, the fortune teller's booth");
  set_long (
    "The booth near you is popular, a queue has been made before it"
  + ". The great Madame Sofia has come all the way from Nanduath t"
  + "o tell of the future. Apparently she wasn't this popular ther"
  + "e. Sofia can tell you what happens the next day or the day af"
  + "ter that, but she also sells her tools, at sky high prices of"
  + " course. The market place continues to all four directions. I"
  + "n the north the Academy of Magic dominates the view. In the w"
  + "est there is another booth, as curious as this one. Some dist"
  + "ance in the east you can see the city gates.");

  add_exit ("south", ROOM_PATH + "marketp4.c");
  add_exit ("north", ROOM_PATH + "marketp11.c");
  add_exit ("east", ROOM_PATH + "marketp3.c");
  add_exit ("west", ROOM_PATH + "marketp5.c");

  add_object (MONSTER_PATH + "gypsy");
  add_object (MONSTER_PATH + "dog");
	
  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
