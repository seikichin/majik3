/*
 * /inherit/protection.c
 * 
 * basic functions for dealing with damage and different damagetypes
 * 
 * coder              dazzt
 * */


/* --- -- - variables - -- --- */

static string *valid_prot;

/* --- function prototypes --- */

int *init_protection();                       /* init protection arrays     */
int set_protection(int *, string, int);
int add_protection(int *, string, int);

int calc_true_damage(int *, string, int);     /* reduces prot from dam      */

/* --- -- - functions - -- --- */

int *init_protection()
{
	if (!valid_prot)
		valid_prot = 
		({ "bludgeon", "pierce", "slash", "fire", "cold", "electricity",
				"acid", "poison", "magic", "psionic", "asphyxiation" });
	return allocate(sizeof(valid_prot));
}

int set_protection(int *protection, string type, int amount)
{
	int idx;

	idx = member_array(type, valid_prot);
	if (idx == -1)
		return 0;
	
	return protection[idx] = amount;
}

int add_protection(int *protection, string type, int amount)
{
	int idx;

	idx = member_array(type, valid_prot);
	if (idx == -1)
		return 0;
	
	return protection[idx] += amount;
}

int calc_true_damage(int *protection, string type, int amount)
{
	int idx, prot;

	idx = member_array(type, valid_prot);
	if (idx == -1)
		idx = 0;
	
	(protection[idx] > 100) ? prot = 0 : prot = 100 - protection[idx];
	
	return amount * prot / 100;
}

string *query_valid_damage_types()
{
	if (!valid_prot)
		init_protection();
	return valid_prot;
}
		
