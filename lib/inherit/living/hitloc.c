/* Health conditions */
#define BATTLESTATTER	"/obj/battle/statter"
#define BATTLEMASTER_OB "/obj/battle/master"

#include "/include/battle.h"
#define OK		1
#define CRIPPLED	0
#define LOST		-1

/* location_map data locations */
#define LEFTHIT		0
#define RIGHTHIT	1
#define LEFTCOND	2
#define RIGHTCOND	3
#define MAXPERCENT	4
#define SEPARATE	5
#define CONNECTION	6

/* weapon_map data locations */
#define WPOBJ		0
#define WPCOUNT		1

/* Battle variables */
#define AVG_SPD		120
#define UNCONDEF	-50
#define UNCONPROT	-50
#define UNCONSKILLRES	-120

DEBUG(string str)
{
  object ob;
  ob=find_player("namhas");
  if(ob)
    tell_object(ob,str);
}

static mapping armour_map;  /* location : armour_ob */
static mapping weapon_map;  /* location : ({weapon_ob, counter}) */
mapping location_map;
string bodytype;
string maneuver_name;

static object battle;
static object *enemy;
static string the_enemy;
object set_battle_object(object o) { return battle=o;}
object query_battle_object() { return battle;}

static int armour_damage, armour_defense, armour_fatique, armour_offense, armour_speed;
static int weapon_defense, weapon_fatique, weapon_protection;
static int maneuver_damage, maneuver_defense, maneuver_fatique;
static int maneuver_offense, maneuver_protection, maneuver_speed;

int query_armour_damage() { return armour_damage*DAMAGEMOD;}
int query_armour_defense() { return armour_defense*DEFENSEMOD;}
int query_armour_fatique() { return armour_fatique*FATIQUEMOD;}
int query_armour_offense() { return armour_offense*OFFENSEMOD;}
int query_armour_speed() { return armour_speed*SPEEDMOD;}
int query_armour_protection(string location, int type)
{
  object arm;
  arm=armour_map[location];
  if(!arm)
    return THOB->query_naked_protection();
  return arm->query_protection(type);
}

object *query_worn_armour()
{
  return values(armour_map);
}

int query_weapon_defense() { return weapon_defense*DEFENSEMOD;}
int query_weapon_fatique() { return weapon_fatique*FATIQUEMOD;}
int query_weapon_protection() { return weapon_protection*PROTECTIONMOD;}

object *query_wielded_weapon()
{
  mixed *dat, *tmp;
  int i;
  object *ret;
  dat=values(weapon_map);
  ret=({});
  for (i=0;i<sizeof(dat); i++)
    {
      tmp=dat[i];
      if(objectp(tmp[0]))
	ret+=({tmp[0]});
    }
  return ret;
}

static int query_maneuver_modifier(int mod)
{
  int chance;
  if(!mod)
    return 0;
  chance=THOB->query_skill_chance(maneuver_name);
  if(mod<0)
    return 0-mod-(mod*chance/100);
  return mod*chance/100;
}

int query_maneuver_damage() { return query_maneuver_modifier(maneuver_damage);}
int query_maneuver_defense() { return query_maneuver_modifier(maneuver_defense);}
int query_maneuver_fatique() { return query_maneuver_modifier(maneuver_fatique);}
int query_maneuver_offense() { return query_maneuver_modifier(maneuver_offense);}
int query_maneuver_protection() { return query_maneuver_modifier(maneuver_protection);}
int query_maneuver_speed() { return query_maneuver_modifier(maneuver_speed);}

int *query_damage(object weapon)
{
  int *dat;
  if(!weapon)
    dat= ({0,0});
  else
    dat=weapon->query_damage();
  return ({(int)((query_armour_damage()+query_maneuver_damage()+dat[0])/3),dat[1]});
}

int query_defense()
{
  int a_def, m_def, w_def;
  a_def=query_armour_defense();
  if(THOB->query_is_unconscious())
    {
      m_def=UNCONDEF;
      w_def=UNCONDEF;
    }
  else
    {
      m_def=query_maneuver_defense();
      w_def=query_weapon_defense();
    }
  return (int)((a_def+m_def+w_def)/3);
}

int query_fatique()
{
  return (int)((query_armour_fatique()+
		query_maneuver_fatique()+
		query_weapon_fatique())/3);
}

