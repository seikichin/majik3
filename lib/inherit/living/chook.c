#include <security.h>
#include <soul.h>

int typo;
int cmds;
int frozen;

int
commandHook (string str)
{
    mixed verb;
    int    result;
    int    *integer_list;        
    string *temp;
    object o;
    verb = query_verb();

    if (frozen)
    {
	write ("You try, but the mind-numbing cold prevents you...\n");
	return 1;
    }

    if (THOB->query_is_dead() && THOB->query_position() == POS_DEAD)
      THOB->set_position (POS_STANDING);

    /* builtin aliases */

    if (verb == "la") verb = "look";    
    if (verb == "exa") verb = "exa";
    if (verb == "'") verb = "say";
    if (verb == "l") verb = "look";
    if (verb == ":") verb = "emote";
    if (verb == "N") {verb = "5"; str="north";}
    if (verb == "W") {verb = "5"; str="west";}
    if (verb == "S") {verb = "5"; str="south";}
    if (verb == "E") {verb = "5"; str="east";}
    if (verb == "NW") {verb = "5"; str="northwest";}
    if (verb == "NE") {verb = "5"; str="northeast";}
    if (verb == "SW") {verb = "5"; str="southwest";}
    if (verb == "SE") {verb = "5"; str="southeast";}

    /*     
	   Cendor fixed this so you can't type '2 2 smile' and it
	   smiles four times then. If you try such thing it returns 0 
    */
    if(str)
    {
	integer_list = ({ 1,2,3,4,5,6,7,8,9,10 });
	if (member_array(to_int(verb),integer_list) != -1)
	{
	    temp=explode(str," ");
	    if(member_array(to_int(temp[0]),integer_list) != -1) return 0;  
	    for (int i=0;i<to_int(verb);i++)
		command (str);
	    return 1;
	}
    }

    while (verb[0..0] == "/")
	verb = verb[1..(sizeof(verb) - 1)];

    if (file_size ("/command/mortal/" + verb + ".c") > -1)
    {
      if (THOB->query_position()<call_other("/command/mortal/"+verb, "query_position"))
        {
          switch (THOB->query_position())
            {
              case POS_DEAD:
                tell_object (THOB, "You are unable to do anything while you are dead.\n");
                return 1;
              case POS_UNCONS:
                tell_object (THOB, "You are in a pretty bad shape, unable to do anything!\n");
                return 1;
              case POS_STUNNED:
                tell_object (THOB, "All you can do right now is think about the stars!\n");
                return 1;
              case POS_SLEEPING:
                tell_object (THOB, "In your dreams, or what?\n");
                return 1;
              case POS_RESTING:
                tell_object (THOB, "Nah... You feel too relaxed to do that..\n");
                return 1;
              case POS_SITTING:
                tell_object (THOB, "Maybe you should get on your feet first?\n");
                return 1;
              case POS_FIGHTING:
                tell_object (THOB, "No way! You're fighting for your life!\n");
                return 1;
            }
          }

	if (str)
	    result = call_other ("/command/mortal/" + verb, "main", str);
	else
	    result = call_other ("/command/mortal/" + verb, "main");
    }

    if (result) {
	cmds++;
	return 1;
    }

    if (file_size ("/command/immortal/" + verb + ".c") > -1)
    {
	if (THOB->query_security()) {
	    if (str)
		result = call_other ("/command/immortal/" + verb, "main", str);
	    else
		result = call_other ("/command/immortal/" + verb, "main");
	}
    }

    if (result) {
	cmds++;
	return 1;
    }

    if (file_size ("/command/admin/" + verb + ".c") > -1)
    {
	if (THOB->query_security() >= SEC6) {
	    if (str)
		result = call_other ("/command/admin/" + verb, "main", str);
	    else
		result = call_other ("/command/admin/" + verb, "main");
	}
    }

    if ("/daemon/channel"->channel(verb, str))
    {
        cmds++;
        return 1;
    }

    // Added by Mordoc on July 25th, 1997 for souls.

    if (verb && verb[0] == '#')
      {
        o = present("irc_object");
        
        if (!o)
          {
            tell_object (THOB, "You have to '^c1irc on^c0' first.\n");
            return 1;
          }

         o->do_irc (str);
         return 1;
       }

    if (SOUL_D->is_soul(verb)){

	if (!str) {                         
	    if (!SOUL_D->parse_soul(verb)) 

		result = 0;

	    else {
		cmds++;
		result = 1;
	    }
	}

	else if (!SOUL_D->parse_soul(verb+" "+str))

	    result = 0;

	else {


	    cmds++;
	    result = 1;
	}

    }

    if (result) {
	cmds++;
	return 1;
    }
    else {
	typo++;
	if (typo == 100 || typo == 1000 || typo == 10000 || typo == 100000) {
	    write ("Congratulations! You just did your "+typo+"th typo!\n\a");
	    return 1;
	}
	if (typo == 1) {
	    write ("Congratulations! You just did your first typo!\n\a");
	    return 1;
	}
	return 0;
    }
}
