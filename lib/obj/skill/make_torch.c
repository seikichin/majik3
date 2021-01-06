//madrid

inherit "obj/skill/obj/skill";

create_skill()
{
    set_skill_name("create_torch");
    set_train_difficulty(1);
    set_base_percent(10);
    add_base_stat("str",20);
    add_base_stat("dex",40);
    add_base_stat("int",10);
    add_base_stat("agi",30);
    set_parent_skill("survival_general");
    set_ep_cost(5);
    set_sp_cost(0);
    set_hp_cost(0);
    set_duration(2);
}
do_success(me,target,result)
{
    object ob;
    write("You proudly hold you torch high for all to see.\n");
    message("standard",THIS->query_cap_name()+" stands proud as he "+
      "fashions a torch.\n",ENV(THIS),THIS);
    ob = clone_object("/home/namhas/torch.c");
    ob->move(THIS);
    return 1;
}
do_failure(me,target,result)
{
    write("You failed to make anything\n");
    return 1;
}

