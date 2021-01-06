// DATE        : Mon Nov 10 01:46:30 1997
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

  add_exit ("down", ROOM_PATH + "bridge31.c");

  add_item ("window",
    "You peer out one of the windows and get a bird's eye view of t"
  + "he action below.  There are some elves on the ground fighting"
  + " what looks like goblins.  You see an elf get decapitated as "
  + "a goblin slashes through his neck with a bloodstained longswo"
  + "rd.  However, the elves have an advantage from the balcony be"
  + "low you as they send volleys of arrows at unsuspecting goblin"
  + "s.\n");

  add_item ("mugs mug",
    "The mugs are made of stone and are empty.\n");

  add_item ("table",
    "The table is sur"
  + "rounded by a few chairs.  There are some mugs and half eaten "
  + "rations strewn about the surface.\n");

  add_item ("chairs chair",
    "The chairs are wooden and w"
  + "ell worn.  You notice some blood on one of them.\n");

  add_item ("hole",
    "The hole is "
  + "cut right into the floor of the treehouse.  It is the only ex"
  + "it from the room.\n");

  add_item ("rations food",
    "There are some rations on the table which h"
  + "ave already been eaten off of.  They look rather old and stal"
  + "e\n");

  add_sound ("A strong wind blows through the treehouse. ");
  add_sound ("The sounds of battle, metal clashing against metal and agonizing death cries, come from the forest floor below. ");

  set_outdoors (1);

  add_monster(MONSTER_PATH + "glandil.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

