/****
****    Name                            /inherit/item.c 
***             Description                     Base object for items
**              Coder                           Dazzt
*/

inherit BASE;

/*              Variables
*/

static int             xdim, ydim, zdim;               /* x, y, z dimensions */
static int             hollow;
static int             weight;                         /* weight in grams */

static mapping         materials;                      /* material item is made from */
static mapping         properties;                     /* special properties */

int             hp;                      /* 'hit points' of item */

static int max_hp;

static int             worn;                           /* is this item wielded? */
static int             no_get;                         /* ungettable? */
static int             light;    /* Light level of the item: -2 to 2 (-2 and +2 are magical lights, -1 to +1 are mundane */

static string          smell;                          
static string          listen;
static string          taste;

int quality;

/*              create()
*/

is_item()
{
  return 1;
}

create()
{
    no_get	= 0;
    worn	= 0;
    weight	= 0;
    smell	= 0;
    taste	= 0;
    listen	= 0;  
    light	= 0;
    hollow	= 0;
    xdim	= 1;
    ydim	= 1;
    zdim	= 1;

    quality = 10 + random(20);

    hp = 1;         max_hp = 1;
    materials = ([ ]);
    properties = ([ ]);
    this_object()->create_item();
}

int
set_quality (int i)
{
  return quality = i;
}

int
query_quality (int i)
{
  return quality;
}

/*              get()   -- moves item to another environment
*/

int get(object target)
{
    if (no_get == 1)
		return 0;

    return 1;
}

/*     do_wear()     -- called when item is worn 
 * */

void do_wear()
{
    string *s = keys(properties);
    string *property;
    int i, org;

    for (i = 0; i < sizeof(s); i++)
    {
	property = explode(s[i], " ");
	switch (property[0])
	{
	case "stat" :  
	    org = call_other(THIS, "query_" + property[1]);
	    call_other(THIS, "set_" + property[1], org + properties[s[i]]);
	    org = call_other(THIS, "query_max_" + property[1]);
	    call_other(THIS, "set_max_" + property[1], org + properties[s[i]]);
	    break;
	case "regen" :
	    org = call_other(THIS, "query_baseregen_" + property[1]);
	    call_other(THIS, "set_baseregen_" + property[1], org + properties[s[i]][0]);
	    org = call_other(THIS, "query_randregen_" + property[1]);
	    call_other(THIS, "set_randregen_" + property[1], org + properties[s[i]][1] - properties[s[i]][0]);
	    break;
	default : break;
	}
    }
    this_object()->wear();
}

/*     do_unwear()    -- called when item is removed 
 * */

void do_unwear()
{
    string *s = keys(properties);
    string *property;
    int i, org;

    for (i = 0; i < sizeof(s); i++)
    {
	property = explode(s[i], " ");
	switch (property[0])
	{
	case "stat" :  
	    org = call_other(THIS, "query_" + property[1]);
	    call_other(THIS, "set_" + property[1], org - properties[s[i]]);
	    org = call_other(THIS, "query_max_" + property[1]);
	    call_other(THIS, "set_max_" + property[1], org - properties[s[i]]);
	    break;
	case "regen" :
	    org = call_other(THIS, "query_baseregen_" + property[1]);
	    call_other(THIS, "set_baseregen_" + property[1], org - properties[s[i]][0]);
	    org = call_other(THIS, "query_randregen_" + property[1]);
	    call_other(THIS, "set_randregen_" + property[1], org - (properties[s[i]][1] - properties[s[i]][0]));
	    break;
	default : message("standard", "Invalid property on " + short() + ".\n", THIS);
	    break;
	}
    }
    this_object()->unwear();
}

/*     query_value()     -- approximate value of an object
 * */

int query_value()
{
    int i, value;
    string *mats;

    mats = keys(materials);
    value = 0;
    for (i = 0; i < sizeof(mats); i++)
    {
		value += to_int(materials[mats[i]] *
                         (THOB->query_weight() / 1000.0) * 
		find_object(MATERIAL_D)->query_value(mats[i]) / 100.0);
    }
    return (value + to_int(quality/100.0*value));
}