int query_offense(object weapon)
{
  if(!weapon)
    return 0;
  return (int)((query_armour_offense()+
		query_maneuver_offense()+
		weapon->query_offense())/3);
}

int query_protection(string location, int type)
{
  int a_prot, m_prot, w_prot;
  a_prot=query_armour_protection(location,type);
  if(THOB->query_is_unconscious())
    {
      m_prot=UNCONPROT;
      w_prot=UNCONPROT;
    }
  else
    {
      m_prot=query_maneuver_protection();
      w_prot=query_weapon_protection();
    }
  return (int)((a_prot+m_prot+w_prot)/3);
}

int query_speed()
{
  return (query_armour_speed()+query_maneuver_speed());
}

void initialize_hit_locations();

string set_bodytype(string type) 
{
  switch (type)
    {
    case "humanoid":
    default:
      bodytype="humanoid";
    }
  initialize_hit_locations();
  return bodytype;
}
string query_bodytype() { return bodytype;}
string query_maneuver() { return maneuver_name;}
string set_maneuver(string s)
{
  object ob;
  int *dat;
  ob=THOB->find_skill(s);
  if(!ob||ob->query_type()!="maneuver")
    {
      tell_object(THOB,
		  s+" is not a legal maneuver.\n");
      return maneuver_name;
    }
  maneuver_name=s;
  dat=ob->query_damage();
  maneuver_damage=dat[0];
  maneuver_defense=ob->query_defense();
  maneuver_fatique=ob->query_fatique();
  maneuver_offense=ob->query_offense();
  maneuver_protection=ob->query_protection();
  maneuver_speed=ob->query_speed();
  return maneuver_name;
}

static void bring_out_your_dead()
{
  object o, *tmp;
  tmp=({});
  if(sizeof(enemy)<1)
    return;
  foreach (o in enemy)
    {
      if(o)
	tmp+=({o});
    }
  enemy=tmp;
  return;
}

int set_enemy(object enemy_object)
{
  if(!enemy)
    {
      enemy=({});
    }
  if(!the_enemy)
    the_enemy=enemy_object->query_name();
  if(member_array(enemy_object,enemy)>=0)
    return 0;
  if(enemy_object==THOB)
    return 0;
  enemy+=({enemy_object});
  bring_out_your_dead();
  return 1;
}

string set_target(string enemy_name)
{
  object ob;
  ob=present(enemy_name, environment(THOB));
  if(!ob)
    return the_enemy;
  return the_enemy=enemy_name;
}

object query_target()
{
  object *p_enemy, ob, env;
  int i;
  p_enemy=({});
  bring_out_your_dead();
  env=environment(THOB);
  ob=present(the_enemy,environment(THOB));
  if(ob&&!ob->query_is_dead())
    return ob;
  for (i=0;i<sizeof(enemy);i++)
    {
      if(enemy[i]&&env==environment(enemy[i]))
	p_enemy+=({enemy[i]});
    }
  if(sizeof(p_enemy)<1)
    return 0;
  return p_enemy[random(sizeof(p_enemy))];
}

int add_armour(object armour)
{
  string *slot, *all;
  int i;
  armour->set_is_worn(1);
  all=keys(armour_map);
  slot=armour->query_armour_slots();
  for (i=0;i<sizeof(slot); i++)
    {
      if(armour_map[slot[i]])
	{
	  tell_object(THOB,
		      "You cannot wear "+armour->short()+" over "+
		      armour_map[slot[i]]->short()+".\n");
	  return 0;
	}
      if(member_array(slot[i],all)<0)
	{
	  tell_object(THOB,
		      "You don't have a "+slot[i]+" to wear "+
		      armour->short()+" in.\n");
	  return 0;
	}
    }
  for (i=0;i<sizeof(slot); i++)
    armour_map[slot[i]]=armour;
  return 1;
}

int add_weapon(object weapon)
{
  int slots, i, free;
  string *loc;
  mixed *dat;
  weapon->set_is_worn(1);
  slots=weapon->query_wield_limbs(THOB);
  loc=keys(weapon_map);
  for (i=0; i<sizeof(loc); i++)
    {
      dat=weapon_map[loc[i]];
      if(!dat[WPOBJ]||dat[WPOBJ]->query_type()=="maneuver")
	free++;
    }
  if(free<slots)
    {
      tell_object(THOB,
		  "You do not have enough free limbs to wield "+
		  weapon->short()+".\n");
      return 0;
    }
  i=0;
  for (i=0;i<sizeof(loc);i++)
    {
      dat=weapon_map[loc[i]];
      if(!dat[WPOBJ]||dat[WPOBJ]->query_type()=="maneuver")
	{
	  slots=slots-1;
	  weapon_map[loc[i]]=({weapon, 0});
	  if(slots<=0)
	    break;
	}
    }
  return 1;
}

