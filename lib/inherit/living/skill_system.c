#define EXP_STEP 2
#include <skill.h>

void DEBUG (string msg)
{
    object ob;
    ob=find_player("aluna");
    if(ob)
	tell_object(ob, "DEBUG: "+msg+"\n");
    return;
}

int get_skill_index(string skill_name);
int calculate_skill_base(string skill_name, int restricted);
int calculate_skill_chance(string skill_name);
void recalculate_skill_chances();
int query_skill_base(string skill_name);
int query_skill_exp(string skill_name);
int query_skill_chance(string skill_name);
int add_skill_exp(string skill_name, int exp);
string query_skill_tree();
int query_skill_result(string skill_name, int difficulty);
int do_skill(string skill_name, string target, int difficulty);
string query_skill_rank(string skill_name);
string list_skills(string arg);
void initialize_skill_tables();
object find_skill(string skill_name);
static int sk_conc, sk_duration;
static string do_name, do_target, sk_type;

mapping skillmap;
/*
  Skill Mapping
  (["skillname":({base, exp, parent, ({stat_array})}),type])
  */

string query_skill_in_use() { return do_name;}
int query_skill_duration() { return sk_duration;}
int query_skill_done() { return sk_conc;}
string query_skill_target() { return do_target;}

string switch_character(string str, string what, string towhat)
{
    string msg, *tmp;
    int i;
    msg="";
    tmp=explode(str,what);
    for (i=0;i<sizeof(tmp)-1;i++)
    {
	msg+=tmp[i]+towhat;
    }
    msg+=tmp[i];
    return msg;
}

int initialize_skillmap()
{
    skillmap=([]);
    return 1;
}

int calculate_skill_base(string skill_name, int restricted)
{
    object ob;
    int chance;
    string parent;

    if(!skillmap)
	skillmap=([]);
    if(skillmap[skill_name])
	return -1;
    ob=find_skill(skill_name);
    if(!ob)
	return -2;
    if(ob->query_is_restricted_skill(this_object())&&!restricted)
	return -3;
    if(interactive(THOB))
	parent=ob->query_parent_skill();
    else
	parent="";
    if(parent!="")
	calculate_skill_base(parent,1);
    chance=ob->calculate_skill_base(THOB);
    skillmap[skill_name]=({chance,0,ob->query_parent_skill(),
      ob->query_base_stats(),ob->query_skill_type()});
    return chance;
}

int set_skill_chance(string skill_name, int chance)
{
    object ob;
    ob=find_skill(skill_name);
    if(!ob)
	return 1;
    if(!ob)
	return -1;
    skillmap[skill_name]=({chance,0,ob->query_parent_skill(),
      ob->query_base_stats(),ob->query_skill_type()});
    return chance;
}

int query_skill_base(string skill_name)
{
    mixed dat;
    dat=skillmap[skill_name];
    if(!dat)
	return -1;
    if(dat[0]>100)
    {
	dat[0]=100;
	set_skill_chance(skill_name,100);
    }
    return dat[0];
}

int query_skill_exp(string skill_name)
{
    mixed dat;
    dat=skillmap[skill_name];
    if(!dat)
	return -1;
    return dat[1];
}

int query_skill_chance(string skill_name)
{
    int statbon,i;
    mixed *skstat, *dat;
    if(!skill_name)
	return 0;
    dat=skillmap[skill_name];
    if(!dat)
	return 0;
    skstat=dat[3];
    for(i=0;i<sizeof(skstat);i=i+2)
    {
	statbon=statbon+THOB->query_stat(skstat[i])*skstat[i+1];
    }
    statbon=(int)(statbon/500);
    if(skillmap[skill_name][2]=="")
	return query_skill_base(skill_name)+statbon;
    else
	return (query_skill_chance(skillmap[skill_name][2])+
	  query_skill_base(skill_name)+statbon)/2;
}

void update_skill(string skill_name)
{
    mixed dat;
    object ob;
    ob=find_skill(skill_name);
    if(!ob)
	return;
    dat=skillmap[skill_name];
    if(!dat||sizeof(dat)<4)
	return;
    dat[2]=ob->query_parent_skill();
    if(dat[2]&&dat[2]!="")
	update_skill(dat[2]);
    dat[3]=ob->query_base_stats();
    dat[4]=ob->query_skill_type();
    skillmap[skill_name]=({dat[0],dat[1],dat[2],dat[3],dat[4]});
    return;
}

