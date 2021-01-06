// DATE        : Sat Nov  1 21:40:43 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("A small hut");
  set_long (
    "This hut is very modest. It is a one room place with a small t"
  + "able in the middle and a bed off to the side. There are two c"
  + "ircular windows that offer you a view of Fisherman's Lane out"
  + "side. Plus, there is a small fireplace here with some cookwar"
  + "e on the floor next to it.");

  add_exit ("west", ROOM_PATH + "road1.c");

  set_outdoors(1);

  add_item ("bed",
    "The bed is about 4 feet from head to toe. It is built on a woo"
  + "den support structure and has a mattress that must be filled "
  + "with straw or something. It looks rather comfortable.\n");

  add_item ("window",
    "Outside"
  + " you see Fisherman's Lane. A dirt road that goes off in the n"
  + "orth and south directions.\n");

  add_item ("fireplace fire",
    "There is a stone fireplace here th"
  + "at is currently lit. The smoke flows up and out the chimmney."
  + "\n");

  add_item ("cookware",
    "You see a few pots and pans here on the ground. One is over "
  + "the fire and has some kind of soup cooking in it.\n");

  add_sound ("A sweet smell comes from the the pot over the fireplace.");
  add_sound ("The fire crackles a bit.");
  add_sound ("Some young halflings run by the window, laughing.");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
