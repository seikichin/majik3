inherit "/home/madrid/agriculture/farm_room.c";
create_farm()
{
  set_short("farm room");
  set_save_file("/home/madrid/agriculture/strawberry.o");
  set_farmer("Madrid");
  set_crop_type("strawberry");
}
init_farm()
{
  add_action("do_plant","plant");
  add_action("do_harvest","harvest");
}
