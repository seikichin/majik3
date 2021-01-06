/**
**      Example container by dazzt
*/

inherit "/inherit/container.c";
inherit "/inherit/keylock.c";

void create_container()
{
    set_name(({ "chest", "big chest", "landlubber chest", "big landlubber chest"}));
    set_short("A big landlubber chest");
    set_long("This is a big wooden landlubber chest, with big iron lock on it\n");

    set_dimensions(60, 60, 150);            
    set_container_dimensions(55, 55, 145);          /* space available for items */
    set_weight(10000);                              
    set_hp(100);
    set_max_hp(100);
    set_material("wood");

    set_solid();            /* is solid (see doc) */
    set_closable();         /* can be closed */
    set_lockable();         /* can be locked */
    set_open();             /* is open */
    set_unlocked();         /* and unlocked */
}





