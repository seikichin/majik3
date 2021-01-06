// DATE        : Wed Feb 18 10:49:30 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Feymoon's magic shop");
  set_long (
    "You stand in a gloomy round room. Shelves full of spell compon"
  + "ents and tomes line the walls and beautiful tapestries hang a"
  + "bove them. The floor is covered with a beautifully embroidere"
  + "d carpet. There's a rune covered desk at the back of the room"
  + " and on it rests a small multicolored crystal that glows inte"
  + "nsively illuminating the whole room. A dimly glowing note flo"
  + "ats in the air behind the desk. Behind the desk stairs lead t"
  + "o an upper level of the tower.");

  add_exit ("up", ROOM_PATH + "magstudy.c");
  add_exit ("west", ROOM_PATH + "magdoor.c");

  add_item ("carpet",
    "It must held some power as well. It has been emroidered with r"
  + "unes and magical symbols that make you nervous when you step "
  + "on them, who knows what the carpet has been used for.\n");

  add_item ("crystal",
    "Lumines"
  + "cent multifasceted stone that shimmers brightly enought to il"
  + "luminate the whole shop. Its colors seem to shift ranging fro"
  + "m deep blue to brilliant red and pure white.\n");

  add_sound ("The crystal on the desk flares brightly.");
  add_sound ("Some soft chanting comes from upstairs.");
  add_sound ("The exotic scent of various spell components mixed with the forest air makes your nose itch.");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
