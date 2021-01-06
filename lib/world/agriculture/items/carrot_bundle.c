#include "../path.h"
inherit ITEM;

create_item()
{
  set_name(({"bundle","carrots"}));
  set_short("a bundle of carrots");
  set_long(wrap("This is a bundle of carrots. It holds ten tasty looking carrots that "
               +"are held together by twine. You can separate it into individual pieces "
               +"by 'separate carrots'.\n"));
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
  if(what == "carrots")
   {
    write(wrap("You separate the bundle into ten individual carrots.\n"));
    for(i = 0;i<10;i++)
     {
      clone_object(ITEM_PATH + "carrot.c")->move(THIS);
     }
    destruct(THOB);
    return 1;
   }
}
