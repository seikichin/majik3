main (string str)
{
    int res ;
    string file, tmp ;
    object ob ;

    if (!str) {
	notify_fail ("Usage: goto <room name or player>\n") ;
	return 0 ;
    }
    file = str ;
    if (!absolute_path(file)) file = this_player()->query_cwd()+file ;
    file = resolve_path(file) ;
    if (file[strlen(file)-2..strlen(file)-1]!=".c") file += ".c" ;
    tmp = file_name(environment(this_player()))+".c" ;
    if (tmp=="/"+file) {
	write ("You twitch.\n") ;
	return 1 ;
    }
    if (!file || file_size(file) < 0) {
	ob = find_player (str) ;
	if (!ob) {
            this_player()->move_player (file);
	    return 1;
	}
	ob = environment(ob) ;
	if (ob==environment(this_player())) {
	    write ("You twitch.\n") ;
	    return 1 ;
	}
        res = this_player()->move_player (file_name (ob));
	if (!res) {
	    write ("You cannot go to that player.\n") ;
            return 0;
	}
	return 1 ;
    }
    this_player()->move_player (file);
    return 1 ;
}

