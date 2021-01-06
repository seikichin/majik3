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
          file = str;
    }

    file = true_path(file);
    if (file[<3..<1] == ".c") file = file[0..<4];

    if (file_size(file + ".c") < 0)
    {
	notify_fail (file + ".c" + ": not found, sorry.\n");
	return 0;
    }

    notify_fail("Returned 0.\n");
    if (arg)
        i = call_other(file, "main", arg);
    else
        i = call_other(file, "main");

    return i;
}
