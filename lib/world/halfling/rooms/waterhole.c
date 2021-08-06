// DATE        : Sat Nov  1 21:12:54 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The watering hole");
  set_long (
    "You come across a natural spring. The water is clear and clean"
  + ". The ground surrounding the hole is thick with green grass. "
  + "This place seems very peaceful and looks like a nice place to"
  + " relax and let the days go by.");

  add_exit ("south", ROOM_PATH + "road1.c");

  set_outdoors(4);

  add_item ("water wateringhole spring",
    "The water is crystal clear and appears very clean. It is teemi"
  + "ng with fish.\n");

  add_item ("grass ground",
    "The area around the hole is covered with thick "
  + "green grass.\n");

  add_sound ("A fish pops up out of the water and drops back in.");
  add_sound ("The grass sways in the breeze.");

  add_object (MONSTER_PATH + "younggirl.c");

}

init_room()
{
     add_action("do_drink","drink");
}
do_drink(string what)
{
  if(!what)
  {
    write("You take a long draught of water from the spring and feel much better.\n");
    message("standard", capitalize(THIS->query_name()) + " takes a drink from the "+
     "spring.\n",ENV(THIS),THIS);
    THIS->hydrate_me(500);
    return 1;
  }
  if(what == "spring")
  {
    write("You take a long draught of water from the spring and feel much better.\n");
    message("standard",capitalize(THIS->query_name())+" takes a drink from the "+
    "spring.\n",ENV(THIS),THIS);
    THIS->hydrate_me(500);
    return 1;
  }
  else
  {
     write("Usage: drink spring.\n");
     return 1;
  }
}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

