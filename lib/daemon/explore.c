// file name   : /daemon/explore.c
// description : explore daemon, controls the room numbers
// coder       : namhas

int total;
mapping rooms = ([ ]);

void
create ()
{
    restore_object ("/data/misc/explore");
}

int
query_number (string file)
{
    if (member_array(file, keys(rooms)) == -1)
    {
		if (THIS && THIS->query_security() == 0 && file_size (file + ".c") > 0)
		{
            if (file[0..5] == "/world" && !file->query_no_explore())
			{
				total++;
				rooms[file] = total;
				save_object ("/data/misc/explore");
				return total;
			}
		}
    }
    else
		return rooms[file];
}

int
query_total ()
{
    return total;
}

int
teleport (object ob)
{
    string *arr;
    int i;
	
	if (!ob)
		ob = THIS;

    arr = keys(rooms);
    i   = random(sizeof(arr));

    if (file_size(arr[i] + ".c") < 1)
		write (file_name(ob) + ": Something went wrong, inform!\a\n");
    else
		ob->move_player(arr[i]);

    return 1;
}
