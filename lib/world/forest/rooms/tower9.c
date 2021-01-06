// DATE        : Mon Nov 10 02:30:53 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Pinnacle of the Moon Tower");
  set_long (
    "You have entered the top room of the tower. The room is the sh"
  + "ape of a dome. The walls and ceiling are covered with elegant"
  + " designs. There is a hole in the very center of the ceiling o"
  + "pening to the sky above. There is a circular section, about t"
  + "wo meters in diameter and 1 meter raised above the ground, in"
  + " the center of the room.");

  add_exit ("out", ROOM_PATH + "tower8.c");

  add_item ("table section circular_section",
    "The circular section is made of the same stone as the tower.  "
  + "In fact, it seems like it was raised right out of the floor a"
  + "nd is part of the tower itself.  There is a small, circular i"
  + "ndentation in the center that may be used to hold some object"
  + ".\n");

  add_item ("walls wall ceiling designs",
    "The designs cover every inch of the walls and ceiling.  The"
  + "y seem to represent the sky at night.  There are many stars a"
  + "nd even some that look like distant planets.\n");

  add_item ("hole",
    "The hole in the "
  + "center of the ceiling is about 3 meters in diameter and allow"
  + "s you a limited view of the sky above.  It is directly over t"
  + "he circluar 'table' in the middle of the room.\n");

  set_outdoors (4);

  add_monster(MONSTER_PATH + "filonius.c");
  add_monster(MONSTER_PATH + "kane.c");

}

init()
{
   add_action("check_moon","check");
}

check_moon(string what)
{
  
  if(what != "moon")
  {return 0;}
  if(what == "moon")
  {
    if(ENV(THIS)->query_moon1_vertical_sector() > -1)
     {
      write(wrap("Afay hangs in the sky above.\n"));
      return 1;
     }
    else
     {
      write(wrap("Afay is not in the sky.\n"));
      return 1;
     }
  }
}


// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

