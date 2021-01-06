/* maneuver.c
   Coder: aluna
   */
#include <skill.h>
#include <battle.h>

#define LEGALSTAT ({"str","dex","agi","con","siz","pow","int","wis","cha"})
#define TUNEMOD 1
#define BATTLESTATTER "/obj/battle/statter"
int restricted, base_percent;
string *base_stat;
string parent;
string name;
string type;
string *weapon_type;
string extra_help;

int *per, train_diff;

int man_damage;           /* Deadliness of the maneuver */
int man_defense;          /* Defense ability of the maneuver */
int man_fatique;          /* How much the maneuver fatiques the performer */
int man_offense;          /* Hitting ability of the maneuver */
int man_protection;       /* Protectiveness of the maneuver */
int man_speed;            /* How quick the maneuver is to perform */
int damage_type;

static int unarmed;	/* This is set to 1 if the maneuver is a martial arts maneuver */

void create()
{
    restricted=1;
    base_percent=5;
    train_diff=100;

    name="combat maneuver";
    type="maneuver";

    man_damage=1;
    man_defense=1;
    man_fatique=1;
    man_offense=1;
    man_protection=1;
    man_speed=1;
    damage_type=0;

    base_stat=({});
    parent="";
    per=({});
    weapon_type=({"martial_arts"});

    this_object()->create_skill();
    /* insert Maneuver Checking here */
}

int set_damage(int i) { return man_damage=i;}
int set_defense(int i){  return man_defense=i;}
int set_fatique(int i){  return man_fatique;}
int set_offense(int i){  return man_offense=i;}
int set_protection(int i){  return man_protection=i;}
int set_speed(int i){  return man_speed=i;}

int set_unarmed(int i) { unarmed=i;}
int query_is_unarmed() { return unarmed;}

int *query_damage() 
{ 
    return ({ man_damage*DAMAGEMOD, damage_type});
}
int query_defense() { return man_defense*DEFENSEMOD;}
int query_fatique() { return man_fatique*FATIQUEMOD;}
int query_offense() { return man_offense*OFFENSEMOD;}
int query_protection() { return man_protection*PROTECTIONMOD;}
int query_speed() { return man_speed*SPEEDMOD;}

void reset (int arg)
{
}

/* What the variables do:
   restricted: This cannot be learned without teaching from someone.
   train_difficulty: This affects how difficult the skill is to learn. 
   (more /obj/skill/TRAINING_DIFF)
   duration: Affects how long it takes to activate the skill
   skill_duration: Affects how long the skill with be active
   skill_power: Affects the power level of the skill
   */

int set_restricted(int i) { return restricted=i;}
int set_base_percent(int i) { return base_percent=i;}
int set_train_difficulty(int i) { return train_diff=i;}

int query_is_restricted() { return restricted;}
int query_base_percent() { return base_percent;}
int query_train_difficulty() { return train_diff;}

string query_true_type()
{
    object ob;
    if(parent=="")
	return "node";
    if(parent=="skill_root")
	return name;
    ob=load_object(SKILLDIR+parent);
    if(ob)
	return ob->query_true_type();
    else
	return name;
}
/* What these variables do:
   name: the name of the skill. This is usually the file name of the skill.
   parent: the name of the parent skill in the skill tree.
   type: this variable can be used to store miscellaneous information.
   Examples: hidden, node, maneuver and so on.
   */

string set_skill_name(string s) { name=s;}
string set_parent_skill(string s) { parent=s;}

int set_weapon_types(mixed wtype)
{
    if(arrayp(wtype))
    {
	if(member_array("martial_arts",wtype)>=0)
	    set_unarmed(1);
	weapon_type=wtype;
    }
    else
    {
	weapon_type=({wtype});
	if(wtype=="martial_arts")
	    set_unarmed(1);
    }
    return sizeof(weapon_type);
}

string *query_weapon_types()
{
    return weapon_type;
}

int query_wield_limbs() { return 1;}

string query_skill_name() { return name;}
string query_parent_skill() { return parent;}
string query_handling_type()
{
    if(unarmed)
	return "martial_arts";
    return "not martial";
}

string query_skill_type()
{
    if(!type)
	type=query_true_type();
    return type;
}

void do_skill(object me, string target, int result)
{
    write("This skill is a combat maneuver. They are used with maneuver command.\n");
    return;
}

void do_critical_failure(object me, string target, int result)
{
    this_object()->do_skill(me, target, result);
}

