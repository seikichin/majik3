inherit "obj/skill/obj/skill";

create_skill()
{
	set_skill_type("node");
	set_skill_name("religious");
	set_train_difficulty(7);
	set_base_percent(15);
	add_base_stat("pow",30);  // Total of Base Stats is 100
	add_base_stat("int",20);
	add_base_stat("wis",40);
	add_base_stat("dex",10);
	set_parent_skill("magical");
}


