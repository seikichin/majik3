main (string str)
{
    object ob;

    if(!str)
    {
        write("Usage:\n");
        write("trans <playername>\n");
        write("Transport player to you\n");
        return 1;
    }

    ob = find_player (str);

    if (ob)
    {
	tell_object (ob, "You are magically sucked to totally new environment.\n");
	ob->move_player (file_name(environment(previous_object())) + ".c");
	return 1;
    }
    else
    {
	notify_fail ("No such living thing.\n");
	return 0;
    }
}