void do_failure(object me, string target, int result)
{
    this_object()->do_skill(me,target,result);
}

void do_success(object me, string target, int result)
{
    this_object()->do_skill(me,target,result);
}

void do_critical_success(object me,string target,int result)
{
    this_object()->do_skill(me,target,result);
}

void add_base_stat(string base, int percent)
{
    if(member_array(base,LEGALSTAT)<0)
	return;
    base_stat+=({base});
    per+=({percent});
}

void list_base_stats()
{
    int i;
    for(i=0;i<sizeof(base_stat);i++)
	write(base_stat[i]+":"+per[i]+"\n");
    return;
}

mixed query_base_stats()
{
    int i;
    mixed arr;
    arr=({});
    for (i=0;i<sizeof(base_stat);i++)
	arr+=({base_stat[i],per[i]});
    return arr;
}

int calculate_skill_base (object who)
{
    int i, val;
    float sum;
    return base_percent;

    /* This function calculates base chance of the  skill for object who.
	    The function uses natural stat values for calculations.
    */

    for(i=0;i<sizeof(base_stat);i++)
    {
	switch (base_stat[i])
	{
	case "str":
	    sum+=who->query_str()*per[i];
	    break;
	case "dex":
	    sum+=who->query_dex()*per[i];
	    break;
	case "con":
	    sum+=who->query_con()*per[i];
	    break;
	case "siz":
	    sum+=who->query_siz()*per[i];
	    break;
	case "int":
	    sum+=who->query_int()*per[i];
	    break;
	case "wis":
	    sum+=who->query_wis()*per[i];
	    break;
	case "pow":
	    sum+=who->query_pow()*per[i];
	    break;
	case "cha":
	    sum+=who->query_cha()*per[i];
	    break;
	case "agi":
	    sum+=who->query_agi()*per[i];
	    break;
	}
    }
    val=base_percent+(int)(sum/(200*i));
    return val;
}

int query_advance_skill(int bas, int exp)
{
    if(train_diff*bas*TUNEMOD<exp)
	return 1;
    return 0;
}
int query_advance_exp(int bas, int exp)
{
    return (train_diff*bas*TUNEMOD-exp);
}

string handle_location(string location, object who)
{
    string side, tmp_loc;
    int tmp;
    tmp=sscanf(location,"%s %s",side, tmp_loc);
    tmp=who->query_separate_location(tmp_loc);
    if(tmp)
	return location;
    else
	return tmp_loc;
}

void do_combat_msg(object attacker, object defender)
{
    if(random(8))
	return;
    if(attacker)
	tell_room(environment(attacker),
	  "Some coder has forgotten to code good descriptions for "+
	  THOB->query_skill_name()+".\n",
	  ({}));
}

void do_maneuver_msg(object target, object attacker, object weapon, 
  string location, int offres, int defres, int dmgres, int hitres, int type)
{
    /* target: target object
       attacker: attacker object
       weapon: weapon object / martial arts maneuver object
       location: location to be hit
       offres: how well the attacker attacks (-120 to 120)
       defres: how well the target defends (-120 to 120)
       dmgres: how much damage the target suffers (1+)
       hitres: is positive is target is hit.
       type: type of incoming damage
       */
    tell_room(environment(attacker),
      "Some coder has forgotten to code descriptions for "+
      THOB->query_skill_name()+"!\n");
}

int wield_legality_check(object *wielded, object wielder)
{
    string *types, type, def;
    int i;
    types=({});
    for (i=0;i<sizeof(wielded);i++)
	types+=({wielded->query_handling_type()});
    types=sort_array(types,1); /* Alphabetical order */
    type=implode(types,"_and_");
    if(member_array(type, weapon_type)<0)
    {
	def=BATTLESTATTER->query_default_maneuver(type);
	if(def=="illegal_combination")
	{
	    tell_object(wielder,
	      "You have no idea how to wield this weapon "+
	      "combination.\n");
	    return 0;
	}
	tell_object(wielder,
	  "Your weapon combination cannot be used with "+
	  THOB->query_skill_name()+". Changing to "+def+".\n");
	return 0;
    }
    return 1;
}

int legality_check(object attacker, object weapon, object target)
{
    return 1;
}

string set_help(string s) { return extra_help=s;}

string query_help()
{
    string msg;
    string *value;
    if(extra_help)
	msg=extra_help;
    else
	msg="";
    msg+="Skill type: "+THOB->query_skill_type();
    return msg;
}

string query_type() { return type;}
