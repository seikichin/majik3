// DATE        : Thu Feb  5 17:37:49 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Burial chapel");
  set_long (
    "The dead are given their final blessings in this small chapel."
  + " Like the swan that sings incredibly beautifully on its last m"
  + "oments will the dead tanir be blessed and remembered here bef"
  + "ore their spirits can journey onwards to their gods. The chap"
  + "el is decorated in pure white and silvery colours. A beam of "
  + "light shines through a narrow window illuminating the center "
  + "of the floor brightly at the spot where an altar of white sil"
  + "verstreaked stone stands.");

  add_exit ("west", ROOM_PATH + "winterstr2.c");

  add_item ("altar",
    "The altar is made of some white silverstreaked stone. A beam o"
  + "f light reflects from its silvery surface and makes the altar"
  + " shine in its radiant beauty. Some runes have been carved on "
  + "its sides, most propably prayers that go along those who are "
  + "blessed the final time on this block of stone.\n");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
