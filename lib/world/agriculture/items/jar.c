inherit "/inherit/container.c";

create_container()
{
  set_name(({"jar","glass jar","emptyjar"}));
  set_short("an empty glass jar");
  set_long(wrap("The jar is made of thick glass. It is about 25cm high and 10cm wide.\n"));
  set_dimensions(5, 5, 5);
  set_container_dimensions(9, 9, 24); 
  set_material("glass");

  set_closable();
  set_open();
}

query_value ()
{
  return 5;
}
