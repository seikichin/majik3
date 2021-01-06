// DATE        : Mon Nov 10 02:03:14 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Treehouse");
  set_long (
    "You are in a treehouse perched high in the tree. It is a one r"
  + "oom structure made completely of wood. There are four windows"
  + " on each side, which give a good view of the surrounding area"
  + ". In the middle of the room is a table with a few chairs arou"
  + "nd it. On one side of the rooms is a hole about 1 meter wide."
  + " The rope ladder is attached here and you can climb down to t"
  + "he balcony below. The room is small and cramped, yet it provi"
  + "des more space than the balcony underneath.");

  add_exit ("down", ROOM_PATH + "bridge12.c");

  add_item ("window",
    "You peer out one of the windows and get a bird's eye view of t"
  + "he action below.  There are a bunch of goblins setting the fo"
  + "rest on fire!  They have already got the blaze well underway "
  + "and it is quickly approaching the tree that this place is bui"
  + "lt in.\n");

  add_item ("table",
    "The table is surrounded by a few chairs.  The surface "
  + "of the table is completly empty.\n");

  add_item ("chairs chair",
    "The chairs are wooden and we"
  + "ll worn.  You notice some blood on one of them.\n");

  add_item ("hole",
    "The hole is c"
  + "ut right into the floor of the treehouse.  It is the only exi"
  + "t from the room.\n");

  add_sound ("A strong wind blows through the treehouse.");
  add_sound ("Thick black smoke rises up from the forest below.");
  add_sound ("The sounds of battle, metal clashing against metal and agonizing death cries, come from the forest floor below.");

  set_outdoors (1);

  add_monster(MONSTER_PATH + "porthios.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

