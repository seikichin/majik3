/* Battle object */
#define HITDMGMOD (1/4)
inherit BASE;

void DEBUG(string str)
{
  object ob;
  ob=find_player("aluna");
  if(ob)
    tell_object(ob, str+"\n");
}

#define BODYTYPE 0
#define HEIGHT 1
#define GROUP 2
#define WEAPONS 3
#define MANEUVER 4
#define MANCOUNT 5
mapping combatant;

create()
{
    combatant=([]);
}

id(str) { return (str=="BATTLEMASTER");}

int add_combatant(object who)
{
    if(sizeof(combatant)<1)
	combatant=([]);
    if(!who||who->query_is_dead())
	return 0;
    combatant[file_name(who)]=
    ({who->query_bodytype(),
      who->query_height(),
      0});
    return 1;
}

init()
{
    add_action("check_combatants","battlecheck");
}

void self_destruct()
{
    destruct(this_object());
}

int check_combatants()
{
    object ob, *all;
    string *combs, *files, fn;
    int i;
    combs=keys(combatant);
    files=({});
    all=all_inventory(environment(THOB));
    for (i=0; i<sizeof(all);i++)
      {
	fn=file_name(all[i]);
	if((!all[i]->query_target()||all[i]->query_is_dead()) && member_array(fn, combs)>=0)
	  map_delete(combatant, fn);
	else
	  files+=({fn});
      }
    for (i=0; i < sizeof(combs); i++)
    {
      if(member_array(combs[i],files)<0)
	{
	  map_delete(combatant, combs[i]);
	}
    }
    if(sizeof(combatant)<2)
	self_destruct();
    return 1;
}

int remove_combatant(object who)
{
    mixed *dat;
    if(!who)
	return 0;
    map_delete(combatant, file_name(who));
    if(sizeof(combatant)<2)
    {
	self_destruct();
    }
    return 1;
}

string query_connected_location(string type, string location)
{
    mapping connections;
    int rnd;
    string *dat;
    switch (type)
    {
    case "humanoid":
    default:
	connections=(["head":({"head","neck","ear"}),
	  "ear":({"head"}),
	  "neck":({"chest","head","neck"}),
	  "chest":({"chest","stomach","shoulder","neck"}),
	  "shoulder":({"upper arm","chest"}),
	  "upper arm":({"shoulder","elbow"}),
	  "elbow":({"forearm","upper arm"}),
	  "forearm":({"elbow","wrist"}),
	  "wrist":({"hand","forearm"}),
	  "hand":({"finger","wrist"}),
	  "finger":({"hand"}),
	  "stomach":({"stomach","hip","chest"}),
	  "hip":({"stomach","thigh","hip"}),
	  "thigh":({"hip","knee"}),
	  "knee":({"thigh","shin"}),
	  "shin":({"ankle","knee"}),
	  "ankle":({"foot","shin"}),
	  "foot":({"ankle"})]);
    }
    dat=connections[location];
    if(!dat||sizeof(dat)<1)
	return "none";
    rnd=random(sizeof(dat));
    return dat[rnd];
}

string *query_severed_connection (string type, string location)
{
    mapping connections;
    int rnd;
    string *dat;
    switch (type)
    {
    case "humanoid":
    default:
	connections=(["head":({"neck"}),
	  "ear":({""}),
	  "neck":({"chest"}),
	  "chest":({"stomach","shoulder"}),
	  "shoulder":({"upper arm"}),
	  "upper arm":({"elbow"}),
	  "elbow":({"forearm"}),
	  "forearm":({"wrist"}),
	  "wrist":({"hand"}),
	  "hand":({"finger"}),
	  "finger":({}),
	  "stomach":({"hip"}),
	  "hip":({"thigh"}),
	  "thigh":({"knee"}),
	  "knee":({"shin"}),
	  "shin":({"ankle"}),
	  "ankle":({"foot"}),
	  "foot":({""})]);
    }
    dat=connections[location];
    if(!dat||sizeof(dat)<1)
	return ({""});
    return dat;
}

string query_bodytype(object who)
{
    mixed dat;
    string name;
    if(!who)
	return "humanoid";
    dat=combatant[file_name(who)];
    if(!dat)
	return "humanoid";
    return dat[BODYTYPE];
}

int query_height(object who)
{
    mixed dat;
    string name;
    if(!who)
	return 0;
    dat=combatant[file_name(who)];
    if(!dat)
	return 0;
    return dat[HEIGHT];
}

string *query_location_names(string type)
{
    /* These are listed from up to down and are in same order as
       location sizes below */

    switch (type)
    {
    case "humanoid":
    default:
	return ({"head","ear", "neck",
	  "chest","shoulder","upper arm",
	  "stomach","elbow","forearm",
	  "wrist","hip","thigh",
	  "hand","finger","knee",
	  "shin","ankle","foot"});
    }
}

int *query_location_sizes(string type)
{
    switch (type)
    {
    case "humanoid":
    default:
	return ({25,5,10,
	  35,15,25,
	  20,10,20,
	  5, 10,25,
	  10, 5,10,
	  15,10, 5});
    }
}

