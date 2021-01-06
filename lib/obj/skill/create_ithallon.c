inherit "/obj/skill/obj/skill";

create_skill()
{
  set_skill_name("create_ithallon");
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
   if(present("wolf saliva",THIS) && present("pixie dust",THIS) && present("psykmoss",THIS))
   {
    write("You pour the wolf saliva and then the pixie dust over the psykmoss. It "
     + "quickly changes color to a deep red.\n");
    message("standard",THIS->query_cap_name()+" pours a vial of something and empties "+
    "a pouch on some moss.\n",ENV(THIS),THIS);
    potion = clone_object("/home/pook/farms/items/ithallon.c");
    potion->move(THIS);
    clone_object("/home/pook/farms/items/pouch.c")->move(THIS);
    clone_object("/home/pook/farms/items/emptyvial.c")->move(THIS);
    destruct(present("wolf saliva",THIS));
    destruct(present("pixie dust",THIS));
    destruct(present("psykmoss",THIS));
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
   if(present("wolf saliva",THIS) && present("pixie dust",THIS) && present("psykmoss",THIS))
   {
    write("You mix the ingredients, but the result doesn't seem right.\n");
    potion = clone_object("/home/pook/farms/items/red_moss.c");
    potion->move(THIS);
    clone_object("/home/pook/farms/items/pouch.c")->move(THIS);
    clone_object("/home/pook/farms/items/emptyvial.c")->move(THIS);
    destruct(present("wolf saliva",THIS));
    destruct(present("pixie dust",THIS));
    destruct(present("psykmoss",THIS));
    return 1;
   }
   else
   {
    write("You do not have the proper ingrediants to make the remedy.\n");
    return 1;
   }   
}
