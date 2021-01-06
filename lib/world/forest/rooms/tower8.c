// DATE        : Mon Nov 10 02:30:02 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Staircase");
  set_long (
    "The staircase is circular and is so wide it must take up the w"
  + "idth of the tower. You have finally reached the top of the st"
  + "airs. Before you stands a set of double wooden doors. On the "
  + "door is a large carving of four sections of quarter moon. The"
  + "y are pieced together to form a full moon and they are all gl"
  + "owing very brightly.");

  add_exit ("down", ROOM_PATH + "tower7.c");

  add_item ("doors double_doors double_wooden_doors",
    "The carving covers almost the entire double door set.  Below t"
  + "he full moon, there is an inscription.  It is very small and "
  + "you have to squint to read it.\n");

  add_item ("inscription read_inscription",
    "^lalande The inscription, written in alande, reads:\n\nAs the "
  + "warrior stepped from the darkness, he brought something with "
  + "him...he brought the light of darkness...and so he passed thr"
  + "ough the portal unschathed.\n");
}

init_room()
{
  add_action("do_touch","touch");
}

do_touch(string what)
{
  int i;
  object *foo;

  if(what == "moon shield to door" && present("moon shield",THIS))
  {
   write(wrap("You gently touch the Moon Shield to the carving on the wooden door and "+
              "you are suddenly sucked into the door against your will! Before you have "+
              "a chance to react, you arrive in the next room.\n"));
   foo = all_inventory(ENV(THIS));
   for(i = 0;i<sizeof(foo);i++)
    {
      if(living(foo[i]) && !foo[i]->query_npc())
      {
      foo[i]->move_player(ROOM_PATH + "tower9.c");
      }
    }

   return 1;
  }

  else
  {return 0;}
}



// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

