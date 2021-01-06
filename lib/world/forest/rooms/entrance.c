// DATE        : Thu Nov 13 11:02:35 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Enterance to the Dark Forest");
  set_long (
    "You stand before a beautiful, green forest. The forest if very"
  + " dense and you cannot get a clear view of the inside from her"
  + "e. The trees are tall and forboding. Upon closer inspection, "
  + "you notice a faint path before you.");

  add_exit ("path", ROOM_PATH + "oforest1.c");
  add_exit ("out", "/world/y89x33.c");

  add_item ("forest tree trees woods",
    "The forest is full of tall maples which form a canopy that it "
  + "seems even the sunlight can't penetrate.\n");

  add_item ("path",
    "The path is only sli"
  + "ghtly visible among the overgrown brush.  It looks like it ha"
  + "s not been used in years.\n");

  add_sound ("Feint cries of someone or something in great pain can be heard comming from within the forest. ");
  add_sound ("A chill wind eminates from the direction of the forest. ");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

