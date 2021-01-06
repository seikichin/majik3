/* Battlestatter */
#include <battle.h>

DEBUG(str)
{
  object ob;
  ob=find_player("aluna");
  if(ob)
    tell_object(ob,str+"\n");
  else
  {
    ob=find_player("flambeau");
    if(ob)
      tell_object(ob,str+"\n");
  }
}

int *armour_update_request(object *worn, int naked_defense, int naked_fatique, 
			   int naked_offense, int naked_speed, int naked_damage);
int *weapon_update_request(object *wielded);
int calculate_armour_defense(object *worn, int naked_defense);
int calculate_armour_fatique(object *worn, int naked_fatique);
int calculate_armour_offense(object *worn, int naked_offense);
int calculate_armour_speed(object *worn, int naked_speed);
int calculate_armour_damage(object *worn, int naked_speed);

int calculate_weapon_defense(object *wielded);
int calculate_weapon_fatique(object *wielded);
int calculate_weapon_protection(object *wielded);

int *armour_update_request(object *worn, int nd, int nf, int no, int ns, int ndm)
{
  int spd, off, def, fat, dmg;
  spd=calculate_armour_speed(worn, ns);
  off=calculate_armour_offense(worn, no);
  def=calculate_armour_defense(worn, nd);
  fat=calculate_armour_fatique(worn, nf);
  dmg=calculate_armour_damage(worn, ndm);
  return ({def, off, spd, fat, dmg});
}

static int calculate_armour_damage(object *worn, int naked_damage)
{
  int dam, i;
  dam=0;
  for (i=0;i<sizeof(worn);i++)
    {
      if(worn[i])
	  dam+=(int)worn[i]->query_damage();
      else
	  dam+=naked_damage;
    }
  return (int)(dam/sizeof(worn));
}

static int calculate_armour_defense(object *worn, int naked_defense)
{
  int def, i;
  def=0;
  for (i=0;i<sizeof(worn);i++)
    {
      if(worn[i])
	def+=(int)worn[i]->query_defense();
      else
	def+=naked_defense;
    }
  return (int)(def/sizeof(worn));
}

static int calculate_armour_fatique(object *worn, int naked_fatique)
{
 int def, i;
  def=0;
  for (i=0;i<sizeof(worn);i++)
    {
      if(worn[i])
        def+=(int)worn[i]->query_fatique();
      else
        def+=naked_fatique;
    }
  return (int)(def/sizeof(worn));
}

static int calculate_armour_offense(object *worn, int naked_offense)
{
  int off, i;
  off=0;
  for (i=0;i<sizeof(worn);i++)
    {
      if(worn[i])
	off+=(int)worn[i]->query_offense();
      else
	off+=naked_offense;
    }
  return (int)(off/sizeof(worn));
}

static int calculate_armour_speed(object *worn, int naked_speed)
{
  int spd, i;
  for (i=0;i<sizeof(worn); i++)
    {
      if(worn[i])
	spd+=(int)worn[i]->query_speed();
      else
	spd+=naked_speed;
    }
  return (int)(spd/sizeof(worn));
}

int *weapon_update_request(object *wielded)
{
  int def, fat, pro;
  def=calculate_weapon_defense(wielded);
  fat=calculate_weapon_fatique(wielded);
  pro=calculate_weapon_protection(wielded);
  return ({def, fat, pro});
}

static int calculate_weapon_defense(object *wielded)
{
  int def, i;
  def=0;
  for (i=0; i<sizeof(wielded); i++)
    {
      if(wielded[i])
	def+=(int)(wielded[i]->query_defense());
    }
  return (int)(def/sizeof(wielded));
}

static int calculate_weapon_fatique(object *wielded)
{
  int sum, i;
  sum=0;
  for (i=0;i<sizeof(wielded);i++)
    {
      if(wielded[i])
	sum+=(int)wielded[i]->query_fatique();
    }
  return (int)(sum/sizeof(wielded));
}

static int calculate_weapon_protection(object *wielded)
{
  int sum, i;
  sum=0;
  for (i=0;i<sizeof(wielded);i++)
    if(wielded[i])
      sum+=(int)wielded[i]->query_protection();
  return (int)(sum/sizeof(wielded));
}

string query_default_maneuver(string type)
{
  DEBUG(type);
  switch (type)
    {
    case "martial_arts":
    case "martial_arts_and_martial_arts":
      return "brawlers_punch";
    case "sword":
    case "mace":
    case "dagger":
    case "club":
    case "axe":
      return "basic_strike";
    default:
      return "illegal_combination";
    }
}






