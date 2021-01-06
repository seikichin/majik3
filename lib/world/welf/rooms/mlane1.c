// DATE        : Tue Feb  3 19:00:36 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Morninglane");
  set_long (
    "You're walking on Morninglane which leads south from the fount"
  + "ain just a short distance in north. Though this is the part o"
  + "f city where most of the common tanir folk live it easily mat"
  + "ches the beautiness of the nobility district of Endalen. The "
  + "treehouses that rest on the treetops all around the area are "
  + "not as luxurious as in Endalen, but their simple and somehow "
  + "rustic outlook leave you awestruck nonetheless. The street le"
  + "ads north and south. A well tended path leads west to one of "
  + "the trees holding the houses.");

  add_exit ("south", ROOM_PATH + "mlane2.c");
  add_exit ("north", ROOM_PATH + "square.c");
  add_exit ("west", ROOM_PATH + "oakunder.c");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
