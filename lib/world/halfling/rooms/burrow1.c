// DATE        : Mon Nov  3 02:20:09 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Madam Siline's Burrow");
  set_long (
    "This is a burrow like most of the others in the Shire. It is c"
  + "ut right out of the hill and the walls, ceiling and floor are"
  + " dirt. There is a bed, a small cooking area and a window. Off"
  + " to the side is a stand with a painting on it.");

  add_exit ("east", ROOM_PATH + "road1.c");
 
  set_outdoors(1);

  add_item ("paintings stand",
    "There is a painting on stand with a few paints and brushes nex"
  + "t to it. The painting is of a rolling, grassy plain much like"
  + " the plains surrounding the Shire. The artist is very talente"
  + "d.\n");

  add_item ("bed",
    "The bed is raised about 1 foot off of the floor. There is "
  + "a straw mattress and pillow.\n");

  add_item ("window",
    "The window is a small circular o"
  + "ne, standard for the Shire. Outside you see mostly rolling pl"
  + "ains, but a bit off in the distance is a small lake.\n");

  add_object (MONSTER_PATH + "siline.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
