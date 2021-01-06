// DATE        : Mon Nov  3 20:32:17 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A small library");
  set_long (
    "The room is quite small but it's full of scrolls, spell books "
  + "and other opuses about the arcane art. The bookshelves glow s"
  + "oftly with an unnatural blue light. Wards of protection have "
  + "been cast on the books and if someone is foolish enough to tr"
  + "y steal the opuses he'll know he has made a mistake soon. Doo"
  + "rs lead south and east.");

  add_exit ("east", ROOM_PATH + "hallway1.c");
  add_exit ("south", ROOM_PATH + "lab.c");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
