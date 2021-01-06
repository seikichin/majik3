inherit "/obj/skill/obj/skill";

create_skill()
{
  set_skill_name("create_tethar");
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
   if(present("mistflower",THIS) &&
     present("sorceros root",THIS) &&
     present("unicorn lichen",THIS))
   {
    write("You carefully put the mistflower and sorceros root into the "+
    "the hole in the bottom of the unicorn lichen.\n");
    message("standard",THIS->query_cap_name()+" puts some substances "+
    "into a unicorn lichen.\n",
    ENV(THIS),THIS);
    potion = clone_object("/home/madrid/agriculture/cure/tethar.c");
    potion->move(THIS);
    destruct(present("sorceros root",THIS));
    destruct(present("mistflower",THIS));
    destruct(present("unicorn lichen",THIS));
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
 if(present("sorceros root",THIS) &&
    present("mistflower",THIS) &&
    present("unicorn lichen",THIS))
   {
    write("You mix the ingredients, but the result doesn't seem
    right.\n");
    potion = clone_object("/home/madrid/agriculture/cure/rock.c");
    potion->move(THIS);
    destruct(present("sorceros root",THIS));
    destruct(present("mistflower",THIS));
    destruct(present("unicorn lichen",THIS));
    return 1;
   }
   else
   {
    write("You do not have the proper ingrediants to make the remedy.\n");
    return 1;
   }
}