void update_worn_armour()
{
  object *all, ob, *arm;
  int *dat;
  all=all_inventory(THOB);
  foreach (ob in all)
    {
      if(ob->query_is_worn()&&ob->query_is_armour())
	add_armour(ob);
    }
  arm=values(armour_map);
  dat=BATTLESTATTER->armour_update_request(arm, 
					   THOB->query_naked_defense(),
					   THOB->query_naked_fatique(),
					   THOB->query_naked_offense(),
					   THOB->query_naked_speed(),
					   THOB->query_naked_damage());
  armour_defense=dat[0];
  armour_offense=dat[1];
  armour_speed=dat[2];
  armour_fatique=dat[3];
  armour_damage=dat[4];
}

int set_weapon_map();
void update_wielded_weapon()
{
  object *all, ob, *wpn;
  int *dat, i;
  mixed *md, *tmd;
  string *loc, type;
  all=all_inventory(THOB);
  if(!maneuver_name)
    maneuver_name="brawlers_punch";
  set_weapon_map();
  foreach (ob in all)
    {
      if(ob->query_is_worn()&&ob->query_is_weapon())
	add_weapon(ob);
    }
  loc=keys(weapon_map);
  ob=THOB->find_skill(maneuver_name);
  if(ob&&ob->query_handling_type()=="martial_arts")
    {
      for (i=0; i<sizeof(loc);i++)
	{
	  dat=weapon_map[loc[i]];
	  if(!dat[0])
	    {
	      
	      weapon_map[loc[i]]=({ob,0});
	    }
	}
    }
  wpn=query_wielded_weapon();
  if(sizeof(wpn)<1)
    {
      maneuver_name="brawlers_punch";
      update_wielded_weapon();
      return;
    }
  dat=BATTLESTATTER->weapon_update_request(wpn);
  weapon_defense=dat[0];
  weapon_fatique=dat[1];
  weapon_protection=dat[2];
}

int set_weapon_map()
{
  switch (bodytype)
    {
    case "humanoid":
    default:
      weapon_map=(["left hand":({0,0}), "right hand":({0,0})]);;
    }
}

void initialize_hit_locations()
{
  int i;
  string *loc;
  switch (bodytype)
    {
    case "humanoid":
    default:
      location_map=([
		     "head":({1,1,OK,OK,40,0,""}),
		     "ear":({1,1,OK,OK,5,1,"head"}),
		     "neck":({1,1,OK,OK,15,1,"head"}),
		     "chest":({1,1,OK,OK,50,0,"neck"}),
		     "shoulder":({1,1,OK,OK,25,1,"chest"}),
		     "upper arm":({1,1,OK,OK,25,1,"shoulder"}),
		     "elbow":({1,1,OK,OK,20,1,"upper arm"}),
		     "forearm":({1,1,OK,OK,25,1,"elbow"}),
		     "wrist":({1,1,OK,OK,15,1,"forearm"}),
		     "hand":({1,1,OK,OK,20,1,"wrist"}),
		     "finger":({1,1,OK,OK,5,1,"hand"}),
		     "stomach":({1,1,OK,OK,45,0,"chest"}),
		     "hip":({1,1,OK,OK,30,0,"stomach"}),
		     "thigh":({1,1,OK,OK,45,1,"hip"}),
		     "knee":({1,1,OK,OK,30,1,"thigh"}),
		     "shin":({1,1,OK,OK,35,1,"knee"}),
		     "ankle":({1,1,OK,OK,20,1,"shin"}),
		     "foot":({1,1,OK,OK,25,1,"ankle"})]);
      break;
    }
  set_weapon_map();
  loc=keys(location_map);
  armour_map=([]);
  for (i=0;i<sizeof(loc);i++)
    {
      armour_map["left "+loc[i]]=0;
      armour_map["right "+loc[i]]=0;
    }
  update_worn_armour();
  update_wielded_weapon();
  return;
}

