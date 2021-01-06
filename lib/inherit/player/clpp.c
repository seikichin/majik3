/*
 * RCS: $Id: clpp.c,v 1.1 1997/09/14 17:30:07 namhas Exp namhas $
 *
 * COMMAND LINE PRE-PARSER (CLPP) for Majik MURPE - by namhas@neutech.fi
 *
 * v1.3 [09/10/1997, Dazzt]: Fixed '!n' to work properly
 * v1.2 [03/10/1997, Dazzt]: Almost complete rewrite
 */

#define MAX_PARSE_RECURSION_DEPTH    4
#define MAX_COMMANDS                 50
#define MAX_ALIASES                  50 

static string *clh_arr; // command line history array

string *query_clh_arr()
{
	return clh_arr;
}

mapping clpp_aliases = ([ ]);   // argument aliases
mapping clpp_cmds    = ([ ]);      // command aliases 

string set_clpp_cmd(string cmd, string alias)
{
	if (!clpp_cmds)
		clpp_cmds = ([ ]);
	
	if (sizeof(keys(clpp_cmds)) < MAX_COMMANDS)
		return clpp_cmds[cmd] = alias;
	else
		return 0;
}

int remove_clpp_cmd(string cmd)
{
	map_delete(clpp_cmds, cmd);
	return 1;
}

string set_clpp_alias(string trig, string alias)
{
	if (!clpp_aliases)
		clpp_aliases = ([ ]);
	
	if (sizeof(keys(clpp_aliases)) < MAX_ALIASES)
		return clpp_aliases[trig] = alias;
	else
		return 0;
}

int remove_clpp_alias(string trig)
{
	map_delete(clpp_aliases, trig);
	return 1;
}



string
parse (string verb, string args, int depth)
{
    int i, szi, substc;
    string *parsed, *parsedargs, k;
    int modified = 0;

    /* check for maximum recursion depth */

    if (depth >= MAX_PARSE_RECURSION_DEPTH)
    {
		message("standard", "Maximum alias recursion depth exceeded, execution aborted.\n", THIS);
		return 0;
    }
	
	while (verb[0] == 32)
		verb = verb[1..<1];

    if (!verb)
		verb = "";

    if (!args)
		args = "";

    /* preparser override */

    if (verb[0] == '@')
		return verb[1..sizeof(verb)] + " " + args;

    if (verb == "n")
      return "north";
    if (verb == "w")
      return "west";
    if (verb == "e")
      return "east";
    if (verb == "s")
      return "south";
    if (verb == "sw")
      return "southwest";
    if (verb == "se")
      return "southeast";
    if (verb == "nw")
      return "northwest";
    if (verb == "ne")
      return "northeast";
    if (verb == "u")
      return "up";
    if (verb == "d")
      return "down";

    /* history line processing, not sure if this works yet */

    if (clh_arr && verb[0] == '!')
    {
		if (verb == "!")
			return clh_arr[sizeof(clh_arr) - 1];
		else
		{
			if ((sscanf(verb[1..sizeof(verb)], "%d", i) != 1) || 
				(sizeof(clh_arr) < i))
			{
				message("standard", "No such history line available.\n", THIS);
				return 0;
			}
			message("standard", "Recalling '" + clh_arr[sizeof(clh_arr) - i] +"' from history.\n", THIS);
			return clh_arr[sizeof(clh_arr) - i];
		}
    }
	
    /* command processing */
	
    if (clpp_cmds)
    {
		k = clpp_cmds[verb];
		if (k)
		{
			parsed = explode(k, " ");
			parsedargs = explode(args, " ");
			
			/* dollar substitution */
			
			for (i = 0, szi = sizeof(parsed); i < szi; i++)
			{
				if (sscanf(parsed[i], "$-%d", substc) == 1)
					parsed[i] = implode(parsedargs[substc..(sizeof(parsedargs)-1)], " ");
				if (sscanf(parsed[i], "$-L%d", substc) == 1)
					parsed[i] = implode(parsedargs[0..(sizeof(parsedargs) - 1 - substc)], " ");
				if (sscanf(parsed[i], "$%d", substc) == 1)
					parsed[i] = parsedargs[substc - 1];
				if (sscanf(parsed[i], "$L%d", substc) == 1)
					parsed[i] = parsedargs[szi - (substc - 1)];
				if (parsed[i] == "$")
					parsed[i] = args;
			}
			
			verb = parsed[0];
			if (sizeof(parsed) >= 2)
				args = implode(parsed[1..(sizeof(parsed) - 1)], " ");
			else 
				args = "";
			return parse(verb, args, depth + 1);
		}
    }
	
    /* alias processing */
	
    if (clpp_aliases && verb != "unalias")
    {
		parsed = explode(args, " ");
		modified = 0;
		for (i = 0, szi = sizeof(parsed); i < szi; i++)
		{
			k = clpp_aliases[parsed[i]];
			if (k)
			{
				parsed[i] = k;
				modified = 1;
			}
		}
		args = implode(parsed, " ");
		if (modified)
			return parse(verb, args, depth + 1);
    }
	
    /* add command to history buffer */
	
    if (!clh_arr)
		clh_arr = ({ verb + " " + args });
    else
		clh_arr += ({ verb + " " + args });
	
    if (sizeof(clh_arr) > 9)
		clh_arr -= ({ clh_arr[0] });
	
    return verb + " " + args;
}


string process_input(string input)
{
	string *s;
	
	if (!input || input == "\n" || input == "")
		return input;
	
	s = explode(input, " ");
	if (sizeof(s) >= 2)
		return parse(s[0], implode(s[1..(sizeof(s) - 1)], " "), 0);
	else
	{
		if (sizeof(s) > 0)
			return parse(s[0], "", 0);
		else
			return "";
	}
}
