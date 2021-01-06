/*
 * CHANNEL DAEMON for Majik MURPE - 
 *
 * coders:   dazzt and namhas 
 *
 */

#include <security.h>

static string *chan_valid = ({ "ooc", "irc", "wiz", "god", "admin" });
static int *chan_level = ({ 0, 0, SEC1, SEC6, SEC8 });

string *query_valid_channels()
{
	return chan_valid;
}

int
query_channel_level(string chan)
{
	int i;
	
	i = member_array(chan, chan_valid);
	if (i >= 0)
		return chan_level[i];
	return 0;
}

int
who_on_channel(string chan) {
  object *ob;
  string *names;
  int i,b;
  names = ({});
  ob = users(); b = 0;
if(!THIS->query_channel(chan)) return 0;
  for(i=0;i<sizeof(ob);i++) {
    if(ob[i]) {
      if(ob[i]->query_channel(chan))     
        names += ({ ob[i]->query_name() });
      }
}
for(i=0;i<sizeof(names);i++) {
if((b + (int)strlen(names[i])) >= 75) { write("\n"); b = 0; }
if(i == ((int)sizeof(names) - 1))
  write(capitalize(names[i])+".\n");
  else if(i == ((int)sizeof(names) - 2)) { 
  write(capitalize(names[i])+" and "); b+=5;
}
  else {
  write(capitalize(names[i])+", "); b+=2;
  }
b+=(int)strlen(names[i]);
}
return 1;
}

int
channel (string verb, string args)
{
    int i, szi, emote;
    string chanstr, surname;
    object *ob;

    i = member_array(verb, chan_valid);
    if (i == -1)
    	return 0;

    if (THIS->query_security() < chan_level[i])
    	return 0;

    if (!args)
    {
    	message("standard", "Usage: " + verb + " [message / who / last]\n",THIS);
    	return 1;
    }
        
    if (args == "last") 
    {
    	tail ("/log/channel." + verb);
    	return 1;
    }
    
    if (args == "on")
    {
    	THIS->enable_channel(verb);
    	message("standard", "Channel " + verb + " is now enabled.\n", THIS);
    	return 1;
    }
    
    if (args == "off")
    {
    	THIS->disable_channel(verb);
    	message("standard", "Channel " + verb + " is now disabled.\n", THIS);
    	return 1;
    }

    
    if (args == "who")
    {
        THOB->who_on_channel(verb);
        return 1;
    }
    if (!THIS->query_channel(verb))
    {
        THIS->enable_channel(verb);
        message("standard", "Channel " + verb + " is now enabled.\n", THIS);
    }

    surname = THIS->query_surname();

    if (!surname || surname == "" || surname == " ")
      surname = "";
    else
      surname = " " + capitalize(surname);

    if(args[0]==42 && args[strlen(args)-1]==42) {
     emote = 1;
     if(THIS->query_security() > 0)
      chanstr = "^cp<^cW"+verb+"^c0^cp>^c0: "+
       capitalize(THIS->query_name()) + " ";
     else
      chanstr = "^cc[^cW"+verb+"^c0^cc]^c0: "+
       capitalize(THIS->query_name()) + " ";
    write_file ("/log/channel."+verb,ctime(time())[4..15] + " " +     
    chanstr + args[1..strlen(args)-2] + "^c0\n");

} else  {

    chanstr = "^c0" + capitalize(THIS->query_name()) + surname;
    if (THIS->query_security() > 0)
    	chanstr += " ^cp<^cW" + verb + "^c0^cp>^c0: ";
    else
    	chanstr += " ^cc[^cW" + verb + "^c0^cc]^c0: ";

    write_file ("/log/channel." + verb, ctime( time())[4..15] + " " + chanstr + args + "^c0\n");
}
    ob = users();
    if (THIS)
      ob -= ({ THIS });
if(emote) args = args[1..strlen(args)-2];   
    message ("0", chanstr + args + "^c0\n", THIS);

    for (i = 0, szi = sizeof(ob); i < szi; i++) {
    	if (ob[i]->query_channel(verb))
	    message ("0", chanstr + args + "^c0\n", ob[i]);
    }
    return 1;
}