static int query_parry_result()
{
  object *wpn;
  int i, sum;
  mixed dat;
  wpn=values(weapon_map);
  for (i=0; i<sizeof(wpn);i++)
    {
      dat=wpn[i];
      sum+=THOB->query_skill_result(dat[WPOBJ]->query_handling_type()+"_parry");
    }
  sum=(int)(sum/sizeof(wpn));
  return sum;
}
int query_location_max_hits(string location);
int *defense_check(string location, int type)
{
  int defres, prores, defmod, promod, i;
  string tmp;

  if(!THOB->query_is_unconscious())
    {
      defres=THOB->query_skill_result("dodge");
      prores=query_parry_result();
    }
  else
    {
      defres=UNCONSKILLRES;
      prores=UNCONSKILLRES;
    }
  defmod=query_defense();
  promod=query_protection(location, type);
  sscanf(location,"%s %s",tmp,location);
  return ({defres, prores, defmod, promod, 2*query_location_max_hits(location)});
}

int query_location_max_hits(string location)
{
  int *dat, max;
  if(!location)
    return 0;
  max=THOB->query_max_hp();
  if(max<1)
    return 0;
  dat=location_map[location];
  return max*dat[MAXPERCENT]/100;
}

int query_location_hits(string location)
{
  int *dat;
  string side;
  sscanf(location,"%s %s",side,location);
  if(!dat)
    return 0;
  if(side=="left")
    return dat[LEFTHIT];
  return dat[RIGHTHIT];
}

int query_location_condition(string location)
{
  int *dat, max;
  string side;
  sscanf(location,"%s %s",side, location);
  dat=location_map[location];
  if(!dat)
    return -2;
  max=query_location_max_hits(location);
  if(side=="left")
    return (int)(100*dat[LEFTHIT]/max);
  else
    return (int)(100*dat[RIGHTHIT]/max);
}

static int query_location_status(string side, string location)
{
  mixed *dat;
  int idx;
  if(side!="left"&&side!="right")
    return LOST;
  if(side=="left")
    idx=LEFTCOND;
  else
    idx=RIGHTCOND;
  dat=location_map[location];
  if(!dat||sizeof(dat)<idx+1)
    return LOST;
  return dat[idx];
}

string query_health_status(string location)
{
  mixed *dat;
  int tmp, loc_hp, loc_max, per;
  string side;
  if(!location)
    return "none";
  tmp=sscanf(location,"%s %s",side, location);
  if(tmp<2||side!="left"&&side!="right")
    return "none";
  if(side=="left")
    tmp=LEFTHIT;
  else
    tmp=RIGHTHIT;
  loc_max=query_location_max_hits(location);
  loc_hp=query_location_hits(side+" "+location);
  dat=location_map[location];
  if(dat[tmp+2]==OK)
    {
      if(dat[tmp]<loc_max)
        {
          per=100*loc_hp/loc_max;
          switch (per)
            {
            case 100..90:
              return "scratched";
            case 89..70:
              return "hurt ";
            case 69..50:
              return "pained";
            case 49..30:
              return "very hurt";
            case 29.. 10:
              return "weak";
            default:
              return "almost crippled";
            }
        }
      else
        return "healthy";
    }
  else
    {
      if(dat[tmp+2]==CRIPPLED)
        {
          if(dat[tmp]<0)
            return "crippled";
          else
            return "incapacitated";
        }
      else
        return "lost";
    }
  return "buggy";
}

string query_total_health_status()
{
  int i;
  string *loc, msg;
  msg=sprintf("^c1%-20s^c0 %15s %-15s","Location","Left","Right\n\n");
  loc=BATTLEMASTER_OB->query_location_names(bodytype);
  for (i=0; i<sizeof(loc);i++)
    {
      msg+=sprintf("^c1%-20s^c0 %15s %-15s",
                   loc[i],
                   query_health_status("left "+loc[i]),
                   query_health_status("right "+loc[i]));
      msg+="\n";
    }
  return msg;
}


