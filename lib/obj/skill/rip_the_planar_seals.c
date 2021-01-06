inherit "obj/skill/obj/skill";
#include <spell.h>

create_skill()
{
    set_skill_name("rip_the_planar_seals");
    set_train_difficulty(15);
    set_base_percent(0);
    add_base_stat("pow",40);
    add_base_stat("wis",40);
    add_base_stat("int",20);
    set_parent_skill("primal_evil");
    set_ep_cost(100);
    set_sp_cost(100);
    set_hp_cost(20);
    set_duration(30);
    set_skill_duration(0);
    set_restricted(1);
}

do_success(me, target, result)
{
    int interval;
    int amount;
    int power;

    write("You draw a pentagram to the ground, light a candle to each end of the pentagram "
    + "and start a horrific ritual. You can feel the planar seals destroying and hear "
    + "distant whispers calling your name. You hear distant screams as the demons from "
    + "other planes slaughter the people");

    message("0","You can feel that something supernatural and extremly evil is "
    + "about to happen!\n",users(),THIS);

    me->add_alignx(-200);
    me->add_aligny(-400);

    interval=150-me->query_skill_chance("rip_the_planar_seals");
    amount=5+me->query_skill_chance("rip_the_planar_seals")/5;

    call_out ("summon_demon", interval, ({me, amount,interval}));
}

do_failure(me, target, result)
{
    object demoni;

    write("You draw a pentagram to the ground, light a candle to each end of the pentagram "
    + "and start a horrific ritual. But the you feel something went wrong and a portal "
    + "to deepest abyss opens and a horde of demon enter the room!\n");
    for (int i=0; i< 5+random(10); i++)
    {
        demoni=clone_object("/home/dranil/demon.c");
        demoni->move(ENV(THIS));
        demoni->begin_battle(THIS);
    }

    return 1;
}

summon_demon(mixed *args)
{
    int i=random(sizeof(users()));
    object demoni;

    if (users()[i]!=args[0])
    {
        message("0","An interplanar portal opens in front of you and a hideous demon "
        + "steps out of it!\n",ENV(users()[i]));
        demoni=clone_object("/home/dranil/demon.c");
        demoni->move(ENV(users()[i]));
        demoni->begin_battle(users()[i]);
    }
    if (args[1] >0)
    {
        call_out("summon_demon",args[2],({args[0],args[1]-1,args[2]}));
        return 1;
    }
    message("","You feel the planar seals close.\n",args[0]);
    return 1;
}


