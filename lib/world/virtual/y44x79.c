config (object ob)
{
  ob->set_outdoors(4);

  ob->set_short("Ruins of an ancient temple");
  ob->set_long ("You see a ruined temple here. It has been destroyed "
  + "long time ago. But still you can feel a vile presence"
  + " somewhere inside the ruins.");

  ob->add_exit("enter", "/home/dranil/draguild/rooms/temple.c");
  ob->set_author("dranil");


}
