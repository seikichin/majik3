// DATE        : Tue Feb  3 19:19:03 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Weeping willow");
  set_long (
    "You're standing before a beautiful lonely tree. The tree is ca"
  + "lled weeping willow and you understand why as you look at it."
  + " Silvery droplets shimmer on its small leaves and drop down t"
  + "o a memorial stone under it like tears shed for the one most "
  + "loved and longed. A deep feeling of serenity fills you and tu"
  + "rn away from the grave and the willow not wanting to disturb "
  + "the place. A faint path leads west to the cemetary.");

  add_exit ("west", ROOM_PATH + "sylcem4.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
