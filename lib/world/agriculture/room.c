inherit ROOM;
create_room()
{
  set_short("A room");
  //set_save_file("/home/madrid/agriculture/test_farm1.o");
  set_long("A room.\n");
  add_exit("southeast","/home/madrid/agriculture/test_farm2.c");
  add_exit("southwest","/home/madrid/agriculture/test_farm1.c");
}

