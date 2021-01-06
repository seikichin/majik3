inherit "/inherit/container.c";

create_container()
{
    set_name(({"rusack","sack"}));
    set_short("a brown rusack");
    set_long(wrap("A brown rusack made of burlap. The sack is quite deep and could "
     + "hold many items.\n"));

    set_dimensions(110, 60, 150);            
    set_container_dimensions(105, 55, 145);
    set_weight(200);                              
    set_hp(100);
    set_max_hp(100);
    set_material("wood");

   
    set_closable();
    set_open();
}
