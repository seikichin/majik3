// DATE        : Sun Nov  2 20:30:25 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Marketplace, the southwest corner");
  set_long (
    "You're now standing at the southwest corner of the Market plac"
  + "e. The Market place stretches to the east and north. The mass"
  + "ive building of the Academy of Magic dominates the view in no"
  + "rth, its towers scraping the sky. A door leads west into the "
  + "cityguard headquarters. A sign is attached to the door. ");

  add_exit ("north", ROOM_PATH + "marketp7.c");
  add_exit ("east", ROOM_PATH + "marketp1.c");
  add_exit ("west", ROOM_PATH + "guard1.c");

  add_item ("sign",
    "A sign is attached to the door. It reads:\n \n \n                "
  + "+----------------------+\n                | Silvercreek Citygu"
  + "ard|\n                |     Headquarters     |\n               "
  + " |  'Justice for all'   |\n                |                  "
  + "    |\n                +----------------------+\n \n            "
  + "   ...a note under it says:\n               ,.------.-.-------"
  + "-.----.\n               | In case of enemy, our |\n            "
  + "   | chief officer is now  |\n               | teaching worthy"
  + " men   |\n               | and women to defend   |\n           "
  + "    | our city and people.  |\n               `-------'----'--"
  + "--------'\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
