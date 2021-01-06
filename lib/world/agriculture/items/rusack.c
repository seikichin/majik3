inherit "/inherit/container.c";

create_container()
{
    set_name(({"rusack","sack"}));
    set_short("a brown rusack");
    set_long(wrap("A brown rusack made of burlap. The sack is quite deep and could "
     + "hold many items.\n"));

    set_dimensions(5, 5, 5);            
    set_container_dimensions(105, 55, 145);
    set_material("burlap");

   
    set_closable();
    set_open();
}

query_value ()
{
  return 5;
}
