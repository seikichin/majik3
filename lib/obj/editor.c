/*
 * Generic editor collection for MAJIK MURPE
 * 
 * (c) Jari "Dazzt" Saukkonen 1998
 * 
 * */

inherit BASE;

/* --- -- - variables - -- --- */

static string prompt;
static string var, func;            /* internal variables for editor */
static string *text;
static int line;

static object caller;

/* --- function prototypes --- */

string query_integer_prompt();			/* different prompts are    */ 
string query_string_prompt();  			/* possible by overriding   */
string query_float_prompt(); 			/* these functions          */
string query_text_prompt();

object clone_editor();                          /* clones the editor object */

void read_integer(string, string);
void read_float(string, string);
void read_string(string, string);
varargs void read_text(string, string, object);

string do_prompt(string);

/* --- -- - functions - -- --- */

string query_integer_prompt() {  return "> "; }
string query_string_prompt()  {  return "> "; }
string query_float_prompt()   {  return "> "; }
string query_text_prompt()    {  return "[$L]> "; }

object set_caller(object ob)  {  return caller = ob; }

void display_help()
{
	string s;
	
	s = "^c1Available editor commands -- ^c0\n" + 
		"\n" +
		"  -?  -h             this help\n" +
		"  -s                 displays what you have written so far\n" +
		"  -#                 skip to line number #\n" +
		"  -q                 quit editor\n" +
		"\n";
	
	message("0", s, THIS);
}

void display_written()
{
	string s;
	int i;
	
	s = "^c1Currently written:^c0\n";
	
	for (i = 0; i < sizeof(text); i++)
		s += sprintf("%d: %s\n", i + 1, text[i]);
	message("0", s, THIS);
}


void _read_int(string args)  
{	
    int i;
    
    sscanf(args, "%d", i);
    caller->set(var, i);  
    if (func)
		call_other(caller, func);
}

void _read_float(string args)
{
    float f;
    
    sscanf(args, "%f", f);
    caller->set(var,  f);
    if (func)
		call_other(caller, func);
}

void _read_str(string args)  
{	
    caller->set(var, args);  
    if (func)
		call_other(caller, func);
}

void _read_text(string args)
{
	int l;
	
	switch(lower_case(args))
	{
	  case "-h" :
	  case "-?" : 
		display_help(); 
		message("0", do_prompt(query_text_prompt()), THIS);
		input_to("_read_text"); 
		return;
	  case "-s" :
		display_written();
		message("0", do_prompt(query_text_prompt()), THIS);
		input_to("_read_text");
		return;
	}
	
	if (sscanf(args, "-%d", l) == 1)
	{
		if (l > 0 && l < sizeof(text))
		{
			line = l;
			message("0", "^c1Now editing line #" + l+  ". Original line:^c0\n" + text[l - 1]+ "\n", THIS);
		}
		else
			message("0", "^c1Invalid line number.\n", THIS);
		message("0", do_prompt(query_text_prompt()), THIS);
		input_to("_read_text");
		return;
	}
	
	if (args != "." && args != "-q")
	{
		if ((sizeof(text) - 1) > line)
			text[line -1] = args;
		else
			text += ({ args });
		line++;
		message("0", do_prompt(query_text_prompt()), THIS);
		input_to("_read_text");
	}
	else
	{
		caller->set(var, implode(text, "\n"));
		if (func)
			call_other(caller, func);
		destruct(THOB);
	}
}

void read_integer(string v, string fun)
{
    var = v;   		func = fun;
    message("0", query_integer_prompt(), THIS);
    input_to("_read_int");
}

void read_string(string v, string fun)
{
    var = v;		func = fun;
    message("0", query_string_prompt(), THIS);
    input_to("_read_str");
}

void read_float(string v, string fun)
{
    var = v;		func = fun;
    message("0", query_float_prompt(), THIS);
    input_to("_read_float");
}

varargs void read_text(string v, string fun, object user)
{
	object ob;
	
	if (!clonep(THOB))
	{
		ob = clone_editor();
		if (user)
			ob->set_caller(user);
		else
			ob->set_caller(THOB);
		ob->read_text(v, fun, user);
		return;
	}
			
		
	line = 1;
	text = ({});
	var = v;		func = fun;
	message("0", "Starting editor. Type '-h' for help and '.' on empty line when done.\n", THIS);
	message("0", do_prompt(query_text_prompt()), THIS);
	input_to("_read_text");
}

string do_prompt(string s)
{
	s = replace_string(s, "$L", sprintf("%d", line));
	s = replace_string(s, "$n", THIS->query_name());
	s = replace_string(s, "$N", THIS->query_cap_name());
	return s;
}


object clone_editor()
{
    return clone_object(base_name(THOB));
}
    
