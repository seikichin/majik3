// DATE        : Tue Feb  3 20:28:05 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Totem of Autumn");
  set_long (
    "You wade through piles of brown, yellow and red leaves and bre"
  + "athe deeply the rich scent of autumn. This square seems to be"
  + " a paradise of colors. A totem painted in those same autumn c"
  + "olors resembling an elf riding a great eagle stands at the ce"
  + "nter of the square. A temple welcomes you to enter it in the "
  + "east and three leafcovered paths lead west, south and north.");

  add_exit ("west", ROOM_PATH + "pass1.c");
  add_exit ("south", ROOM_PATH + "corner4.c");
  add_exit ("north", ROOM_PATH + "corner1.c");
  add_exit ("east", ROOM_PATH + "temple.c");

  add_item ("temple swantemple",
    "The temple is made of grey stone and looks ancient. A feeling "
  + "of\nholiness and the presence of some deity surrounds the plac"
  + "e. Four\npillars support its heavy gothic stylished roof and o"
  + "n the each\nfour sides of the temple are carved intricate leaf"
  + " patterns. The\nrune of autumn has been carved above the door "
  + "on this side of the\nbuilding. You notice a thick plume of smo"
  + "ke rising from the temple.\n");

  add_item ("eagle totem kotka eagletotem",
    "  `\\           /' You duck when y"
  + "ou notice the mighty eagle swooping\n  '/\\   \\;/   /\\' towa"
  + "rd its prey, you! Phew, it was only the totem,\n  '//\\ (U'U) "
  + "/\\\\' but it sure looks so real. Elves regard the great\n  '/"
  + "//\\/`V'\\/\\\\\\  eagles as sacred animals, and use them as "
  + "air\n   '//(,.,.,)\\\\'  cavalry when they ride to war against"
  + " the orc scum.\n    '//\\,.,/\\\\'   You wonder what it would "
  + "feel like riding one of\n     ' /`;'\\ '    those eagles high "
  + "in the skies... must be great.\n     _/ /|\\ \\_\n        '''\n");

  add_sound ("You breathe in the rich scent of autumn.");
  add_sound ("A plume of smoke rises to the sky from the temple in east.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
