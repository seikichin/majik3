main (string str, int duration)
{
    object ob;

    if(!str)
    {
	write("Usage: banish <player>\n");
	return 1;
    }

    if(capitalize(str)=="Project")
    {
	write("You cannot banish the god of justice! "+
	      "Instead, you will be punished yourself!\n");
	ob = THIS;
    }
    else ob = find_player (str);

    if (ob)
    {
	tell_object (ob, "You are suddenly surrounded with malicious spirits, shouting your name in rage! You have earned the wrath of the gods, and will thus be imprisoned!\n");
	message("standard",capitalize(str)+" is suddenly surrounded by a horde of evil spirits of Sweden and gets carried away for divine imprisonment!\n",environment(ob),ob);
	write(capitalize(str)+" banished!\n");
	message("announce",capitalize(str)+" has been banished by "+capitalize(THIS->query_name())+"!\n",users());
	ob->move_player("/home/project/areas/prison/cell.c");
	return 1;
    }
    else
    {
	notify_fail ("No such living thing.\n");
	return 0;
    }
}

