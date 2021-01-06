#define PATH "/doc/examples/door/"

inherit ROOM;

create_room()
{
  set_short("A room with a locked door");
  set_long("You can feel sheer happiness about finding this marvellous"
  + " example on doors and locks and keys. Now you are having fun.\n");

  add_door("north", PATH + "room2", "door", "bone",
  PATH + "key_to_that_door",16,2);

  add_object(PATH + "key_to_that_door.c");
}
