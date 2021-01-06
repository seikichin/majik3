// DATE        : Thu Feb 26 18:32:11 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("In front of a treehouse");
  set_long (
    "You're standing on a small wooden platform that's built on the"
  + " sturdiest limbs of a large pinetree. A peculiar octagon shap"
  + "ed treehouse has been built around its great trunk. A couple "
  + "of lanterns hang from holders on the both sides of its frontd"
  + "oor. Below, you can see a blooming sylvan garden and Morningl"
  + "ane just a short distance in west. Steep and narrow stairs le"
  + "ad down to the garden.");

  add_exit ("down", ROOM_PATH + "mystgarden.c");
  add_exit ("east", ROOM_PATH + "mystroom.c");

  add_item ("treehouse",
    "It has a strong mystical feeling in it. You're not sure what t"
  + "o think of it, but it doesn't feel evil in anyway. It's built"
  + " of some dark wood and is covered with leaves and flowers, da"
  + "rk purple in color.\n");

  add_item ("garden",
    "Full of flowers of all sorts the garden i"
  + "s in full bloom.\n");

  add_item ("lanterns lamps",
    "They are firmly attached to the holders and "
  + "cannot be taken if you were thinking of stealing them, bastar"
  + "d.\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