int add_skill_exp(string skill_name, int exp)
{
    mixed dat;
    object ob;
    string parent;

    dat=skillmap[skill_name];
    if(!dat)
	return 0;
    ob=find_skill(skill_name);
    if(!ob)
	return 0;
    if(dat[0]<100)
    {
	dat[1]=dat[1]+exp;
	/* Lets check if the skill can be advanced one percent up with the exp */
	if(ob->query_advance_skill(dat[0], dat[1]))
	{
	    dat[1]=0;
	    dat[0]++;
	    update_skill(skill_name);
	}
    }
    exp=(int)(exp/EXP_STEP);
    parent=ob->query_parent_skill();
    if(parent!=""&&exp>=1)
    {
	add_skill_exp(parent, exp);
    }
    return dat[1];
}

int query_advance_exp(string skill_name)
{
    object ob;
    ob=find_skill(skill_name);
    if(!ob)
	return 0;
    return ob->query_advance_exp(query_skill_base(skill_name),query_skill_exp(skill_name));
}

static int query_fumble_number(int chance);

int query_skill_result(string skill_name, int difficulty)
{
	int exp, chance, result, base_ch;

	difficulty=difficulty+20;
	difficulty+=THOB->query_fatique_penalty();
	chance=query_skill_chance(skill_name);
	base_ch=query_skill_base(skill_name);
	if(chance==0)
		return -100;
	result=chance-random(80+difficulty);
	if(base_ch<MAX_CHANCE&&base_ch<difficulty*5)
	{
		if(result<=query_fumble_number(chance))
		{
			exp=(33+result/3); /* 0 to 33 exp */
			this_object()->add_skill_exp(skill_name, exp);
		}
		else
		if (result>chance*LEARN_DIF_MULTIPLIER)
		{
			exp=result-(chance*LEARN_DIF_MULTIPLIER); /* 0 to 33 exp */
			this_object()->add_skill_exp(skill_name, exp);
		}
    	}
    	if(result>MAX_RESULT)
		result=MAX_RESULT;
    	return result;
}

int skill_check(string skill_name)
{
    return query_skill_result(skill_name, 0);
}

static int query_fumble_number(int chance)
{
	return (int)(-89+chance-(chance/10));
}

int get_skill_success_level(string skill_name, int result)
{
    int chn;
    chn=query_skill_chance(skill_name);
    if(result<=query_fumble_number(chn))
	return -1;
    if(result<1)
	return 0;
    if(result>chn*LEARN_DIF_MULTIPLIER)
	return 2;
    return 1;
}

int do_skill(string skill_name, string target, int difficulty)
{
    int result, diff_mod, suc_lvl;
    object ob;
    ob=find_skill(skill_name);
    if(!ob)
    {
	write("No such skill / spell.\n");
	return 0;
    }
    if(!ob->query_can_use(THOB,target))
	return 0;
    diff_mod=ob->query_skill_difficulty(this_object(),target);
    if(diff_mod<MIN_DIFFICULTY)
	return -1;
    if(diff_mod>MAX_DIFFICULTY)
	diff_mod=MAX_DIFFICULTY;
    result=query_skill_result(skill_name, diff_mod);
    ob->do_skill_cost(THOB,target);
    suc_lvl=get_skill_success_level(skill_name, result);
    switch (suc_lvl)
    {
    case -1:
	ob->do_critical_failure(this_object(),target,result);
	break;
    case 0:
	ob->do_failure(this_object(),target,result);
	break;
    case 1:
	ob->do_success(this_object(),target,result);
	break;
    case 2:
	ob->do_critical_success(this_object(),target,result);
	break;
    }
    return result;
}

string query_skill_rank(string skill_name)
{
    int chance;
    chance=this_object()->query_skill_chance(skill_name);
    switch (chance)
    {
    case 0:
	return "non-existent";
    case 1..6:
	return "hopeless";
    case 7..13:
	return "pathetic";
    case 14..20:
	return "terrible";
    case 21..27:
	return "poor";
    case 28..34:
	return "incompetent";
    case 35..41:
	return "mediocre";
    case 42..48:
	return "fair";
    case 49..55:
	return "good";
    case 56..62:
	return "competent";
    case 63..69:
	return "excellent";
    case 70..76:
	return "great";
    case 77..83:
	return "superb";
    case 84..90:
	return "excuisite";
    case 91..97:
	return "awesome";
    default:
	return "legendary";
    }
}


