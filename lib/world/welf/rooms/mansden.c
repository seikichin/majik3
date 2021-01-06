// DATE        : Thu Feb 26 12:38:58 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Den");
  set_long (
    "This chamber is relevantly decorated. A large writing desk cov"
  + "ered with parchments and maps has been placed near the window"
  + ". A comfortable looking sofa lies beside the east wall. A nea"
  + "t painting picturing a forest scene has been hung above it on"
  + " the wall. Bookcases full of books and opuses dominate the re"
  + "st of the walls.");

  add_exit ("east", ROOM_PATH + "mansmain.c");
  add_exit ("west", ROOM_PATH + "mansbed.c");

  add_item ("sofa",
    "It looks soft and comfortable, just the type of sofa you could"
  + " spend you day resting on reading a good book.\n");

  add_item ("bookcase bookcases books",
    "The shelves ar"
  + "e full of books and opuses, all neatly placed in alphabetical"
  + " order. Most of them are about the history of the realms and "
  + "Sol'daran, but several books seem to be tales written by Bele"
  + "mar, the Chronicler.\n");

  add_item ("desk parchments maps",
    "Most of the maps on the table seem to be"
  + " out of date and look worthless. The parchments seem to be no"
  + "tes made by some chronicler for his tales.\n");

  add_item ("painting",
    "The artist must ha"
  + "ve been a master of some sort. The scene in the painting look"
  + "s incredibly real and you feel like you were in the forest yo"
  + "urself.\n");

  add_item ("window",
    "The view is quite spectacular. The streets are full o"
  + "f life and hustle and the animals scurry around the surroundi"
  + "ng forest on their own routines.\n");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
