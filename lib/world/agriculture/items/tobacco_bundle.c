#include "../path.h"
inherit ITEM;

create_item()
{
  set_name(({"bundle","tobaccos","leaves"}));
  set_short("a bundle of tobacco leaves");
  set_long(wrap("This is a bundle of tobacco leaves. It holds ten leaves that are held "
   + "together by twine. You can separate it into individual pieces by 'separate "
   + "leaves'.\n"));
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
  if(what == "leaves")
   {
    write(wrap("You separate the bundle into ten individual leaves.\n"));
    for(i = 0;i<10;i++)
     {
      clone_object(ITEM_PATH + "tobacco.c")->move(THIS);
     }
    destruct(THOB);
    return 1;
   }
}
