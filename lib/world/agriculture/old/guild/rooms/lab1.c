// DATE        : Sun Jan 25 22:54:18 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_area("university");
  add_object(MONSTER_PATH+"gnar.c");
  set_short ("Labratory");
  set_long (
    "The inside of this room is cluttered from wall to wall with va"
  + "rious items used in experiments. Among these you notice a scr"
  + "oll case against the east wall and a table near the north one"
  + ". There is a small window above the scroll case, and an oil l"
  + "amp hanging from the ceiling.");

  add_exit ("west", ROOM_PATH + "unihall2.c");

  add_item ("table",
    "The table has flasks, jars, testtubes all over it. In the cent"
  + "er you see a few items next to a jar filled with some wierd s"
  + "ubstance.\n");

  add_item ("items",
    "Next to the jar, there are four items which appear "
  + "to be seperated from the other clutter of the table. There is"
  + " a leaf, some paste and a pouch of some strange substance.\n");

  add_item ("withered_scroll",
    "Th"
  + "e scroll is quite age worn, however you can make out some tex"
  + "t in the center of the document written in sartog. It reads: "
  + "...come accross in my expe...ents wit. cures for these damn d"
  + "iseases. I have fou.d that in all cases only thre. .r four in"
  + "gredients were req..red. It took me many yea.. to find the ap"
  + "propiate items, but I did it .ventually... At the bottom it i"
  + "s signed: Gran.in, alchemist re..wn.\n");

  add_item ("jar",
    "The jar is made of thick"
  + " glass. It is about 25cm high and 10cm wide. It is mostly ful"
  + "l of some light brown substance, like thick gravy.\n");

  add_item ("lamp oil_lamp",
    "The oil la"
  + "mb is lit but it's not providing very much light.\n");

  add_item ("paste",
    "A pale whit"
  + "e hunk of guyano paste, about the size of your palm. It feels"
  + " sticky and wet.\n");

  add_item ("case scroll_case",
    "The scroll case is made of thin wood strips "
  + "which provide holes for the scrolls to be placed in. One very"
  + " withered scroll is half hanging out of the case.\n");

  add_item ("window",
    "Outside the"
  + " window you see a small forest and a few farm plots among the"
  + " rolling green plains.\n");

  add_item ("pouch",
    "A small brown pouch, half full of sile"
  + " powder. The powder is a bright yellow and very grainy.\n");

  add_item ("scroll_case",
    "The s"
  + "croll case is made of thin wood strips which provide holes fo"
  + "r the scrolls to be placed in. One very withered scroll is ha"
  + "lf hanging out of the case.\n");

  add_item ("leaf",
    "The leaf is brown with a few smal"
  + "l, yellow spots on it.\n");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
