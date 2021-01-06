// DATE        : Fri Oct 31 14:12:36 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The Totem of Winter");
  set_long (
    "The ground here is frozen and bare. No leaves decorate it like"
  + " elsewhere in the village. A totem resembling an elf riding a"
  + " great grey wolf stands in the center of the desolate square."
  + " The Swan Temple welcomes you to enter it in the south and th"
  + "ree paths lead to east, north and west from here.");

  add_exit ("south", ROOM_PATH + "temple.c");
  add_exit ("west", ROOM_PATH + "corner1.c");
  add_exit ("east", ROOM_PATH + "corner2.c");
  add_exit ("north", ROOM_PATH + "winterstr.c");

  add_item ("wolf totem wolftotem sepe susi",
    " \n     /\\,,/\\    The totem looks as fierce as the wolf it re"
  + "presents. Its\n    ; o  o ;   eyes glow red and a small wisp o"
  + "f vapor escapes through\n  ,--; () ;--. its gritted teeth. Wel"
  + "l, maybe its just your imagination,\n  |   ;==;   | but you do"
  + "n't feel so safe here, yet the elves come here\n  |    \"\"   "
  + " | on winter nights and pray for protection against the cold\n"
  + "  |___.______| dark nights and they really believe that if th"
  + "ey pray hard\n  |          | enough the sinister dark moon wil"
  + "l fall down from the skies\n  |__ __:_.__| and Afay will take "
  + "its place.  It is said that the winter\n  :          : wolves "
  + "helped elves during a war against the orcs. And still\n  ..   "
  + ".. .... some of their leader have been seen riding white wolv"
  + "es on\n  .          . their travels. Another legend says that "
  + "Kirkis the first\n               leader of the tanir tribe had"
  + " the power to change himself\n  .          . into a great wolf"
  + " and some of his descendants could still\n               posse"
  + "ss the same strange power...\n \n");

  add_sound ("You think the totem's eyes flashed red.");
  add_sound ("The totem is watching you, isn't it...");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
