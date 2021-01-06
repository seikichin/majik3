inherit "obj/skill/obj/skill";

create_skill()
{
    set_skill_type("node");
    set_skill_name("combat");
    set_train_difficulty(7);
    set_base_percent(15);
    add_base_stat("str",40);  // Total of Base Stats is 100
    add_base_stat("agi",40);
    add_base_stat("siz",20);
    set_parent_skill("movement");
}
