inherit "/inherit/container.c";

create_container()
{
  set_name(({"jug","wooden jug","emptyjug"}));
  set_short("a wooden jug");
  set_long(wrap("The jug is made of wood and is rather small.\n"));
  set_dimensions(10, 10, 25); 
  set_container_dimensions(8, 8, 22);
  set_material("wood");
  set_taste("You take a sip from the jug and feel refreshed by the clear water.");

  set_closable();
  set_open();
}

query_value ()
{
  return 5;
}
