main()
{
    mixed *directory;
    string poks = "";
    int i, total;
    mixed *poks2;
    string *arr;

    message("standard", "All commands available for you:\n\n", THIS);

    directory = get_dir ("/command/mortal/");

    if (THIS->query_security())
      directory += get_dir ("/command/immortal/");

    if (THIS->query_security() > 50)
      directory += get_dir ("/command/admin");

    poks2 = THIS->query_poks();

    for (int j=0;j<sizeof(poks2);j++) {
      if (strlen(poks2[j][0]) > 0)
      {
      if (!arr)
        arr = ({ poks2[j][0] });
      else
        arr += ({ poks2[j][0] });
      }
    }
    if(!arr) arr = ({});
    directory += arr;

    total = sizeof (directory);

    for (i = 0; i < total; i++)
    {
		if (directory[i][<1..] == "~" || directory[i][<4..] == ".old")
			continue;
		if (directory[i][<2..] == ".c")
			poks += directory[i][0..<3] + "\n";
		else
			poks += directory[i] + "\n";
    }

    message("standard", sprintf("%#-78s\n", poks) + "\nTotal commands: "+total+".\n", THIS);

    return 1;
}

query_author ()
{
  return "namhas";
}

query_help ()
{
  return "Will list all available commands to you at the present "
       + "time, excluding feeling commands and aliases.";
}

query_see_also ()
{
  return "command(1), alias(1), feelings(1), adverbs(1)";
}
