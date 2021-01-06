inherit "/inherit/container.c";

create_container()
{
  set_name(({"pouch"}));
  set_short("a brown pouch");
  set_long(wrap("A small brown pouch.\n"));
  set_material("cloth");
  set_dimensions(10, 10, 25); 

  set_closable();
  set_open();
}
