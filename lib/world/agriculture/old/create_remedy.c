inherit "/obj/skill/obj/skill";

create_skill()
{
  set_skill_name("create_remedy");
  set_train_difficulty(2);
  set_base_percent(1);
  add_base_stat("wis",10);
  add_base_stat("pow",10);
  add_base_stat("int",50);
  add_base_stat("dex",30);
  set_parent_skill("upkeep");
  set_ep_cost(75);
  set_sp_cost(0);
  set_hp_cost(0);
  set_duration(3);
}
do_success(me,target,result)
 {
   object potion;
   if(present("astul",THIS) && present("jar",THIS) && present("paste",THIS) && present("silepouch",THIS))
   {
    write("You mix the astul leaf, wakan paste and sile into a jar.\n");
    message("standard",THIS->query_cap_name()+" mixes some things in a "+
    "jar.\n",ENV(THIS),THIS);
    potion = clone_object("/home/pook/farms/items/jar_pukabase.c");
    potion->move(THIS);
    clone_object("/home/pook/farms/items/pouch.c")->move(THIS);
    destruct(present("astul",THIS));
    destruct(present("paste",THIS));
    destruct(present("sile",THIS));
    destruct(present("emptyjar",THIS));
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
 if(present("astul",THIS) && present("jar",THIS) && present("paste",THIS) && present("silepouch",THIS))
   {
    write("You mix the ingredients, but the result doesn't seem right.\n");
    potion = clone_object("/home/pook/farms/items/jar_brown_goop.c");
    potion->move(THIS);
    clone_object("/home/pook/farms/items/pouch.c")->move(THIS);
    destruct(present("astul",THIS));
    destruct(present("paste",THIS));
    destruct(present("sile",THIS));
    destruct(present("emptyjar",THIS));
    return 1;
   }
   else
   {
    write("You do not have the proper ingrediants to make the remedy.\n");
    return 1;
   }   
}


