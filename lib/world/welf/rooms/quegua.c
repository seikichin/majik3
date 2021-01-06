// DATE        : Fri Mar  6 23:12:11 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Guardroom");
  set_long (
    "This is the guardroom of Que-Moran. There aren't much furnitur"
  + "e in here, just an old table and few chairs around it. One co"
  + "rner of the room has been cleared so that the guards may prac"
  + "tice their swordcraft. Several weapons and shields have been "
  + "hung on the walls to add some decoration to the room.");

  add_exit ("west", ROOM_PATH + "questa2.c");
  add_exit ("south", ROOM_PATH + "quegq.c");

  add_item ("walls weapons shields",
    "Oh they sure do look like fine pieces of weaponry, but as you "
  + "take a closer look you notice that they are made just for the"
  + " decoration. The edges of the swords are dull and the shields"
  + " are probably made of tin.\n");

  add_item ("table chairs",
    "An old wooden table and four chair"
  + "s around it apparently meant for playing poker.\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
