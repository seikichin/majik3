inherit "/obj/skill/obj/skill";

create_skill()
{
  set_skill_name("create_asthmil");
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
   if(present("red elm bark",THIS) && present("sunburst tulip",THIS) && present("dawntear",THIS))
   {
    write("You drop the red elm bark and sunburst tulip into the jug of dawntear "
     + "and mix it around for a bit.\n");
    message("standard",THIS->query_cap_name()+" drops a tulip and a piece of bark into "+
    "a jug.\n",ENV(THIS),THIS);
    potion = clone_object("/home/pook/farms/items/jug_asthmil.c");
    potion->move(THIS);
    destruct(present("red elm bark",THIS));
    destruct(present("sunburst tulip",THIS));
    destruct(present("dawntear",THIS));
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
   if(present("red elm bark",THIS) && present("sunburst tulip",THIS) && present("dawntear",THIS))
   {
    write("You mix the ingredients, but the result doesn't seem right.\n");
    potion = clone_object("/home/pook/farms/items/jug_blueliquid.c");
    potion->move(THIS);
    destruct(present("red elm bark",THIS));
    destruct(present("sunburst tulip",THIS));
    destruct(present("dawntear",THIS));
    return 1;
   }
   else
   {
    write("You do not have the proper ingrediants to make the remedy.\n");
    return 1;
   }   
}
