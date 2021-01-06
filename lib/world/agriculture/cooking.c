inherit "/obj/skill/obj/skill";
#define pline(x)           message("0",x,THIS);
#define room(x)            message("0",x,ENV(THIS),THIS);

mapping foods = ([ "corn" : "/home/pook/farms/items/cooked_ear_corn.c",
                   "green bean" : "",
                   "cabbage" : "",
                   "potato"  : "",
                   "carrot" : "",
                   "bean" : ""]);
create_skill()
{
    set_skill_name("cooking");
    set_train_difficulty(7);
    set_base_percent(13);
    add_base_stat("wis",40);
    add_base_stat("int",35);
    add_base_stat("dex",20);
    add_base_stat("str",5);
    set_parent_skill("upkeep");
    set_ep_cost(14);
    set_sp_cost(0);
    set_hp_cost(0);
    set_duration(4);
}

do_success(me, target, result)
{
  string *type;
  string *file;
  object obj;
  int place;
  type = keys(foods);
  file = values(foods);
  if(obj = present(target,me)) {
  if(present("fire",ENV(me))) {
    if((place = member_array(target,type)) < 0) {
      pline("That food cannot be cooked.\n");
      return 0;
    }
    else {
      pline("You make a makeshift spit and cook the "+target+"\n");
      room(me->query_cap_name()+" nimbily creates a makeshift "+
      "spit and cooks a "+target+" in it.\n");
      clone_object(file[place])->move(ENV(me));
      destruct(present(type[place],THIS));
      return 1;
    }
  }
  else {
    pline("You must have a fire in the room with you to cook "+
    "anything.\n");
    return 0;
  }
 } 
 else {
    pline("You don't have a "+target+" in your inventory.");
    return 0;
  }
}
do_failure(me,target,result)
{
  object obj;
  string *type;
  type = keys(foods);
  if(member_array(target,type) < 0) {
    pline("You cannot cook that.\n");
    return 1;
  }
  if(!(present("fire",ENV(me)))) {
    pline("You must be in a room with a fire to cook that.\n");
    return 0;
  }
  if(obj = present(target,me)) {
    pline("You try to cook a "+target+" but completely fail in "+
    "doing so, rendering it unedible.\n");
    room(me->query_cap_name()+" ruins a "+target+" trying to cook "+
    "in the fire.\n");
    destruct(obj);
  } 
  else {
    pline("You don't have a "+target+" with you.\n");
    return 0;
  }
}