int heal_location(string location, int amount)
{
  string side;
  mixed *dat;
  int idx, max;
  if(!location)
    return 0;
  sscanf(location,"%s %s",side,location);
  dat=location_map[location];
  if(sizeof(dat)<SEPARATE||(side!="left"&&side!="right"))
    return 0;
  if(side=="left")
    idx=LEFTHIT;
  else
    idx=RIGHTHIT;
  if(dat[idx+2]==LOST)
    return 0;
  if(dat[idx+2]==CRIPPLED)
    amount=(int)(amount/2)+1;
  max=query_location_max_hits(location);
  if(dat[idx]<max)
    {
      dat[idx]+=amount;
      if(dat[idx]>max)
	{
	  dat[idx]=max;
	  if(dat[idx+2]<OK)
	    {
	      if(dat[CONNECTION]!="")
		{
		  if(query_location_status(side, dat[CONNECTION])==OK)
		    {
		      dat[idx+2]=OK;
		    }
		}
	      else
		dat[idx+2]=OK;
	    }
	}
    }
  location_map[location]=dat;
}

void regen_limbs()
{
  string *loc;
  int i, am_l, am_r, stu, rest;
  stu=THOB->query_stu();
  loc=keys(location_map);
  rest=THOB->query_resting();
  for(i=0;i<sizeof(loc);i++)
    {
      am_l=random(stu/5)+1;
      am_r=random(stu/5)+1;
      if(rest)
	{
	  am_l+=(int)(stu/5);
	  am_r+=(int)(stu/5);
	}
      heal_location("left "+loc[i],am_l);
      heal_location("right "+loc[i],am_r);
    }
  return;
}

void drop_armour(string side, string location)
{
}

void drop_weapon(string side, string location)
{
}


int damage_location(object attacker, string location_data, int damage, int type)
{
  int idx, tmp, max;
  mixed *dat;
  string side, location, hlp1, hlp2;
  tmp=sscanf(location_data, "%s %s", side, location);
  if(tmp<2)
    return 0;
  if(side=="left")
    idx=LEFTHIT;
  else
    {
      side="right";
      idx=RIGHTHIT;
    }
  dat=location_map[location];
  if(!dat||sizeof(dat)<(MAXPERCENT)+1)
    return 0;
  max=query_location_max_hits(location);
  dat[idx]=dat[idx]-damage;
  if(dat[idx]<-max&&dat[idx+2]>LOST)
    {
      if(!dat[SEPARATE])
        {
          hlp1="part of your "+location;
	  hlp2="part of "+THOB->query_possessive()+" "+location;
        }
      else
        {
          hlp1=side+" "+location;
	  hlp2=hlp1;
        }
      tell_object(THOB,
                  "^cRYou lose "+hlp1+"!^c0\n");
      tell_room(environment(THOB),
                THOB->query_cap_name()+" screams as "+
		THOB->query_pronoun()+" loses "+hlp2+"!\n",
                ({THOB}));
      dat[idx]=-max;
      dat[idx+2]=LOST; /* Torn off */
      BATTLEMASTER_OB->do_lose(bodytype, side, location);
    }
  if(dat[idx]<0&&dat[idx+2]>CRIPPLED)
    {
      if(!dat[SEPARATE])
        {
          hlp1=location;
          hlp2=location;
        }
      else
        {
          hlp1=side+" "+location;
          hlp2=side+" "+location;
        }
      dat[idx+2]=CRIPPLED; /* Crippled */
      tell_object(THOB,
                  "^cRYour "+hlp1+" is hurt very badly!^c0\n");
      tell_room(environment(THOB),
                THOB->query_cap_name()+
                " winces from pain as "+
		THOB->query_possessive()+" "+hlp2+" is hit!\n",
                ({THOB}));
      BATTLEMASTER_OB->do_cripple(bodytype, side, location);
    }
  location_map[location]=dat;
  return damage;
}

void do_full_heal()
{
  string *loc;
  int i, max;
  mixed *dat;
  loc=keys(location_map);
  THOB->revive();
  for(i=0;i<sizeof(loc);i++)
    {
      dat=location_map[loc[i]];
      max=query_location_max_hits(loc[i]);
      dat[LEFTHIT]=max;
      dat[RIGHTHIT]=max;
      dat[LEFTCOND]=OK;
      dat[RIGHTCOND]=OK;
      location_map[loc[i]]=dat;
    }
  THOB->set_hp(THOB->query_max_hp());
  THOB->set_sp(THOB->query_max_sp());
  THOB->set_ep(THOB->query_max_ep());
}

