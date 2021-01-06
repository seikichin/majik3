#include "../path.h"
inherit ITEM;

create_item()
{
  set_name(({"bundle","wheats","spikes"}));
  set_short("a bundle of wheat spikes");
  set_long(wrap("This is a bundle of wheat. It holds ten spikes of wheat" 
               +"that are held together by twine. You can separate it "
               +"into individual pieces by 'separate wheats'.\n"));
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
  if(what == "wheats")
   {
    write(wrap("You separate the bundle into ten individual wheats.\n"));
    for(i = 0;i<10;i++)
     {
      clone_object(ITEM_PATH + "wheat.c")->move(THIS);
     }
    destruct(THOB);
    return 1;
   }
}
