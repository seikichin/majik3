#include "../path.h"

inherit ROOM;

create_room ()
{
    set_short ("At a small pond");
    set_long  ("You stand at a small pool of crystal clear water. "
      +"Water bursts out from a cliff above you on the north side"
      +" of the pool forming a small waterfall. Stairs have been cut"
      +" in the stone and lead up to the cliff. The pool is in the west"
      +" and a passagaway leads east from here.");
    
    add_exit ("east", ROOM_PATH + "pass2.c");
    add_exit ("west", ROOM_PATH + "pool.c");
    add_exit ("up", ROOM_PATH + "cliff.c");
    
    add_sound ("The sound of the water falling down to the pool is soothing.\n");
    add_sound ("The water looks inviting and very refreshing though cold"
      +" it may be...\n");
    
    set_outdoors(4);
}

