// DATE        : Mon Nov 10 01:13:08 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Inside the Mist");
  set_long (
    "You are surrounded by a green swirling mist. There are no plan"
  + "ts in sight and the ground is covered by dirt only. Before yo"
  + "u looms a tall, stone tower. It is an amazing sight. The ston"
  + "ework is beautiful and crafted to perfection.");

  add_exit ("mist", ROOM_PATH + "iforest5.c");
  add_door ("north", ROOM_PATH + "tower1", "door", "wooden", 0, 0, 0);  

  add_item ("door wooden door",
    "The door is approximately 2 meters high and is made of wood.  "
  + "There is a handle on the left side.  The only other noticable"
  + " object on it is a finely carved picture of a quarter moon.\n");

  add_item ("mist",
    "T"
  + "he mist swirls all around and has a feint green color to it. "
  + " It rises high to an infinite height, but you can still see t"
  + "he sky directly above you.  Walking throught the mist seems t"
  + "o be the only exit from here besides entering the tower.\n");

  add_item ("moon carving picture",
    "On t"
  + "he door is an intracatly carved depiction of a quarter moon. "
  + " However, upon close inspection, you notice a piece is missin"
  + "g in the center of the carving.\n");

  add_sound ("The mist slowly swirls about you. ");
  add_sound ("A hollow voice echos in your head: Enter the tower and save me from this horrible nightmare. ");
  add_sound ("Hideous laughter and screams of immense pain come from somewhere above you. ");

  set_outdoors (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

