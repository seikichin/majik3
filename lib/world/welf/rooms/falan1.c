// DATE        : Sun Feb  8 18:36:35 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Falan's way");
  set_long (
    "You're walking along Falan's way which runs through Endalen, t"
  + "he part of the city where the most important and noblest pers"
  + "ons of Sol'daran live. At the both sides of the street, spira"
  + "lling stairways lead up to treehouses that rest on the larges"
  + "t treetops. In the south you can see a nice looking fountain "
  + "square. A path leads east to an ancient oak and the street co"
  + "ntinues towards north.");

  add_exit ("south", ROOM_PATH + "square.c");
  add_exit ("north", ROOM_PATH + "falan2.c");
  add_exit ("east", ROOM_PATH + "magoak.c");

  add_item ("oak ancient east",
    "You can see an ancient and huge oak in the east. On its top is"
  + " built a wooden tower that looks like a dwelling that a magic"
  + "ian would prefer. Some purple smoke rise from highest windows"
  + " and an occasional flash of light confirms your thought of so"
  + "me wizard living in it. There's a large sign hung above its d"
  + "oor but you can't quite make it out what it reads.\n");

  add_sound ("There's an octarine flash of light in the windows of the treehouse in east.");
  add_sound ("You can hear beautiful singing coming from some treehouse nearby.");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
