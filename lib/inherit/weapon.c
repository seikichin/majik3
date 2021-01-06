/****
****    File                                    /inherit/weapon.c
***     Description                             Weapon object
**      Coder                                   Dazzt
*/

inherit "/inherit/equipment";

#define WEAPON_DATA         "/data/misc/weapon.data"
#define SPACECUT(x)         implode(explode(x, " ") - ({" "}), "")

/* --- -- - variables - -- --- */

string weapon_type;                     /* weapon type, to set defaults     */
string handling_type;                   /* skill required to use this wpn   */
string *damage_types;                   /* list of damagetypes and damages  */

static string *slots;                   /* used by eq code, do NOT modify!  */

static int is_worn;

/* --- function prototypes --- */

string set_damage_type(string, string); /* 'dam' is in XdY+Z form           */
int set_weapon_type(string);            /* initializes various defaults     */
string set_handling_type(string);       /* defines weapon handling type     */

string query_weapon_type();             /* returns weapon type              */           
string query_handling_type();           /* returns handling type            */
string *query_damage_types();           /* returns all damages              */

int *resolve_damage(string);            /* "3d6" => ({ min_dam, max_dam })  */
int *query_random_damage();             /* calculates random amnt of damage */

string *set_slots(string *);            /* used by eq code, do NOT modify   */
string *query_slots();                  /* manually!                        */

string
set_handling_type (string str)
{
  return handling_type = str;
}

int
query_wield_limbs ()
{
  return 1; /* 1h weapon, for aluna's battle */
}

int
query_is_worn ()
{
  return is_worn;
}

int
set_is_worn (int i)
{
  return is_worn = i;
}

/* --- -- - functions - -- --- */

create_equipment()
{
	damage_types = PROTECTION_D->init_protection();
	
	THOB->create_weapon();
}

/*
 * int set_weapon_type(string)                 Initializes weapon to its
 *                                             default values that are read
 *                                             from weapon data file.
 * */

int set_weapon_type(string type)
{
	string *file;
	string wtype, whtype, wdtype, wdmg, material;
	int xs, ys, zs, i;
	
	file = explode(read_file(WEAPON_DATA), "\n");
	
	while (strlen(type) != 15)
		type += " ";
	
	for (i = 0; i < sizeof(file); i++)
	{
		if (file[i] && file[i][0] != '#')
		{	
			sscanf(file[i], "%s | %s | %s | %s | %d %d %d", 
				   wtype, whtype, wdtype, wdmg,
				   xs, ys, zs);
			if (wtype == type)
				break;
		}
	}
	
	if (i == sizeof(file))
		return 0;

	weapon_type = wtype;
	handling_type = SPACECUT(whtype);
	set_damage_type(SPACECUT(wdtype), SPACECUT(wdmg));
	set_dimensions(xs, ys, zs, 0);

	if (materials && sizeof(keys(materials)) == 0)
	{
		material = MATERIAL_D->query_random_material();
		set_material(material);
		set_weight(query_volume() * MATERIAL_D->query_weight(material) / 5);
	}
	
	return 1;
}
	
string set_damage_type(string type, string dam)
{
	int idx;
	
	idx = member_array(type, PROTECTION_D->query_valid_damage_types());
	if (idx == -1)
		return 0;
	
	return damage_types[idx] = dam;
}


/*  
 *  int *resolve_damage(string)                calculates minimum and maximum
 *                                             damages from XdY+Z form
 * */

int *resolve_damage(string dam)
{
	int x, y, bonus;
	
	if (!dam || dam == "")
		return ({ 0, 0 });
	
	if (sscanf(dam, "%dd%d+%d", x, y, bonus) != 3)
		if (sscanf(dam, "%dd%d", x, y) != 2)
			if (sscanf(dam, "%d", bonus) != 1)
				return ({ 0, 0, 0 });

	return ({ x + bonus, x * y + bonus });
}

/*  int *query_random_damage()                 calculates damage done in one 
 *                                             hit. returned array has the
 *                                             same form as protection array.
 * */

int *query_random_damage()
{
	int *damages, i, sz;
	int *dam, d;
	
	damages = PROTECTION_D->init_protection();
	
	for (i = 0, sz = sizeof(damage_types); i < sz; i++)
	{
		dam = resolve_damage(damage_types[i]);
		d = random((dam[1] + 1) - dam[0]) + dam[0];
		damages[i] = d;
	}
	return damages;
}

/*
 * Couple of simple querying functions 
 * 
 * */

string query_weapon_type() {	return weapon_type;    }
string query_handling_type() {	return handling_type;  }
string *query_damage_types() {  return damage_types;   }

int *query_damage()
{
/* 
	int idx;
	
	idx = member_array(type, PROTECTION_D->query_valid_damage_types());
	if (idx != -1)
		return damage_types[idx];
	else
		return 0;
*/

  return ({ 5, 1 });
}




string stat_me()
{
	string s;
	string *dam = PROTECTION_D->query_valid_damage_types();
	int i;
	
	s = ::stat_me();
	s += "WEAPON OBJECT\n";
	
	s += "  weapon type  : " + (weapon_type ? weapon_type : "custom") + "\n" 
	   + "  handling     : " + (handling_type ? handling_type : "none") + "\n"
	   + "  damage       : ";
	for (i = 0; i < sizeof(damage_types); i++)
		if (damage_types[i] != 0)
			s += dam[i] + " (" + damage_types[i] + "), ";
	
	s = s[0..<3] + "\n";
	
	return s;
}

string *set_slots(string *s) {	return slots = s; }
string *query_slots()        {  return slots;     }

int query_weapon()    {	  return 1; }
int is_weapon() { return 1; }
int query_is_weapon() { return 1; }
string query_author() {	  return "dazzt"; }
