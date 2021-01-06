#include "../path.h"
inherit ITEM;

create_item()
{
  set_name(({"bundle","tomatos"}));
  set_short("a bundle of tomatos");
  set_long(wrap("This is a bundle of tomato. It holds ten red tomatos that are held "
   + "together by twine. You can separate it into individual pieces by 'separate "
   + "tomatos'.\n"));
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
  if(what == "tomatos")
   {
    write(wrap("You separate the bundle into ten individual tomatos.\n"));
    for(i = 0;i<10;i++)
     {
      clone_object(ITEM_PATH + "tomato.c")->move(THIS);
     }
    destruct(THOB);
    return 1;
   }
}
