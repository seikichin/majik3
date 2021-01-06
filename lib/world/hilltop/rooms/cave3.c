// DATE        : Sun Feb  8 19:29:00 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : yorkaturr

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Cave chamber");
  set_long (
    "You are in a chamber somewhere in the Hilltop Caverns. There's"
  + " an old fireplace in the middle of the room and all kinds of "
  + "other things suggesting that someone is living here, or at le"
  + "ast has been living here. There's a small sign on the wall. T"
  + "he eastern wall looks strange somehow.");

  add_exit ("west", ROOM_PATH + "cave2");

  add_item ("wall east east_wall",
    "It feels like you could walk through wall.\n");

  add_item ("sign",
    "Welcome to Hilltop'"
  + "s Sneakers training room, you can: \n  1) 'join' to the guild\n"
  + "  2) 'train' some skills\n  3) 'advance' advance your title\n  "
  + "4) get some 'info'\n");

  add_object(MONSTER_PATH + "thief.c");
}

 do_east()
  {
  tell_object(ENV(THIS),THIS->query_cap_name()+" walks through the wall!\n");
  THIS->move(ROOM_PATH + "linguistics.c");
  write("You walk through the wall!\n");
  THIS->force_us("l");
  return 1;
   }
   init_room()
    {
     add_action("do_east","east");
     }
// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