int query_total_size(string type)
{
    switch (type)
    {
    case "humanoid":
    default:
	return 260;
    }
}

string query_random_hit_location(object attacker, object defender, string attack_side)
{
    int a_height, d_height, diff, *loc_size, rnd, tot_size;
    int idx;
    string side, d_type, *loc_name;
    a_height=query_height(attacker);
    d_height=query_height(defender);
    d_type=query_bodytype(defender);
    loc_name=query_location_names(d_type);
    loc_size=query_location_sizes(d_type);
    tot_size=query_total_size(d_type);
    diff=(a_height-d_height)/20; /* each 20 cm of height difference modifies by 1 */
    rnd=-1;
    idx=-1;
    while (rnd<=0||rnd>=tot_size)
	rnd=random(tot_size-diff);
    while (rnd>0)
    {
	idx++;
	rnd=rnd-loc_size[idx];
    }
    if(random(3))
    {
	if(attack_side=="left")
	    side="right";
	else
	{
	    attack_side="right";
	    side="left";
	}
    }
    else
    {
	side=attack_side;
    }
    return side+" "+loc_name[idx];
}

int abs(int x) { if (x>=0) {return x;} else return -x;}

int perform_maneuver(object weapon, object target, object maneuver, int offres, int manres, 
  int offmod, int dammod, string side, int type)
{
    object attacker;
    string location;
    int defres, prores, defmod, promod, *dat;
    int hitres, dmgres, maxdmg, w_dmg_mod, exp, alm;

    attacker=previous_object();
    if(!attacker||!target||!maneuver||!weapon)
	return 0;
    /*
    if(!maneuver->legality_check(attacker, weapon, target))
    {
	return 0;
    }
    */
    location=query_random_hit_location(attacker, target, side);
    dat=target->defense_check(location, type);
    defres=dat[0];
    prores=dat[1];
    defmod=dat[2];
    promod=dat[3];
    maxdmg=dat[4];
    hitres=(offres*(100+offmod/100))-(defres*(100+defmod/100));
    dmgres=(hitres*HITDMGMOD+manres-prores)*(100+dammod-promod)/100;
    if(dmgres<1)
	dmgres=1;
    else
    if(dmgres>maxdmg)
	dmgres=maxdmg;
    maneuver->do_maneuver_msg(target, attacker, weapon, location, 
			      offres, defres, dmgres, hitres, prores, type);
    if(hitres>0)
    {
	target->damage_location(attacker, location, dmgres, type);
	target->add_hp(-dmgres);
        if(target && target->query_is_dead())
        {
          target->add_dexp(1);
          if ((attacker->query_alignx() >= 0 && target->query_alignx() >= 0) ||
              (attacker->query_alignx() <= 0 && target->query_alignx() <= 0))
            {
              exp -= (abs(attacker->query_alignx())+abs(target->query_alignx()))/10;
            }
          else
            {
              exp += (abs(attacker->query_alignx())+abs(target->query_alignx()))/10;
            }

          exp += random(100) + (target->query_level()*100);

          if (target->query_alignx() < 0)
            alm += -((target->query_alignx()/20));
          else if (target->query_alignx() > 0)
            alm -= target->query_alignx()/20;

          attacker->add_alignx (alm);

          if (target->query_subrace())
            attacker->add_kexp(exp, target->query_subrace());
          else
            attacker->add_kexp(exp, target->query_race());

          if (!interactive (target))
            destruct (target);
        }
	if(!target || target->query_is_dead())
	{
	  check_combatants();
	}
    }
    return 1;
}

static int do_real_cripple(object who, string bodytype, string side, string location)
{
    string *dat;
    int i;
    dat=query_severed_connection(bodytype, location);
    for (i=0; i<sizeof(dat); i++)
    {
	if(dat[i]!="")
	{
	    who->do_cripple(side, dat[i]);
	    do_real_cripple(who, bodytype, side, dat[i]);
	}
    }
    return 1;
}

void do_cripple(string bodytype, string side, string location)
{
    do_real_cripple(previous_object(),bodytype,side,location);
}

static int do_real_lose(object who, string bodytype, string side, string location)
{
    string *dat;
    int i;
    dat=query_severed_connection(bodytype, location);
    for (i=0; i<sizeof(dat); i++)
    {
	if(dat[i]!="")
	{
	    who->do_lose(side, dat[i]);
	    do_real_lose(who, bodytype, side, dat[i]);
	}
    }
    return 1;
}

void do_lose(string bodytype, string side, string location)
{
    object o;

    o = clone_object(ITEM);
    o->set_short ("a "+(({ "severed", "bloody", "dislodged",
      "mutilated", "torned" })[random(5)])+" "+location+" of "+
      article(previous_object()->query_race())+"");
    o->set_long ("This is a "+
      previous_object()->query_maybe_cap_name()+"'s bodypart.\n");
    o->set_material ("flesh");
    o->set_dimensions (random(10), random(10), random(10));
    o->set_no_autoload (1);
    o->move (ENV(THOB));

    do_real_lose(previous_object(),bodytype,side,location);
}

string short() { return "BATTLEMASTER";}
void long() { write("If you see this after fight, inforn Aluna about it.\n");}
