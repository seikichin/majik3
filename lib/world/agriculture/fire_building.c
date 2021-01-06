#define pline(x)           message("0",x,THIS);
#define room(x)            message("0",x,ENV(THIS),THIS);
inherit "/obj/skill/obj/skill";
create_skill()
{
    set_skill_name("fire_bulding");
    set_train_difficulty(5);
    set_base_percent(15);
    add_base_stat("wis",30);
    add_base_stat("int",25);
    add_base_stat("dex",30);
    add_base_stat("str",15);
    set_parent_skill("upkeep");
    set_ep_cost(10);
    set_sp_cost(0);
    set_hp_cost(0);
    set_duration(6);
}
do_success(me,target,result) 
{
  object fyre;
  if(!(ENV(THIS)->query_outdoors())) {
    pline("You can only create fires outside.\n");
    return 0;
  }
  else {
    pline("You gather up some leaves and branches and successfully "+
    "make a fire.\n");
    room(THIS->query_cap_name()+" gathers some leaves and sucessfully "+
    "creates a fire.\n");
    fyre = clone_object("/home/madrid/agriculture/fire.c");
    fyre->move(ENV(THIS));
    return 1;
  }
}
do_failure(me,targer,result)
{
  if(!(ENV(THIS)->query_outdoors())) {
    pline("You can only create fires outside.\n");
    return 0;
  }
  else {
    pline("You fail to create a fire.\n");
    room(THIS->query_cap_name()+" fails to create a fire.\n");
    return 1;
  }
}
