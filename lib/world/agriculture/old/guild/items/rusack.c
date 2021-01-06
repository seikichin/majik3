inherit "/inherit/container.c";

create_container()
{
    set_name(({"rusack","sack"}));
    set_short("a brown rusack");
    set_long(wrap("A brown rusack made of burlap. The sack is quite deep and could "
     + "hold many items.\n"));

    set_material("burlap");
    set_dimensions(20, 20, 20);            
    set_container_dimensions(105, 55, 145);
   
    set_closable();
    set_open();
}