int set_hp(int i) { }
int add_hp(int i) { return hp += i; }
int set_max_hp(int i) { }
int query_hollow ()
{
  return hollow;
}
varargs int set_dimensions(int x, int y, int z, int hollow_percent)
{
    xdim = x; ydim = y; zdim = z;

    if (!hollow_percent)
	hollow = 0;
    else
	hollow = hollow_percent;

    hp = THOB->query_max_hp()/2 + to_int(quality/100.0*THOB->query_max_hp());
    if (hp < 2)
      hp = 1;
    max_hp = THOB->query_max_hp();
    return 1;
}

int set_weight(int n) { return weight = n; }
int set_worn(int n) { return worn = n; }
int set_no_get () { return no_get = 1; }

mixed set_property(string property, mixed value) 
{ 
    if (!properties)
	properties = ([ ]);
    return properties[property] = value; 
}

mixed set_material(mixed s) 
{       
    int i, percent;
    string *mats;
    if (!materials)
	materials = ([ ]);

    if (stringp(s))
    {
	if (member_array(s, find_object(MATERIAL_D)->query_all_materials()) == -1)
	    materials["wrong material"] = 100;
	else
	    materials[s] = 100;
	return s;
    }
    if (mapp(s))
    {
	mats = keys(s); percent = 0;

	for (i = 0; i < sizeof(mats); i++)
	{
	    if (member_array(s, find_object(MATERIAL_D)->query_all_materials()) == -1)
		materials["wrong material"] += s[mats[i]];
	    else
		materials[mats[i]] = s[mats[i]];
	    percent += s[mats[i]];
	}
	if (percent != 100)
	{
	    message("standard", "Invalid material definition on " + THOB->short() + ".\n", THIS);
	    return 0;
	}
	return s;
    }
    return 0;
}

string set_smell(string s) { return smell = s; }
string set_taste(string s) { return taste = s; }
string set_listen(string s) { return listen = s; }

string query_smell(string s) { return smell; }
string query_taste(string s) { return taste; }
string query_listen(string s) { return listen; }

int query_hp() { return hp; }
int query_max_hp() {
  int i;

  if (hollow)
    i = (xdim*ydim*zdim)*hollow/100;
   
  return ((xdim*ydim*zdim-i)/10)+5;
}

string query_cond()
{
    int i;
    i = 100 * THOB->query_hp() / THOB->query_max_hp();

    switch (i)
    {
    case 0 : return "useless";
    case 1..9 : return "trashed";
    case 10..19 : return "very bad";
    case 20..29 : return "bad";
    case 30..39 : return "poor";
    case 40..59 : return "average";
    case 60..69 : return "good";
    case 70..79 : return "excellent";
    case 80..89 : return "superb";
    case 90..100 : return "perfect";
    default : return "AWESOME";
    }
}

string query_weightstr()
{
    switch (THOB->query_weight())
    {
    case 0 : return "weightless";
    case 1..99 : return "very light weight";
    case 100..499 : return "light weight";
    case 500..999 : return "a bit weighty";
    case 1000..2999 : return "weighty"; 
    case 3000..4999 : return "a bit heavy";
    case 5000..9999 : return "heavy";
    case 10000..19999 : return "very heavy";
    case 20000..49999 : return "very VERY heavy";
    case 50000..79999 : return "EXTREMELY heavy";
      default: return "RIDICULOUSLY heavy";
    }
}

int *query_dimensions() { return ({ xdim, ydim, zdim }); }
int query_volume() { return xdim * ydim * zdim; }

int query_longest_dim()
{
    if (xdim >= ydim && xdim >= zdim)
	return xdim;
    if (ydim >= xdim && ydim >= zdim)
	return ydim;
    if (zdim >= xdim && zdim >= ydim)
	return zdim;
}

mixed query_material() { return materials; }
mapping query_properties() { return properties; }
int query_no_get() { return no_get; }
int query_weight() { 
  string *k;
  object *all, o;
  int hol, paino, cm3, l;

  k = keys(materials);

  if (hollow)
    hol = (xdim*ydim*zdim)*hollow/100;

  cm3 = (xdim*ydim*zdim)-hol;

  for (int i=0;i<sizeof(k);i++)
    {
      paino += materials[k[i]] * (MATERIAL_D->query_weight(k[i]) * cm3) / 100;

      if (THOB->query_liquid())
        l = THOB->query_liters();

      paino += materials["water"] * (MATERIAL_D->query_weight("water") * l) /
        100;

      all = all_inventory(THOB);

      if (all)
        {
          foreach (o in all)
            paino += o->query_weight();
        }
    }

  return paino;
}

