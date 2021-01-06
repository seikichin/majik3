inherit "/obj/skill/obj/skill";

create_skill()
{
  set_skill_name("make_potion");
  set_train_difficulty(2);
  set_base_percent(15);
  add_base_stat("wis",10);
  add_base_stat("pow",10);
  add_base_stat("int",50);
  add_base_stat("dex",30);
  set_parent_skill("potion_magic");
  set_ep_cost(10);
  set_sp_cost(10);
  set_hp_cost(0);
  set_duration(3);
}

do_success(me,target,result)
{
  object potion;
  if(present("coca",THIS) && present("vial",THIS))
  {
    write("Your hands glow bright as magically a potion appears.\n");
    message("standard",THIS->query_cap_name()+" magically invokes a "+
    "potion from another dimension.\n",ENV(THIS),THIS);
    potion = clone_object("/home/pook/guilds/cult/items/potionmentalref.c");
    potion->move(THIS);
    destruct(present("root",THIS));
    destruct(present("vial",THIS));
    return 1;
  }
  else
  {
    write("You do not have the proper ingrediants to make the potion.\n");
    return 1;
  }
}
do_failure(me,target,result)
{
  write("Your magic falters and you fail to create a potion.\n");
  return 1;
}
 
