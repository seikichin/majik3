string nimi;

int main (string str) {

    int len, i;
    object obj, *ob;
    mixed err;

    if (!str) {
	notify_fail ("Usage: cc <filename>\n") ;
	return 0 ;
    }
    if (str == "here")
	str = file_name (environment (this_player()));

    if (!absolute_path(str)) str = this_player()->query_cwd()+str ;
    len = strlen(str) ;
    if (str[len-2..len-1]!=".c") str += ".c" ;
    if (file_size(str) < 0) {
      message ("wizinfo", "COMPILING ^c1" + str + "^c0 (virtual) ... ", THIS);
    }
    else message ("wizinfo", "COMPILING ^c1" + str + "^c0 ... ", THIS);
    nimi = str;
    obj = find_object(str);

    write ("\n");

    if (obj)
    {
	ob = all_inventory (obj);
	for (i=0;i<sizeof(ob);i++)
          {
            if(interactive(ob[i]))
	      {
                tell_object (ob[i], "You feel the world collapse under your feet!\n");
		ob[i]->move ("/world/misc/void");
	      }
	    else
              destruct(ob[i]);
          }
    }

    if (obj)
      destruct(obj);

    err = catch(call_other(str, "???"));

    if (err)
      write (err[1..]);
    else
      write ("Done.\n");

    for (i=0;i<sizeof(ob);i++) {
      if (ob[i])
        ob[i]->move_player (nimi, "nowhere");
    }

    return 1 ;
}
