int
main (string str)
{
    string file, arg;
    int i;

    if (!str)
    {
	notify_fail ("usage: run <lpc source in home directory> [arguments]\n");
	return 0;
    }

    if (sscanf (str, "%s %s", file, arg) !=2) {
	if (sscanf (str, "%s", file) !=1) {
	    notify_fail ("usage: run <lpc source in home directory> [arguments]\n");
	    return 0;
	}
    }

    i = strsrch(file, "/");

    if (i == -1)
	file = THIS->query_cwd() + file;
    else
    if (i != 0)
	file = THIS->query_cwd() + file;

    if (file_size(file + ".c") < 0)
    {
	notify_fail (file + ".c" + ": not found, sorry.\n");
	return 0;
    }

    if (arg)
	call_other (file, "main", arg);
    else
	call_other (file, "main");

    return 1;
}
