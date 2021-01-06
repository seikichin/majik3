inherit "obj/skill/obj/skill";
/* 
   skill_root
	magical 
	  academic
	    witchcraft
	      flask_making

   Coded by Yorkaturr
*/

create_skill()
{
    set_skill_name("flask_making");
    set_train_difficulty(8);
    set_base_percent(10);
    add_base_stat("pow",20);
    add_base_stat("dex",40);
    add_base_stat("str",40);
    set_parent_skill("witchcraft");
    set_ep_cost(30);
    set_sp_cost(30);
    set_hp_cost(10);
    set_duration(15);
}

do_success(me,target,result)
{
    object flask, sand;
    sand=present("sand",THIS);
    if(sand)
    {
	write("You squeeze the sand and mold a fine looking flask.\n");
	message("standard",THIS->query_cap_name()+" succesfully molds a flask.\n",ENV(THIS),THIS);
	flask = clone_object("/home/yorkaturr/items/flask.c");
	flask->move(THIS);
	destruct(sand);
	return 1;
    }
    else
    {
	write("You need a quantity of sand to make a flask.\n");
         return 0;
    }
}
do_failure(me,target,result)
{
    write("You squeeze the sand but only manage to mess up your hands.\n");
    destruct(present("sand",THIS));
    return 1;
}

