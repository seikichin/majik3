// DATE        : Sun Feb  8 19:30:21 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Falan's way");
  set_long (
    "The street ends here before the doors of a beautiful temple. W"
  + "hite marble pillars, colorful windows and a shiny golden dome"
  + " make Tirilith, one of the most important buildings in Sol'da"
  + "ran, easily recognizable. The doors of the house of healing s"
  + "tand always open for those who walk the path of light and lad"
  + "y T'ianna is well known as a proficient healer. The street le"
  + "ads west and the temple is in east.");

  add_exit ("east", ROOM_PATH + "tirithil.c");
  add_exit ("west", ROOM_PATH + "falan3.c");

  add_item ("temple pillars windows tirilith",
    "The temple of healing or Tirilith as the elves know it is a be"
  + "autiful sight. Light shines on its polished golden dome and i"
  + "ts white stonework glows softly by its own inner power. A sof"
  + "t murmur of praying echoes from inside.\n");

  add_sound ("Soft chanting echoes from inside the temple.");
  add_sound ("You can hear murmuring of a prayer in the temple.");
  add_sound ("Beautiful singing comes from the temple in east.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
