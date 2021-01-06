// DATE        : Tue Oct 28 21:40:06 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Swan Temple");
  set_long (
    "You're standing before a huge wooden statue, sculpted to resemble a"
  + " swan spreading its wings. The marvellous woodwork and the sheer p"
  + "resence of some divine force and holiness make you feel so small "
  + "and puny. A fragrance of herbs and flowers fills your nostrils and"
  + " you feel a little high. In front of the statue is laid food and w"
  + "ine as a gift for the god of Nature, Shinael. The temple is lit by "
  + "a fire burning in a pit at the center of the room. The thick smo"
  + "ke rising from it escapes out to the skies from a hole in the h"
  + "igh domed ceiling of the temple. The ceiling is painted full of pi"
  + "ctures which tell the tale of elves in its whole colourful length"
  + " from the first steps of the elves to the recent days of the fores"
  + "t realms. Four doorways for the four seasons lead out of the templ"
  + "e to the city of Sol'daran.");

add_object ( ITEM_PATH + "board.c" );
  add_exit ("north", ROOM_PATH + "winter.c");
  add_exit ("east", ROOM_PATH + "spring.c");
  add_exit ("west", ROOM_PATH + "autumn.c");
  add_exit ("south", ROOM_PATH + "summer.c");

  set_outdoors (1);
  set_light (1);
  set_no_clean_up(1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
