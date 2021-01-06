// DATE        : Sun Feb  8 19:15:17 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
    set_short ("Falan's way");
    set_long (
      "You're now on Falan's way which runs through the area of Enda"
      + "len. Being the part of the city where most of the nobles of S"
      + "ol'daran live it sure is a breathtaking sight. Luxurious tree"
      + "houses rest on the largest treetops on the both sides of the "
      + "street and spiralling stairs lead up to their doors. The str"
      + "eet leads north and south.");

    add_exit ("south", ROOM_PATH + "falan1.c");
    add_exit ("north", ROOM_PATH + "falan3.c");
    add_exit ("west", ROOM_PATH + "mansground.c");

    add_sound ("A majestetic deer gracefully jumps across the street.");
    add_sound ("You can hear laughter and singing coming from a nearby building.");
    add_sound ("Birds chirp carefreely on the branches of a tree near you.");

    set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
    return 12;
}
