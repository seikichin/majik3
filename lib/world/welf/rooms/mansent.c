// DATE        : Sun Feb 22 15:09:38 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Entrance hall");
  set_long (
    "You stand in an impressive entrance hall of the treemansion. T"
  + "apestries describing the history of Sol'daran have been place"
  + "d on the walls and above them has been hung the coat of arms "
  + "of the family and the seal of clan Velendur. The northern wal"
  + "l is dominated by a long bench and a large mirror.");

  add_exit ("south", ROOM_PATH + "manslib.c");
  add_exit ("east", ROOM_PATH + "mansfront.c");
  add_exit ("west", ROOM_PATH + "mansmain.c");

  add_item ("seal coat_of_arms coat arms",
    "The coat of arms has been painted half gold and half green. Th"
  + "e green side has a golden tree pictured on it and the gold on"
  + "e a green leaf and an apple. The seal above the coat of arms "
  + "has the word ^lalande Velendur ^l0 written on it.\n");

  add_item ("tapestry tapestries",
    "Intricately"
  + " woven tapestries decorate the walls of this room. They all s"
  + "eem to tell about the history of the city of tanir, Sol'daran"
  + ".\n");

}

init_room()
{
  add_action ("do_look", "look");
  add_action ("do_l","l");
}

do_look(str)
{

 if (!str || str != "mirror")
 { return 0; }

write ("You see your own reflection in the mirror and stop to"
      +" admire it for a while.\n"+ THIS->long() );
 message ("3", THIS->query_cap_name() +
 " stops to admire the reflection in the mirror.\n",
 ENV(THIS), THIS);
 return 1;
}
do_l(str)
{

 if (!str || str != "mirror")
 { return 0; }

write ("You see your own reflection in the mirror and stop to"
      +" admire it for a while.\n"+ THIS->long() );
 message ("3", THIS->query_cap_name() +
 " stops to admire the reflection in the mirror.\n",
 ENV(THIS), THIS);
 return 1;
}
