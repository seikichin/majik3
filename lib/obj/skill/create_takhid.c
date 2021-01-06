inherit "/obj/skill/obj/skill";

create_skill()
{
  set_skill_name("create_takhid");
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
   if(present("morningdew",THIS) && present("dog-ear leaf",THIS) && present("awnbloom",THIS))
   {
    write("You place the dog-ear leaf and awnbloom into the jug of morningdew and "
     + "mix them together for a while.\n");
    message("standard",THIS->query_cap_name()+" places a flower and a leaf into a "+
    "wooden jug and mixes it together.\n",ENV(THIS),THIS);
    potion = clone_object("/home/pook/farms/items/jug_takhid.c");
    potion->move(THIS);
    destruct(present("morningdew",THIS));
    destruct(present("dog-ear leaf",THIS));
    destruct(present("awnbloom",THIS));
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
 if(present("morningdew",THIS) && present("dog-ear leaf",THIS) && present("awnbloom",THIS))
   {
    write("You mix the ingredients, but the result doesn't seem right.\n");
    potion = clone_object("/home/pook/farms/items/jug_pinkwater.c");
    potion->move(THIS);
    destruct(present("morningdew",THIS));
    destruct(present("dog-ear leaf",THIS));
    destruct(present("awnbloom",THIS));
    return 1;
   }
   else
   {
    write("You do not have the proper ingrediants to make the remedy.\n");
    return 1;
   }   
}
