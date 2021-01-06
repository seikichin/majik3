// DATE        : Tue Jan 20 05:29:47 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

#define room(x) message("3", x, environment(THIS), THIS)
#define pline(x) message("0", x, THIS)
#define ALL(x)   message("standard", x, ENV(THIS))

create_room ()
{
  set_short ("Flooded Dungeon");
  set_long (
    "You are in small dungeon type room. A ladder is attached to th"
  + "e south wall and leads to a trap door in the ceiling. Water h"
  + "as filled the room almost to the top. The walls are solid sto"
  + "ne and have turned to a dark green color from the prolonged e"
  + "xposure to the water. Also, there is some sort of seal on the"
  + " floor of the chamber.");

  add_exit ("up", ROOM_PATH + "tower2.c");

  add_item ("trap_door",
    "The trap_door can be reached by the ladder on the south wall. "
  + "However the water level is so high that if you know how to sw"
  + "im you could probably reach it from there.\n");

  add_item ("seal",
    "On the floor of th"
  + "e chamber is a strange type of door. It is circular in shape "
  + "and has a wheel attached to the top of it. It must be air tig"
  + "ht becuase no water seems to be escaping through it.\n");

  add_item ("water",
    "The wate"
  + "r is clean and clear, however it's also very cold.\n");

  add_sound ("The water is chilling you to the bone.");
  add_sound ("There is nothing but complete silence here.");

}

init()
{
  add_action("do_swim","swim");
}

do_swim(string what)
{
  int chance;
  chance = (45 + random(20));
  if(what == "here")
  {
    if(THIS->query_skill_chance("swimming") < chance)
     {
       pline("You swallow a mouth full of water and begin choking on it.\n");
       room(THIS->query_cap_name() + " chokes violently on some water.\n");
       THIS->add_hp(-20 - random(80));
       return 1;
     }
  }
}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

