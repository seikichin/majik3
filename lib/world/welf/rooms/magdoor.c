// DATE        : Sun Feb 15 18:25:58 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the towerdoor");
  set_long (
    "You're standing up in the ancient oak on a small wooden platfo"
  + "rm. A strange tower rises in front of you, as twisted as the "
  + "oak it's resting on. Just like the other elven abodes this on"
  + "e seems to be one with the tree. However the tower radiates p"
  + "ower you haven't felt around the other buildings in here and "
  + "it makes your neckhair stand. A big sign has been nailed on t"
  + "he tower's door. Stairs spiral down around the runecovered oa"
  + "ktrunk.");

  add_exit ("down", ROOM_PATH + "magoak.c");
  add_exit ("east", ROOM_PATH + "magshop.c");

  add_item ("oak trunk oaktrunk",
    "Carved full of intricate runes the trunk seems to glimmer with"
  + " a soft silvery light. Perhaps the runes are for protection, "
  + "or perhaps they are the reason behind the oak's unbelievable "
  + "age.\n");

  add_item ("sign",
    "\n     ...      *   *            *                *\n   ::"
  + ": ::  *           *            *       *\n :::           *    "
  + "       *                    *\n::::   Astron Feymoon's shoppe "
  + "of majikal\n:::       curiosities and literature          *\n::"
  + ":: 'May the triad of moons light your way'     *\n :::       *"
  + "            *          *\n   ::: ..     *      *           *  "
  + "          *\n     :::     *           *             *\n");

  add_sound ("There's an octarine flash on the highest windows of the tower.");
  add_sound ("You think the tower is humming softly.");
  add_sound ("The runes carved on the trunk glimmer with a soft silvery light.");
  add_sound ("A raven flies into the tower through the highest window.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
