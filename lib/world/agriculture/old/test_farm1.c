inherit "/home/madrid/agriculture/farm_room.c";
string buf;
create_farm()
{
  set_short("A farming plot");
  //set_save_file("/home/madrid/agriculture/test_farm1.o");
  set_crop_type("potatoes");
  add_exit("east","/home/madrid/agriculture/test_farm2.c");
  add_exit("northeast","/home/madrid/agriculture/room.c");
}
