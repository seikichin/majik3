// DATE        : Tue Dec 23 14:29:07 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Totem of Spring");
  set_long (
    "Birds chirp happily and the sound of the wind hustling in the "
  + "trees makes you feel calm and serene. The fresh scent of natu"
  + "re and flowers fills the air. A totem of an elf riding a maje"
  + "stetic great white swan stands in the center of the square. T"
  + "he holy swan temple welcomes you to enter it in the west and "
  + "three leafcovered paths lead to north, south and east.");

  add_exit ("north", ROOM_PATH + "corner2.c");
  add_exit ("west", ROOM_PATH + "temple.c");
  add_exit ("east", ROOM_PATH + "spass1.c");
  add_exit ("south", ROOM_PATH + "corner3.c");

  add_item ("swan totem swantotem joutsen",
    " /\\    ,;,    /\\  The Swan is a majestetic sight indeed. Its"
  + " white\n //\\   o O   /\\\\  painted wings almost shine with t"
  + "heir own light,\n ///\\  \\V/  /\\\\\\  and it has been carved"
  + " so skillfully that it seems\n  ///\\  H  /\\\\\\   like if it"
  + " was really flying. On the chilly spring\n   ///\\,H./\\\\\\  "
  + "  mornings elves gather here around the totem and\n     /(   )"
  + "\\      celebrate the coming summer. Spring and the swan\n    "
  + "   `.'        symbolize rebirth and life for the elves and fr"
  + "om\n       | |        all of the totems this must be most sacr"
  + "ed to them...\n       | |\n       | |\n      /   \\\n");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
