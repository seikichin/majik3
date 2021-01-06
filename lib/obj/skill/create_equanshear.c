inherit "/obj/skill/obj/skill";

create_skill()
{
  set_skill_name("create_equanshear");
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
   if(present("vialanhydride",THIS) && present("silvergrassblades",THIS))
   {
    write("You drop the blades of silvergrass into the vial and watch it dissolve.\n");
    message("standard",THIS->query_cap_name()+" drops a few blades of grass into a "+
    "vial of some clear liquid.\n",ENV(THIS),THIS);
    potion = clone_object("/home/pook/farms/items/vial_equanshear.c");
    potion->move(THIS);
    destruct(present("vialanhydride",THIS));
    destruct(present("silvergrassblades",THIS));
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
 if(present("vialanhydride",THIS) && present("silvergrassblades",THIS))
   {
    write("You mix the ingredients, but the result doesn't seem right.\n");
    potion = clone_object("/home/pook/farms/items/vial_greenliquid.c");
    potion->move(THIS);
    destruct(present("vialanhydride",THIS));
    destruct(present("silvergrassblades",THIS));
    return 1;
   }
   else
   {
    write("You do not have the proper ingrediants to make the remedy.\n");
    return 1;
   }   
}


