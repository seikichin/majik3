inherit "/obj/skill/obj/skill";

create_skill()
{
  set_skill_name("create_joelinium");
  set_train_difficulty(2);
  set_base_percent(1);
  add_base_stat("wis",10);
  add_base_stat("pow",10);
  add_base_stat("int",50);
  add_base_stat("dex",30);
  set_parent_skill("upkeep");
  set_ep_cost(15);
  set_sp_cost(0);
  set_hp_cost(0);
  set_duration(3);
}
do_success(me,target,result)
 {
   object potion;
   if(present("newt eye",THIS) && 
      present("psylosibin",THIS) &&
      present("carvinorax",THIS))
   {
    write(wrap("You carefully mix the newt's eye with the psylosibin "+
    "and carvinorax and hope for a new substance.\n"));
    message("standard",THIS->query_cap_name()+" mixes a newt's eye with "+
    "some other substances and grunts and presses them together.\n",
    ENV(THIS),THIS);
    potion = clone_object("/home/madrid/agriculture/cure/joelinium.c");
    potion->move(THIS);
    destruct(present("newt eye",THIS));
    destruct(present("carvinorax",THIS));
    destruct(present("psylosibin",THIS));
    return 1;
  }
  else
  {
    write("You do not have the proper ingrediants to make the remedy.\n");
    return 1;
  }

}
do_failure(me,target,result)
{
 object potion;
 if(present("newt eye",THIS) && 
    present("carvinorax",THIS) &&
    present("psylosibin",THIS))
   {
    write("You mix the ingredients, but the result doesn't seem right.\n");
    potion = clone_object("/home/pook/farms/items/jar_brown_goop.c");
    potion->move(THIS);
    clone_object("/home/pook/farms/items/pouch.c")->move(THIS);
    destruct(present("newt eye",THIS));
    destruct(present("carvinorax",THIS));
    destruct(present("psylosibin",THIS));
    return 1;
   }
   else
   {
    write("You do not have the proper ingrediants to make the remedy.\n");
    return 1;
   }
}
