inherit ROOM;

#include "../path.h"

create_room ()
{
 set_light (1);
 set_short ("entrance to example area.");
set_long ("You are entering in large cave. It's sure not a vulcan, it might been done by old river long time ago. But someone have made changes to old cave, you would be better watch your steps. There's sign hanging above your head,read it.\n");
add_exit ("south", ROOM_PATH+"one.c");
add_item ("sign","There is large sign above your head. Read it.\n");
}
init()
{
 ::init ();
 add_action ("do_read","read");
}
do_read (string str)
{
if (!str ||str != "sign")
 {
 notify_fail ("read what?\n");
 return 0;
 }
write ("Report all bugs.\n");
write ("This is only example area so you should not be here.\n");
return 1;
}


