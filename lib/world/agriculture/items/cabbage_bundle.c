#include "../path.h"
inherit ITEM;

create_item()
{
  set_name(({"a bundle of cabbage heads","bundle","cabbages","heads"}));
  set_short("a bundle of cabbage heads");
  set_long(wrap("This is a bundle of cabbages. It holds ten cabbages that are held "
   + "together by twine. You can separate it into individual pieces by 'separate "
   + "cabbages'.\n"));
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
  if(what == "cabbages")
   {
    write(wrap("You separate the bundle into ten individual cabbages.\n"));
    for(i = 0;i<10;i++)
     {
      clone_object(ITEM_PATH + "cabbage.c")->move(THIS);
     }
    destruct(THOB);
    return 1;
   }
}
