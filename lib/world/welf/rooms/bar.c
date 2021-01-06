// DATE        : Thu Feb  5 17:24:19 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the back of the mainroom");
  set_long (
    "You walk to the long desk at the back of the main room. Stools"
  + " have been placed in front of it for people who like to drink"
  + " and order new drinks at the same time. A thick haze floats a"
  + "bove the room in here. A bell has been placed on the table, s"
  + "o that you can call for the bar keeper. A list of drinks and "
  + "food has been hung on the wall. You can see the entrance to t"
  + "he tavern in the west.");

  add_exit ("west", ROOM_PATH + "sunflower.c");

  add_item ("list wall",
    "+--------------+----+-------------------+----+\n|Foods         "
  + "| gp |             Drinks| gp |\n+--------------+----+--------"
  + "-----------+----+\n|Cooked rabbit |    | Elven plumwine    |  "
  + "  |\n|Mutton        |    | Dark dwarven ale  |    |\n|Stale bre"
  + "ad   |    | Halfling beer     |    |\n|Elven waybread|    | Th"
  + "ari whiskey     |    |\n|Vegetable dish|    | Faun's fall drin"
  + "k |    |\n|Sunflower soup|    | Sunflower special |    |\n+----"
  + "----------+----+-------------------+----+\n");

  add_item ("bell",
    "A small silvery bel"
  + "l, most propably for calling the barkeeper. A symbol of foami"
  + "ng mug has been etched on its side.\n");

  add_sound ("The haze is like syrup here.");
  add_sound ("A laughter erupts in a table near you.");
  add_sound ("A halfling customer hops on one of the tables and starts to sing something stupid.");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
