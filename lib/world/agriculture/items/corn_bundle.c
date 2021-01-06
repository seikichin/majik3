#include "../path.h"
inherit ITEM;

create_item()
{
    set_name(({"bundle","corns","cobs","corn-cobs"}));
    set_short("a bundle of corn-cobs");
    set_long(wrap("This is a bundle of corn-cobs. It holds ten cobs that "
	+"are held together by twine. You can separate it into "
	+"individual pieces by 'separate corns'.\n"));
    set_dimensions(10, 25, 15);
    set_material("food");
    
}
init()
{
    add_action("do_separate","separate");
}
do_separate(string what)
{
    int i;
    if(what == "corns")
    {
	write(wrap("You separate the bundle into ten individual cobs.\n"));
	for(i = 0;i<10;i++)
	{
	    clone_object(ITEM_PATH + "corn.c")->move(THIS);
	}
	destruct(THOB);
	return 1;
    }
}
