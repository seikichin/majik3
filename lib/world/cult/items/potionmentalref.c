inherit ITEM;

#include "../path.h"

create_item()
{
     set_name(({"potion","potion of mental refreshment"}));
     set_short("a Potion of Mental Refreshment");
     set_long(wrap("It is a small glass vial with some thick, purple liquid in it.\n"));


     set_dimensions(6, 6, 15);
     set_weight(20);
     set_material("glass");
     set_taste("The liquid tastes very grainy.\n");
     set_smell("It smells a little like chocolate and coffee mixed.\n");
     
}

init()
{
   add_action("do_consume","consume");
}

do_consume(string what)
{
  if(!what)
  {
   write("Consume what?\n");
   return 1;
  }

  if(what == "potion of mental refreshment")
  {
   write(wrap("You drink down the potion and feel much more alert.\n"));
   message("standard", THIS->query_cap_name() + " downs a vial of some purple "+
    "liquid.\n", ENV(THIS), THIS);
   THIS->set_sp(THIS->query_sp()+ 250);
   clone_object(ITEM_PATH + "vial.c")->move(THIS);
   destruct(THOB);
   return 1;
  }
}


