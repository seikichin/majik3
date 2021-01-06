// DATE        : Mon Nov 10 02:12:12 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

int m = 1;
int s = 1;

create_room ()
{
  set_short ("Entry Hall");
  set_long (
    "This is the entry hall of the great stone tower. The walls are"
  + " adorned with paintings, statues and ornaments of elven make."
  + " There are tables on either side of you, each next to an arch"
  + "way carved out of the stone wall. The hall also continues for"
  + "ward twords a stairway. The doorway to enter the tower is beh"
  + "ind you. There are two torches attached to the walls on eithe"
  + "r side of you.");

  add_exit ("west", ROOM_PATH + "tower2.c");
  add_exit ("north", ROOM_PATH + "tower4.c");
  add_exit ("east", ROOM_PATH + "tower3.c");
  add_door ("south", ROOM_PATH + "mist1", "door", "wooden", 0, 0, 0);  

  add_item ("marble_table",
    "The table is of very fine make and doesn't have a single scrat"
  + "ch or mark on it.  On the underside of it you find a carving "
  + "of a half moon.  As you examine the carving you notice that t"
  + "he outer rim of it is cut deep in the marble.  With a little "
  + "prying, it may come loose.\n");

  add_item ("table tables",
    "The two tables are exactly the sam"
  + "e save the material they are made of.  The one on your right "
  + "is marble, while the other is made of stone.\n");

  add_item ("stairway stair stairs",
    "You can see the "
  + "beginnigs of a stairway which rises up into the tower.\n");

  add_item ("stone_table",
    "The ta"
  + "ble is made of solid stone and is in perfect condition.  On t"
  + "he underside of it you find a carving the moon in the three-q"
  + "uarter state.    You look closely at the picture and notice t"
  + "hat the outer rim of it has been cut very deep into the stone"
  + ".  With some prying it may come loose.\n");

  add_item ("torches torch",
    "The to"
  + "ches are in metal holsters attached to the walls.\n");

  set_light (1);

}

init_room()
{
  add_action("do_pry","pry");
}

do_pry(string what)
{
    
  if(!what)
  {return 0;}
  
  if(what == "carving from marble table" ||  what == "picture from marble table")
  {
    if(!m)
    {
      write("The carving has already been taken.\n");
      return 1;
    } 
    else
    {  
       write("You dig your fingers under and around the carving and, with"+
       " alot of work and a few cuts on your fingers, you eventually "+ 
       "pry it loose.\n");
       clone_object(ITEM_PATH + "marblefrag.c")->move(THIS);
       message("standard", THIS->query_cap_name() + " pries something"+
       " loose from the marble table.\n", ENV(THIS), THIS);
       m = 0;
      return 1;
    }
  }
  if(what == "carving from stone table" || what == "picture from stonetable") 
  {
    if(!s)
    {
      write("The carving has already been taken.\n");
      return 1;
    }
    else 
    {
      write("You dig your fingers under and around the carving and finally"+
      " work it loose from the stone table.\n");
      clone_object(ITEM_PATH + "stonefrag.c")->move(THIS);
      message("standard", THIS->query_cap_name() + " coaxes something"+
      " loose from the stone table\n", ENV(THIS), THIS);
      s = 0;
      return 1;
    }
  }
  write("Pry <what> from <which> table?\n");
   return 1;
}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

