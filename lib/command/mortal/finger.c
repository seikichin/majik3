#include "/home/mordoc/include/time.c"
#include <security.h>

string find_wiz_level(int);

int main (string str) {

    int i,bogon ;
    string s1,s2, *plan, p ;
    string *user_file ;
    mapping user_data ;
    object plr;
    string text, gender ;

    if (!str) {
	notify_fail ("usage: finger <player>\n") ;
	return 0 ;
    }
    if(plr=find_player(str) && plr && interactive(plr)) plr -> save_me(); 
    if (file_size("/data/player/"+str[0..0]+"/"+str+".o")<0) {
	notify_fail ("There is no player named "+capitalize(str)+".\n") ;
	return 0 ;
    }
    user_file = explode(read_file("/data/player/"+str[0..0]+"/"+str+".o"),"\n") ;
    user_data = ([ ]) ;
    for (i=0;i<sizeof(user_file);i++) {
	if (sscanf(user_file[i],"%s %d",s1,bogon)==2) {
	    user_data[s1]=bogon ;
	} else {
	    if (sscanf(user_file[i],"%s %s",s1,s2)==2) {
		user_data[s1]=s2 ;
	    }
	}
    }

    text = sprintf("^cB=====^cW^bb%|15s^c0", capitalize(str));
    text += sprintf("^cB==========================================================^c0\n");
    text += sprintf("     ^cC%-15s: ^c0%-36s","Rank",find_wiz_level(user_data["security"]));
    if (user_data["gender"] == 1) gender = "male";
    else if (user_data["gender"] == 2) gender = "female";
    else gender = "neuter";
    gender = capitalize(gender);
    text += sprintf("  ^cC%-10s: ^c0%-6s\n", "Gender", gender);
    if (user_data["email"])
	text += sprintf("     ^cC%-15s: ^c0%-25s\n", "E-Mail Address", user_data["email"]);
    text += sprintf("     ^cC%-15s: ^c0%-25s", "Creation Date", ctime(user_data["creation_date"]));
    text += sprintf("\n");
    if (!find_player(str)) {
	text += sprintf("     ^cC%-15s: ^c0%-25s", "Last Logged In", ctime(user_data["last_date"]));
    }
    else 
	text += sprintf("     ^cC%-15s: ^c0%-25s", "Logged in Since", ctime(user_data["last_date"]));
    text += sprintf("from %s.\n", user_data["last_host"]);
    if (find_player(str) && !interactive(find_player(str)))
      text += sprintf("     ^cc%s is link dead currently.^c0\n",capitalize(find_player(str)->query_pronoun()));
    else
    if (find_player(str) && query_idle(find_player(str)) > 60)
text += sprintf("     ^cC%-15s: ^c0%-25s\n", "Idle for",format_time(query_idle(find_player(str))));
    if(user_data["spouse"])
    text += sprintf("     ^cC%-15s: ^c0%-25s\n",
"Married to",user_data["spouse"]);

	if (file_size("/home/" + str) == -2)
	{
		p = read_file("/open/" + str + "/.plan");
		if (p)
			plan  = explode(p, "\n");
		else
		{
			if (user_data["plan"])
			{
				plan = explode(user_data["plan"][1..<2], "\n");
			}
		}
		
		if (plan)
			text += sprintf("     ^cC%-15s: ^c0%s", "Plan", implode(plan, "\n                      ")) + "\n";
	}
	text += sprintf("^cB==============================================================================^c0\n");
			
    message("write", text, this_player());
    return 1;
}

string find_wiz_level(int level) {
    if (!level) return "Mortal";
    if (level < SEC3) return "Novice Demigod (level "+level+")";
    if (level < SEC4) return "Apprentice Demigod (level "+level+")";
    if (level < SEC5) return "Demigod (level "+level+")";
    if (level < SEC6) return "Lesser God (level "+level+")";
    if (level < SEC7) return "God (level "+level+")";
    if (level < SEC8) return "Greater God (level "+level+")";
    if (level == SEC8) return "Administrator (level "+level+")";
    return "Newt";
}

query_author ()
{
  return "mordoc";
}

query_synopsis ()
{
  return "finger <player>";
}

query_help ()
{
  return "This command will display various partially OOC information on "
       + "specified player. Lists things such as rank, gender, email "
       + "address, creation date etc.";
}

query_see_also ()
{
  return "who(1), wizlist(1), countries(1), email(1), plan(1)";
}

query_position ()
{
  return POS_RESTING;
}

