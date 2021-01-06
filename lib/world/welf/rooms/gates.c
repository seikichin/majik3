// DATE        : Wed Dec 24 16:29:08 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
    set_short ("At the gates of Sol'daran");
    set_long (
      "You're standing just inside the grand city of Sol'daran, the f"
      + "amed city of Tanir forest folk. Numerous lanterns and lamps i"
      + "lluminate the whole city in a sea of lights. Awe and serenity"
      + " fills the air and you stand wide eyed pondering what miracles the "
      + "city holds inside. The street continues north towards"
      + " the holy swan temple and in the south you can enter the vast"
      + " forest surrounding the city.");

    add_exit ("south","/world/y100x201");
    add_exit ("north", ROOM_PATH + "street2.c");

  add_sound("Laughter and occasionals cheers sound from somewhere in northeast"
           +" where you spot a strange treehouse.\n");
 add_sound("The smell of cooked rabbit and fresh bread drifts in from northeast.\n");
    add_object ( MONSTER_PATH + "guard.c");
    set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
    return 12;
}