int query_worn() { return worn; }

string long()
{
    string str = "";

    str = long_desc;
    if (long_desc[<1..<1] != "\n")
	str += "\n";
    str += "It looks " + query_weightstr() + ".\n";
    str += "It's in " + query_cond() + " condition.\n";
    return str;
}

string identify()
{   
    string str;                       // used when identifying object
    string *mats, *p, *prop;
    int i, j;

    /* names and aliases 
     * */

    str = "";

    if (aliases)
    {
	str += "It's known as ";
	for (i = 0; i < sizeof(aliases); i++)
	    str += aliases[i] + ", ";
	str += "and " + name + ".\n";
    }
    else
	str += "It's known as " + name + ".\n";

    /* weight 
     * */

    str += "It weighs " + weight + " grams.\n";

    /* properties
     * */

    p = keys(properties);

    for (i = 0; i < sizeof(p); i++)
    {
	prop = explode(p[i], " ");

	switch (prop[0])
	{
	case "stat" : 
	    j = properties[p[i]];
	    str += "It affects ";
	    if (j < 0)
		str += "negatively ";
	    str += "your " + prop[1] + " ";
	    if (j < 0)
		j = -j;

	    switch(j)
	    {
	    case 0..3 : str += "a little"; 
		break;
	    case 4..6 : str += "somewhat";
		break;
	    case 7..10 : str += "greatly";
		break;
	    }
	    str += ".\n";
	    break;

	case "regen" : 
	    j = properties[p[i]][0];
	    str += "It affects ";
	    if (j < 0)
		str += "negatively ";
	    str += "your " + prop[1] + " regeneration ";
	    if (j < 0)
		j = -j;

	    switch(j)
	    {
	    case 0..3 : str += "a little"; 
		break;
	    case 4..6 : str += "somewhat";
		break;
	    case 7..10 : str += "greatly";
		break;
	    }
	    str += ".\n";
	    break;
	}
    }

    /* materials
     * */

    str += "It's made from ";

    mats = keys(materials);
    if (sizeof(mats) > 1)
    {
	for (i = 0; i < sizeof(mats) - 1; i++)
	    str += mats[i] + ", ";
	str += str[0..(strlen(str) - 2)];

	str += "and " + mats[i] + ".\n";
    }
    else
	str += mats[0] + ".\n";

    /* condition 
     * */

    str += "It's in " + query_cond() + " condition.\n";

    return str;
}

int set_light(int i)
{
    if(i<-2)
	i=-2;
    else
    if(i>2)
	i=2;
    light=i;
    if(THIS)
	THIS->check_light();
    return light;
}

int query_light() { return light;}

string stat_me()
{
	string mats;
	string *all_mats;
	int i;

	if (materials)
	{
		mats = "";
	    all_mats = keys(materials);

		for (i = 0; i < sizeof(all_mats); i++)
			mats += all_mats[i] + " (" + materials[all_mats[i]] + "%), ";
		mats = mats[0..<3];
	}
	
	return base::stat_me() + 
		"ITEM OBJECT\n" +
		"  weight       : " + sprintf("%.3f", THOB->query_weight()/1000.0) + " kgs ('" + query_weightstr() + "')\n" + 
		"  dimensions   : " + xdim + " x " + ydim + " x " + zdim + " cm\n" +
                "  hollow       : " + hollow + " %\n" + 
		"  hitpoints    : " + hp + " / " + max_hp + " (" + query_cond() + ")\n" +
		"  material     : " + (mats ? mats : "-") + "\n" + 
		"  worn         : " + (worn ? "yes" : "no") + "\n" + 
		"  no_get       : " + (no_get ? "yes" : "-") + "\n" +
		"  value        : " + (query_value() ? (string)query_value() : "worthless") + "\n";
		
}
