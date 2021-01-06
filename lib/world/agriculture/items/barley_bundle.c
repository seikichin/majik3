#include "../path.h"
inherit ITEM;

create_item()
{
  set_name(({"a bundle of barleys","bundle","barleys","spikes"}));
  set_short("a bundle of barleys");
  set_long(wrap("This is a bundle of barley spikes. It holds ten barleys that are held "
               +"together by twine. You can separate it into individual pieces by "
               +"'separate barleys'.\n"));

  set_material ("food");
  set_dimensions(10, 25, 15); 
}
init()
{
  add_action("do_separate","separate");
}
do_separate(string what)
{
 int i;
  if(what == "barleys")
   {
    write(wrap("You separate the bundle into ten individual barleys.\n"));
    for(i = 0;i<10;i++)
     {
      clone_object(ITEM_PATH + "barley.c")->move(THIS);
     }
    destruct(THOB);
    return 1;
   }
}
