#include "../path.h"
inherit ITEM;

create_item()
{
  set_name(({"bundle","potatos"}));
  set_short("a bundle of potatos");
  set_long(wrap("This is a bundle of potatos. It holds ten potatos that are held "
   + "together by twine. You can separate it into individual pieces by 'separate potatos'.\n"));
  set_dimensions(10, 25, 15); 
  set_material("food");
  set_smell("It smells musty.\n");
  

}
init()
{
  add_action("do_separate","separate");
}
do_separate(string what)
{
 int i;
  if(what == "potatos")
   {
    write(wrap("You separate the bundle into ten individual potatos.\n"));
    for(i = 0;i<10;i++)
     {
      clone_object(ITEM_PATH + "potato.c")->move(THIS);
     }
    destruct(THOB);
    return 1;
   }
}
