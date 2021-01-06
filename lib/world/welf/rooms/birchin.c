// DATE        : Thu Feb  5 18:15:34 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("In front of a wonderful treehouse");
  set_long (
    "You're standing on a small porch on the treetop of a strong an"
  + "d beautiful birchtree. A small treehouse has been built on th"
  + "e tree's limbs. The house looks like if it was a part of the "
  + "tree itself. Whoever built or designed the house must have be"
  + "en a genius or an artist extraordinary. It's built of shimmer"
  + "ing white wood and its roof is made of leaves golden in color"
  + ". It looks like a slender tower and a spacious mansion at the"
  + " same time, and what's most curious about it is that it never"
  + " looks the same when you glance at it again. Stairs lead down"
  + " to the ground level from here.");

  add_exit ("west", ROOM_PATH + "birchal.c");
  add_exit ("down", ROOM_PATH + "birchop.c");

  add_sound ("A squirrel jumps from a tree to another near you.");
  add_sound ("Birch chirp happily in the trees nearby.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