string list_skills(string arg)
{
    int i;
    int kl=0;
    string msg;
    string *ind;
    mixed dat;
    msg="";
    if(!skillmap)
	return msg;
    if(!arg)
	arg="all";
    ind=keys(skillmap);
    ind=sort_array(ind, 1);
    msg+= sprintf ("^c0^cW^bb%-20s %-16s          %-20s %-16s^c0\n",
      "skill", "rank",
      "skill", "rank");

    for(i=0;i<sizeof(ind);i++)
    {
	dat=skillmap[ind[i]];
	if((arg=="all"||dat[4]==arg)&&dat[4]!="node"&&dat[4]!="hidden") {

	    msg+=sprintf("^c1%-20s^c0 %-16s", replace_string(ind[i],"_"," "),
	      query_skill_rank(ind[i]));
	    if(kl%2)
		msg+="\n";
	    else
		msg+="          ";
	    kl++;
	}
    }
    msg+="\n";
    return msg;
}

object find_skill(string skill_name)
{
    object ob;
    string *dir;
    int i;
    skill_name=skill_name+".c";
    dir=get_dir(SKILLDIR);
    i=member_array(skill_name, dir);
    if(i<0)
	return 0;
    ob=load_object(SKILLDIR+dir[i]);
    return ob;
}

int add_skill(string skill_name)
{
    return calculate_skill_base(skill_name,0);
}

/* query_beat_effect affects how quickly the person does the skill in question */
int query_beat_effect()
{
switch (sk_type)
{
case "truename":
			return 1;
    		case "magical":
			return 1;
    		default:
			return 1;
    	}
}

int skill_beat()
{
    string truename;
    if(!do_name||do_name=="")
	return 0;
    sk_conc+=query_beat_effect();
    if(sk_conc>=sk_duration)
    {
	if(sscanf(do_name,"truename_%s",truename)==1)
	{
	    THOB->recite_true_name(truename, do_target);
	    sk_conc=0;
	    do_name=0;
	    return 1;
	}
	do_skill(do_name, do_target, 0);
	sk_conc=0;
	do_name=0;
	return 1;
    }
    return 0;
}

int cmd_skill_use(string str)
{
    int tmp;
    object sk;
    string tm1, tm2, type;

    tmp=sscanf(str, "'%s' %s",tm1, tm2);
    if(tmp<1)
    {
	tmp=sscanf(str,"'%s'",tm1);
	if(tmp==1)
	{
	    tm2="";
	}
	else
	{
	    write("Usage: use '<skill name>' [target name]\n");
	    return 1;
	}
    }
    tm1=switch_character(tm1, " ", "_");
    sk=find_skill(tm1);
    if(!sk)
    {
	write("No such skill.\n");
	return 1;
    }
    type=sk->query_skill_type();
    if(type=="node"||type=="maneuver"||type=="hidden")
    {
	write("No such skill.\n");
	return 1;
    }
    if(query_skill_base(tm1)<1)
      calculate_skill_base(tm1,0);

    if (!sk->query_can_use(THOB, tm2))
	return 1;

    if (!sk->do_message())
    {
	write("You begin to do the skill.\n");
	say(this_object()->query_cap_name()+" begins to do something.\n");
    }

    sk_duration=sk->query_duration(this_object());
    sk_type=sk->query_true_type();
    if(tmp==1)
    {
	do_name=tm1;
	do_target="";
	sk_conc=0;
	return 1;
    }
    else
    {
	do_name=tm1;
	do_target=tm2;
	sk_conc=0;
	return 1;
    }
}

int begin_true_name(string truename, string target)
{
    string *words;
    int dura;
    if(!truename)
	return 0;
    words=explode(truename,"-");
    dura=sizeof(words)-2;
    if(dura<1)
	dura=1;
    sk_conc=0;
    sk_type="truename";
    do_name="truename_"+truename;
    do_target=target;
    sk_duration=dura;
    return 1;
}

void _clear_skillmap()
{
    skillmap=([]);
}

mapping dump_skillmap() { return skillmap;}



