int
main (string str)
{
    object ob;


    if (!str) {
	notify_fail ("Usage: clone <file>\n");
	return 0;
    }

    if (!absolute_path (str))
	str = this_player()->query_cwd() + str;

    str = resolve_path (str);

   if (str[<2..<1] != ".c")
     str += ".c";

    if (file_size (str) < 0) {
	notify_fail (str + ": No such file or directory\n");
	return 0;
    }

    ob = clone_object (str);

    if (ob)
    {
      message ("3", THIS->query_cap_name() + " snaps " +
        THIS->query_possessive() + " fingers and "+ob->query_name()+
        " arrives in a puff of logic.\n", ENV(THIS), THIS);

      write ("You clone "+ob->query_name()+".\n");

      ob->move (file_name(ENV(THIS)));
    }
    else
    {
	say (str + ": Failed to clone object\n");
    }

    return 1;
}
