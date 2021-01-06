inherit "obj/skill/obj/skill.c";
/* 
   skill_root
	magical 
	  academic
	    witchcraft
   
   Coded by Yorkaturr
*/

create_skill()
{
    set_skill_type("node");
    set_skill_name("witchcraft");
    set_train_difficulty(7);
    set_base_percent(10);
    add_base_stat("pow",20);
    add_base_stat("wis",20);
    add_base_stat("int",50);
    add_base_stat("dex",10);
    set_parent_skill("academic");
}

