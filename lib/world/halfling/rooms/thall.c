// DATE        : Fri Dec  5 07:25:15 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Town Hall");
  set_long (
    "You are in the lobby of a very large hut. The room is spacious"
  + " and has a few pieces of funiture for you to sit and wait on."
  + " There is a couch and four or five chairs. Plus, there is a c"
  + "ounter at the far end of the room which must be the service d"
  + "esk. There is also a board nailed to the wall.");

  add_exit ("east", ROOM_PATH + "taxroom.c");
  add_exit ("south", ROOM_PATH + "road5.c");
  add_exit ("west", ROOM_PATH + "jailview.c");

  add_item ("couch",
    "The couch is blue velvet. It is designed to fit three halfling"
  + "s or two human sized people.\n");

  add_item ("board",
    "There is a post-it board on the "
  + "wall.\n");

  add_item ("counter",
    "The counter stands about two feet off the ground and is"
  + " made entirely of wood.\n");

  add_item ("chairs",
    "There are five chairs in the room. Fo"
  + "ur of them are halfling sized while one is larger, made for a"
  + " larger person.\n");

  set_outdoors (1);
  set_light (1);

  add_object (ITEM_PATH + "pboard.c");
  add_object (MONSTER_PATH + "corin.c");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
