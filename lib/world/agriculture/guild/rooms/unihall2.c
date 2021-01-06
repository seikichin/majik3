// DATE        : Sun Jan 25 22:51:11 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("university");
  set_short ("Hall of Knowledge");
  set_long (
    "The ceiling here is many times your height above the ground an"
  + "d is supported by huge pillars which line the walls. Everythi"
  + "ng is contructed of deep black obsidian. In between each pill"
  + "ar is a small pedastal which holds an oil lamp. The hall cont"
  + "inues on to the west and there is a small doorway at the east"
  + " end. ");

  add_exit ("west", ROOM_PATH + "unihall1.c");
  add_exit ("east", ROOM_PATH + "lab1.c");

  add_item ("pillar pillars",
    "The pillars line the walls about 2 meters away from them. They"
  + " are too numerous\nto count and you can only guess at their he"
  + "ight, since they reach all the way\nto the ceiling above.\n");

  add_item ("obsidian",
    "This"
  + " entire room is made of the gleaming black obsidian. You can "
  + "almost make\nout your relection in it.\n");

  add_item ("lamp lamps pedastal pedastals",
    "The pedastals stand abo"
  + "ut 1 meter high and on top of each is a large oil lamp to\npro"
  + "vide some light for the immense hall.\n");

  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
