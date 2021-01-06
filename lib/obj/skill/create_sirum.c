inherit "/obj/skill/obj/skill";

create_skill()
{
  set_skill_name("create_sirum");
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
   if(present("zormroot",THIS) &&
     present("red elm bark",THIS) &&
     present("wildwool",THIS))
   {
    write(wrap("You forcefully crush the zormroot, wildwool and "+
    "red elm bark together in your hand with great force.\n"));
    message("standard",THIS->query_cap_name()+" grunts and crushes a few "+
    "substances together.\n",
    ENV(THIS),THIS);
    potion = clone_object("/home/madrid/agriculture/cure/sirum.c");
    potion->move(THIS);
    destruct(present("zormroot",THIS));
    destruct(present("red elm bark",THIS));
    destruct(present("wildwool",THIS));
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
 if(present("zormroot",THIS) &&
    present("red elm bark",THIS) &&
    present("wildwool",THIS))
   {
    write("You mix the ingredients, but the result doesn't seem
    right.\n");
    potion = clone_object("/home/madrid/agriculture/cure/oak_bark.c");
    potion->move(THIS);
    destruct(present("zormroot",THIS));
    destruct(present("red elm bark",THIS));
    destruct(present("wildwool",THIS));
    return 1;
   }
   else
   {
    write("You do not have the proper ingrediants to make the remedy.\n");
    return 1;
   }
}


