// DATE        : Wed Feb 18 11:00:18 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The study");
  set_long (
    "This rooms is apparently used as a study. A dusty table and a "
  + "comfortable looking chair have been placed in front of the wi"
  + "ndow on the north wall and beside the desk on the both sides "
  + "stand huge bookcases. The remaining wallspace has been used t"
  + "o hang several notes about magic and the tree moons and a sta"
  + "rmap. A dusty golden chandeliers lights the room dimly. Stair"
  + "s spiral down from here.");

  add_exit ("down", ROOM_PATH + "magshop.c");

  add_item ("notes starmap",
    "All neatly written with flowing elven script, but you can't st"
  + "ill make out what they are really about. A picture of the thr"
  + "ee moons and lots of symbols written on them dominates much o"
  + "f the wallspace and below it has been hung a starmap.\n");

  add_sound ("A raven flies into the study and lands on top of a bookcase.");
  add_sound ("You hear someone muttering downstairs.");
  add_sound ("A soft breeze blows in from the open window.");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