int begin_battle(object target)
{
  if(battle&&environment(battle)!=environment(THOB))
    {
      battle->remove_combatant(THOB);
      battle=present("BATTLEMASTER",environment(THOB));
    }
  if(!battle)
    {
      battle=clone_object(BATTLEMASTER_OB);
      battle->move(environment(THOB));
    }
  battle->add_combatant(THOB);
  if(target)
    {
      target->set_enemy(THOB);
      target->begin_battle(0);
    }
  return 1;
}

mapping dump_weapon_map() { return weapon_map;}
mapping dump_armour_map() { return armour_map;}

void battle_beat()
{
  int i, at_spd, spd, offres, manres, ep_cost, ep_chance, *dat, two, res, *wpdat;
  string side, tmp, *wpn, left, type;
  object wp, maneuver, target;
  if(!battle)
    begin_battle(0);


  if(environment(battle)!=environment(THOB)||THOB->query_is_dead())
    {
      battle->remove_combatant(THOB);
      return;
    }
  at_spd=query_armour_speed()+query_maneuver_speed();

  maneuver=THOB->find_skill(maneuver_name);
  target=query_target();
  maneuver->do_combat_msg(THOB, target);

  wpn=keys(weapon_map);
  for (i=0; i<sizeof(wpn);i++)
    {
      dat=weapon_map[wpn[i]];
      wp=(object)dat[WPOBJ];
      
      if(query_location_condition(wpn[i])>CRIPPLED)
	{
	  two=wp->query_wield_limbs();
	  type=wp->query_handling_type();
	  sscanf(wpn[i],"%s %s",left,tmp);
	  if(left=="left"&&type!="martial_arts")
	    {
	      if(two<2)
		{
		  res=THOB->query_skill_result(type+"_offhand_attack");
		  res=THOB->get_skill_success_level(type+"_offhand_attack",res);
		  if(res<0)
		    res=0;
		  dat[WPCOUNT]=dat[WPCOUNT]+res;
		}
	    }
	  else
	    dat[WPCOUNT]=dat[WPCOUNT]+2;
	  /* Off hand will later be slower than the other hand */
	  spd=AVG_SPD-(at_spd+wp->query_speed())/3;
	  spd=spd/10; /* About AVG_SPD/20 heart beats between average attacks */
	  if(spd<1)
	    spd=1;


	  if(dat[WPCOUNT]>=spd)
	    {
	      offres=THOB->query_skill_result(type+"_attack");
	      manres=THOB->query_skill_result(maneuver_name);

	      if(target&&battle)
		{
		  wpdat=wp->query_damage();

		  battle->perform_maneuver(wp,
					   target,
					   maneuver,
					   offres,
					   manres,
					   query_offense(wp),
					   wpdat[0],
					   left,
					   wpdat[1]);
		  dat[WPCOUNT]=0;
		}
	    }
	}
      weapon_map[wpn[i]]=dat; /* errori?*/
    }
  ep_chance=75-query_fatique();
  while (ep_chance>100)
    {
      ep_cost++;
      ep_chance=ep_chance-100;
    }
  if(random(100)<ep_chance)
    ep_cost++;
  THOB->add_ep(-ep_cost);
  return;
}

void do_ok_status(string side, string location)
{
  mixed *dat;
  int idx;
  dat=location_map[location];
  if(side=="left")
    idx=LEFTCOND;
  else
    idx=RIGHTCOND;
  dat[idx]=OK;
  location_map[location]=dat;
}

void do_cripple(string side, string location)
{
  mixed *dat;
  int idx;
  dat=location_map[location];
  if(side=="left")
    idx=LEFTCOND;
  else
    idx=RIGHTCOND;
  dat[idx]=CRIPPLED;
  location_map[location]=dat;
}

void do_lose(string side, string location)
{
  mixed *dat;
  int idx, idx2;
  string *wieldable;
  wieldable=({"hand"});
  dat=location_map[location];
  if(side=="left")
    {
      idx=LEFTCOND;
      idx2=LEFTHIT;
    }
  else
    {
      idx=RIGHTCOND;
      idx2=RIGHTHIT;
    }
  dat[idx]=LOST;
  dat[idx2]=-query_location_max_hits(location);
  location_map[location]=dat;
  drop_armour(side, location);
  if(member_array(location, wieldable)>=0)
    drop_weapon(side, location);
}
  
