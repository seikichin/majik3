/*
 * MAJIK SECURITY DAEMON
 * 
 * Last modified 14.01.97 by Dazzt
 * */

#include <security.h>

inherit BASE;

/* --- -- -- defines -- -- --- */

//#define DEBUG(x) if (find_player("dazzt")) message("0", x, find_player("dazzt"))
//#define DEBUG(x) write_file("/TEST", "DBG: " + x)
#define DEBUG(x) 
#define READ     0
#define WRITE    1

/* --- -- - variables - -- --- */

mapping security;

/* --- function prototypes --- */

int query_valid(string, int);

/* --- -- -- applies -- -- --- */

create()
{
	set_name("daemon");
	set_short("a security daemon");
	security = ([
// PATH                    READ   WRITE  
"/"                  : ({  SEC0,  SEC6 }),
"/data/"             : ({  SEC0,  SEC0 }),
"/CHANGES"           : ({  SEC0,  SEC1 }),
"/daemon/security.c" : ({  SEC6,  SEC6 }),
"/command/immortal/" : ({  SEC1,  SEC6 }),
"/command/admin/"    : ({  SEC6,  SEC6 }),
"/open/"             : ({  SEC0,  SEC1 }),
"/secure/"           : ({  SEC5,  SEC6 }),
"/home/"             : ({  SEC5,  SEC6 }),
"/log/"              : ({  SEC0,  SEC0 }),
"/www/"              : ({  SEC1,  SEC1 }),
]);
//	restore_object(SECURITY_SAVE);
}

/* --- -- - functions - -- --- */

string query_db()
{
	int i;
	string *dirs, s;
	
    dirs = keys(security);
	
	s = "";
	
	for (i = 0; i < sizeof(dirs); i++)
	{
		s += sprintf("R:%-3d W:%-3d :: %s\n", 
					 security[dirs[i]][READ],
					 security[dirs[i]][WRITE],
					 dirs[i]);
	}
		
	return s;
}
	

nomask int query_valid(string path, int which)
{
	object prev;
	string *dirs, dir;
	int min, sec, i;
	string f;
	
	i = 0;
	prev = previous_object(0);
	while (previous_object(++i))
		prev = previous_object(i);
	
	sec = prev->query_security();
	
	DEBUG("^ccSECURITY DAEMON ACCESS^c0: " + (which ? "(write)" : "(read)") + "\n");
	DEBUG(sprintf("Lvl: %-3d   Fn: %-30s Sh: %-15s\n",
				  sec,
				  file_name(prev),
				  prev->query_cap_name()
				  ));
	dirs = explode(path, "/");
	
	dir = "/";
	min = security[dir][which];
	for (i = 0; i < sizeof(dirs); i++)
	{
		if (is_directory(dir + dirs[i]))
			dir += dirs[i] + "/";
		else
			if (is_file(dir + dirs[i]))
				dir += dirs[i];
			
		if (security[dir])
			min = security[dir][which];
	}
	if (i == 0)
		min = security[dir][which];

	DEBUG(sprintf("Min: %-3d File: %-30s DB: %-30s \nResult: %-15s\n",
				  min,
				  path,
				  dir,
				  ((sec >= min || author_file(path) == prev->query_true_name()) ? 
				   "^cGOK^c0" : "^crACCESS DENIED^c0")
				  ));
	
	if (sscanf(file_name(prev), "/secure/%s#%*s", f) != -1)
	{
		if (!interactive(prev))
		{
			DEBUG("User from /secure/, security overriden.\n");
			return 1;
		}
	}
	
	if (author_file(path) == prev->query_true_name())
		return 1;
	if (sec >= min)
		return 1;
	return 0;
}

