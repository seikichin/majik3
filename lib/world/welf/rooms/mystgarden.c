// DATE        : Thu Feb 26 14:47:03 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Blooming garden");
  set_long (
    "Myriad flowers of almost every possible shade bloom in this sy"
  + "lvan garden. A small fountain gushes from a rock formation su"
  + "rrounded by thousands of small red flowers and streaks of wat"
  + "er pour down from the sides of the rock on the flowers. A lar"
  + "ge tree casts its calming shadow over most of the garden. Amo"
  + "ng the bushy leaves of the tree you can spot a small treehous"
  + "e. Steep flower covered stairs lead up to its doors and a pat"
  + "h leads west where it joins Morninglane.");

  add_exit ("west", ROOM_PATH + "mlane2.c");
  add_exit ("up", ROOM_PATH + "mysthouse.c");

  add_item ("treehouse",
    "The flowercovered house has a somewhat mystical feeling in it "
  + "and you feel curious to find out who lives here.\n");

  add_sound ("The strong scent of the flowers makes you sneeze.");
  add_sound ("You think you heard someone playing harp.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
