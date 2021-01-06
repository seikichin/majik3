#include "../path.h"
inherit ITEM;

create_item()
{
  set_name(({"bundle","beans","pods"}));
  set_short("a bundle of beans");
  set_long(wrap("This is a bundle of beanpods. It holds ten beanpods that are held "
   + "together by twine. You can separate it into individual pieces by 'separate "
   + "beans'.\n"));
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
  if(what == "beans")
   {
    write(wrap("You separate the bundle into ten individual pods.\n"));
    for(i = 0;i<10;i++)
     {
      clone_object(ITEM_PATH + "bean.c")->move(THIS);
     }
    destruct(THOB);
    return 1;
   }
}
