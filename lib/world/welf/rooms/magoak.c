// DATE        : Sun Feb 15 18:34:59 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Under a strange twisted oak");
  set_long (
    "You're standing under a huge and twisted oak. By the looks of "
  + "it, it must be ancient. Its trunk is carved full of intricate"
  + " runes that glimmer softly as you look at them. As you look u"
  + "pwards you notice that a strange tower has been built on the "
  + "treetop, as twisted as the tree itself. Slender stairs spiral"
  + " up to the tower's door and a path leads west where it joins "
  + "Falan's way.");

  add_exit ("up", ROOM_PATH + "magdoor.c");
  add_exit ("west", ROOM_PATH + "falan1.c");

  add_item ("tower",
    "Twisted and as ancient as the tree it is built on, the tower l"
  + "ooms high above you. An occasional flash in the windows and t"
  + "he scent of sulphur make you think about magicians.\n");

  add_item ("oak trunk oaktrunk runes",
    "The trunk"
  + " is carved full of intricate runes that glow with a silvery l"
  + "ight. You can't be sure what they stand for, but you guess th"
  + "ey are for protection.\n");

  add_sound ("A raven flies out of the tower above you.");
  add_sound ("There's an octarine flash in the tower windows.");
  add_sound ("The runes on the oaktrunk seem to glow softly with a silvery light.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
