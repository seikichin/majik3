// DATE        : Tue Feb 10 19:55:51 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Forestpath");
  set_long (
    "You're standing on a forestpath which leads west deeper into t"
  + "he forest. In east it runs over a small bridge that crosses a"
  + " sparkling stream. A smaller path leads north along the strea"
  + "m. You can hear the birds singing everywhere around you and t"
  + "he smaller denisens of the sylvan realm, rabbits and squirrel"
  + "s, run carefreely here and there. Tall birch trees stand alon"
  + "g the path and behind them the forest gets denser and darker."
  + "");

  add_exit ("north", ROOM_PATH + "friver.c");
  add_exit ("east", ROOM_PATH + "fbridge.c");
  add_exit ("west", ROOM_PATH + "fclearing.c");

  add_item ("bridge",
    "A sturdy stone bridge, an old one, by the looks of it. It must"
  + " have been there as long as the stream it crosses.\n");

  add_item ("stream",
    "The stream"
  + " catches the light in a most enchanting way. It sparkles and "
  + "glimmers softly and beckons you to dive into it. In the north"
  + " you can indeed see a suitable swimming spot.\n");

  add_sound ("You can hear joyous laughter and splashing of water coming from north.");
  add_sound ("A small bunny hops across the path and disappears behind the trees.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
