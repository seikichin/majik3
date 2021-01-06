// DATE        : Thu Feb 12 19:40:08 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Under a strange treehouse");
  set_long (
    "Sturdy wooden stairs spiral up to the tree where a strange bui"
  + "lding has been built. Smell of exotic herbs and flowers float"
  + "s down to greet you as you step on the first step of the stai"
  + "rs. The building itself is covered with bushes, moss and litt"
  + "le twigs. Smoke twirls up to the skies from a small hole in i"
  + "ts roof. You can still faintly hear the sound of people hurry"
  + "ing on the street east from here but the strange smell of flo"
  + "wers drags you to enter the building up in the tree.");

  add_exit ("east", ROOM_PATH + "street2.c");
  add_exit ("up", ROOM_PATH + "herbadoor.c");

  add_sound ("A curious smell drifts here from the treehouse above you.");
  add_sound ("The smoke rising from the treehouse suddenly turns green.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
