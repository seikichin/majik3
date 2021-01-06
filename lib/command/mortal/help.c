/*
	Command				Help
	Description			Displays help on various things
	Coder				Dazzt
*/


#define HELP_DIR "/data/help/"

// Searches spells from specified directory

string *search_dir(string str)
{
    string *dir, *files;
    string f;
    int i;

    dir = get_dir(str);
    files = ({ });
    
    for (i = 0; i < sizeof(dir); i++)
    {
	f = str + dir[i];
	if (file_size(f) == -2)
	    files += search_dir(f + "/");
	else
	    if (dir[i][<2..] == ".c")
		files += ({ dir[i] });
    }
    return files;
}

    

main(string helpfile)
{
	string *directory;
        string poks = "", skill, command, buf = "";
	object ob;
	int i, total, section;
	
	if (!helpfile)
	{
          helpfile = "help";
	}

        if (sscanf (helpfile, "command %s", command) ||
            sscanf (helpfile, "mortal %s", command))
          section = 1;

        if (sscanf (helpfile, "immortal %s", command))
          section = 2;
        if (sscanf (helpfile, "function %s", command))
          section = 3;
        if (sscanf (helpfile, "skill %s", command))
          section = 4;
        if (sscanf (helpfile, "spell %s", command))
          section = 5;
        
        if (!section)
          if (sscanf(helpfile, "%d %s", section, command));
            section = section;

        if (section > 5 || section < 0)
          {
            write ("No section "+section+" available.\n");
            return 1;
          }

            if(section==1)
            {
              if (command == "topics" || command == "*" || command == "list"
               || command == "" || !command)
                {
                  directory = get_dir ("/command/mortal/");                    

                buf += "All help topics available in section 1 (mortal commands):\n\n";

                total = sizeof(directory);
           
                for (i = 0; i < total; i++)
                  {
                    if (directory[i][<2..] == ".c")
                  poks += directory[i][0..strsrch(directory[i], ".")-1] + "\n";
                    }

                buf += sprintf("%#-*s\n\nTotal help topics: ^c1%d^c0.\n", 
                  THIS->query_columns()-2, poks, total);
                 

                THIS->more_string(buf);
                return 1;
             }

             command=replace_string(command, " ", "_");
             ob=(find_object("/command/mortal/"+command) ||
                 load_object("/command/mortal/"+command));
  
             if (!ob || !ob->query_help())
               {
                 write ("No manual entry for "+command+" in section 1.\n");
                 return 1;
               }
              else
              {
               buf += sprintf ("%-*s(1) %|*s %*s(1)\n\n",
                  strlen(command), command,
                  THIS->query_columns()-(strlen(command))*2-21-2, "MAJIK MORTAL COMMANDS",
                  strlen(command), command);

                buf += "^c1NAME^c0\n";
                buf += "        "+command+"\n\n";
                if (ob->query_synopsis())
                {
                buf += "^c1SYNOPSIS^c0\n";
                buf += "        "+ob->query_synopsis()+"\n\n";
                }
                buf += "^c1DESCRIPTION^c0\n";
                buf += wrap(ob->query_help(), THIS->query_columns()-23, 8) + "\n";
                if (ob->query_example())
                {
                buf += "^c1EXAMPLE^c0\n";
                buf += "        "+ob->query_example()+"\n\n";
                }
                if (ob->query_see_also())
                {
                buf += "^c1SEE ALSO^c0\n";
                buf += "        "+ob->query_see_also()+"\n\n";
                }
                if (ob->query_author())
                {
                buf += "^c1AUTHOR^c0\n";
                buf += "        "+capitalize(ob->query_author())+" <"+ob->query_author()+"@majik.netti.fi>\n\n";
                }
                buf += sprintf ("Majik %|*s 1\n",
                  THIS->query_columns()-21-2,
                  ctime(stat("/command/mortal/"+command+".c")[1])[8..9]+
                  " "+
                  ctime(stat("/command/mortal/"+command+".c")[1])[4..6]+
                  " "+
                  ctime(stat("/command/mortal/"+command+".c")[1])[20..23]);

                write (buf);

               return 1;
              }
             }

            if(section==2)
            {
             if(THIS->query_security()==0)
             {
              write("Permission denied.\n");
              return 1;
             }

              if (command == "topics" || command == "*" || command == "list"
               || command == "" || !command)
                {
                  directory = get_dir ("/command/immortal/");
                
                buf += "All help topics available in section 2 "
                     + "(wizard commands):\n\n";

                total = sizeof(directory); 

                for (i = 0; i < total; i++) 
                {
                if (directory[i][<2..] == ".c")
                  poks += directory[i][0..strsrch(directory[i], ".")-1] + "\n";
                }

                buf += sprintf("%#-*s\n\nTotal help topics: ^c1%d^c0.\n",
                  THIS->query_columns()-2, poks, total);                 

                THIS->more_string(buf);   
                return 1;
             }   

             command=replace_string(command, " ", "_");
             ob=(find_object("/command/immortal/"+command) ||
                 load_object("/command/immortal/"+command));
  
             if (!ob || !ob->query_help())
               {
                 write ("No manual entry for "+command+" in section 2.\n");
                 return 1;
               }
              else
              {
               buf += sprintf ("%-*s(2) %|*s %*s(2)\n\n",
                  strlen(command), command,
                  THIS->query_columns()-(strlen(command))*2-21-2, "MAJIK IMMORTAL COMMANDS",
                  strlen(command), command);

                buf += "^c1NAME^c0\n";
                buf += "        "+command+"\n\n";
                if (ob->query_synopsis())
                {
                buf += "^c1SYNOPSIS^c0\n";
                buf += "        "+ob->query_synopsis()+"\n\n";
                }
                buf += "^c1DESCRIPTION^c0\n";
                buf += wrap(ob->query_help(), THIS->query_columns()-23, 8) + "\n";
                if (ob->query_example())
                {
                buf += "^c1EXAMPLE^c0\n";
                buf += "        "+ob->query_example()+"\n\n";
                }
                if (ob->query_see_also())
                {
                buf += "^c1SEE ALSO^c0\n";
                buf += "        "+ob->query_see_also()+"\n\n";
                }
                if (ob->query_author())
                {
                buf += "^c1AUTHOR^c0\n";
                buf += "        "+capitalize(ob->query_author())+" <"+ob->query_author()+"@majik.netti.fi>\n\n";
                }
                buf += sprintf ("Majik %|*s 1\n",
                  THIS->query_columns()-21-2,
                  ctime(stat("/command/immortal/"+command+".c")[1])[8..9]+
                  " "+
                  ctime(stat("/command/immortal/"+command+".c")[1])[4..6]+
                  " "+
                  ctime(stat("/command/immortal/"+command+".c")[1])[20..23]);

                write (buf);

               return 1;
              }
             }

        if (section == 4)
          {
              if (command == "topics" || command == "*" || command =="list"
               || command == "" || !command)
                {
                  directory = get_dir ("/obj/skill/");
                
                buf += "All help topics available in section 4 "
                     + "(mortal skills):\n\n";
                
                total = sizeof(directory);
                  
                for (i = 0; i < total; i++)
                {
                if (directory[i][<2..] == ".c")
                  poks += directory[i][0..strsrch(directory[i], ".")-1] +"\n";
                }
                
                buf += sprintf("%#-*s\n\nTotal help topics: ^c1%d^c0.\n",
                  THIS->query_columns()-2, poks, total);
                 
                THIS->more_string(buf);   
                return 1;
             }   

            command = replace_string(command, " ", "_");
            ob=THIS->find_skill(command);

            if (!ob||ob->query_type()=="hidden"||ob->query_type()=="node")
              {
                write ("No manual entry for "+command+" in section 4.");
                return 1;
              }

            write (ob->query_help() + "\n");
            return 1;
          }

        if (section == 3)
          {
            write ("Please use man(2) command for functions.\n");
            return 1;
          }

        if (section == 5)
          {
              if (command == "topics" || command == "*" || command =="list"
               || command == "" || !command)
                {
                  directory = search_dir("/obj/spell/generic/");
                  
                buf += "All help topics available in section 5 "
                     + "(mortal spells):\n\n";
                     
                total = sizeof(directory);
                
                for (i = 0; i < total; i++)
                {
                if (directory[i][<2..] == ".c")
                  poks += directory[i][0..strsrch(directory[i], ".")-1]+"\n";
                }
                 
                buf += sprintf("%#-*s\n\nTotal help topics: ^c1%d^c0.\n",
                  THIS->query_columns()-2, poks, total);
                  
                THIS->more_string(buf);
                return 1;
             }
              
            command = replace_string(command, " ", "_");
/*            ob=THIS->find_spell(command);
            
            if (!ob||ob->query_type()=="hidden"||ob->query_type()=="node")
              {
                write ("No manual entry for "+command+" in section 5.");
                return 1;
              }
*/
	      write("Spell help will be functional when namhas codes find_spell() similar to find_skill().\nBug him about that! :)    ++Dazzt\n");
//            write (ob->query_help() + "\n");
            return 1;
          }


        if (helpfile == "topics" || command == "topics")
            {
		message("standard", "All help topics available in section 0 (help files):\n\n", THIS);
		directory = get_dir(HELP_DIR);
				
                total = sizeof(directory);
    
		for (i = 0; i < total; i++)
		{
                  if (file_size("/etc/help/"+directory[i]) > 0)
                  poks += directory[i] + "\n";
                  else
                  poks += directory[i] + "\n";
		}
                write(sprintf ("%#-78s\n" + "\nTotal help topics: ^c1"+total+"^c0.\n", poks));
	}
	else
	{
		helpfile = HELP_DIR + helpfile;
                if (file_size(resolve_path(helpfile)) == -2)
                {
                  write ("Sub topics not implemented - try again later!\n");
                  return 1;
                }
		if (file_size(resolve_path(helpfile)) < 0)
		{
			message("standard", "Topic not found. For a list of topics, type 'help topics'.\n", THIS);
			return 1;
		}
		else
			THIS->more_file(helpfile);
	}

	return 1;
}

query_synopsis ()
{
  return "help [manual] <topic>";
}

query_help ()
{
  return "Envokes this screen on various different topics. To get a " + 
         "list of available help topics type help topics. Please see " + 
         "help(0) for documentation about manuals.";
}

query_see_also ()
{
  return "help(0), commands(1)";
}

query_author ()
{
  return "namhas";
}
