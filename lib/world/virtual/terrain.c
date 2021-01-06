// file name   : /world/virtual/terrain.c
// description : terrain inheritable to handle terrains, saves memory
// coder       : namhas

inherit ROOM;

static mapping terrains;
static mapping cache;

void
create ()
{
    ::create();

    cache = ([ ]);

    terrains = ([
      "!" : ({ "peak",                    "^cw" }),
      "=" : ({ "bridge",                  "^cL" }),
      "x" : ({ "badlands",                "^cR" }),
      "y" : ({ "field",                   "^cy" }),
      "z" : ({ "shore",                   "^cY" }),
      "#" : ({ "ruins",                   "^cL" }),
      "S" : ({ "shallow",                 "^cc" }),
      "V" : ({ "volcano",                 "^cr" }),
      "^" : ({ "mountain",                "^cP" }),
      "b" : ({ "beach",                   "^cy" }),
      "d" : ({ "desert",                  "^cy" }),
      "F" : ({ "deep forest",             "^cg" }),
      "f" : ({ "forest",                  "^cG" }),
      "h" : ({ "hills",                   "^cp" }),
      "i" : ({ "highlands",               "^cp" }),
      "j" : ({ "jungle",                  "^cg" }),
      "l" : ({ "lake",                    "^cb" }),
      "p" : ({ "plain",                   "^cG" }),
      "R" : ({ "deep river",              "^cb" }),
      "r" : ({ "river",                   "^cb" }),
      "s" : ({ "swamp",                   "^cR" }),
      "t" : ({ "tundra",                  "^cw" }),
      "g" : ({ "glacier",                 "^cw" }),
      "v" : ({ "valley",                  "^cG" }),
      "w" : ({ "waterfall",               "^cC" }),
      "~" : ({ "sea",                     "^cb" }),
      "-" : ({ "road",                    "^cL" }),
      "|" : ({ "road",                    "^cL" }),
      "/" : ({ "road",                    "^cL" }),
      "\\": ({ "road",                    "^cL" }),
      "+" : ({ "crossing",                "^cL" }),
      "c" : ({ "city",                    "^cL" }),
      "C" : ({ "player city",             "^cL" }),
      "?" : ({ "scenic location",         "^cW" }),
      "%" : ({ "special location",        "^cW" }),
      "&" : ({ "another player",          "^cW" }),
      "L" : ({ "lava",                    "^cR" }),
      "O" : ({ "oasis",                   "^cb" }),
      "@" : ({ "player",                  "^cW" }) ]);
}

string
read_world_file (int y, int x)
{
    string poks;

    poks = WORLD_D->query_world (x, y);

    return poks;
}

string
get_terrain (string ch)
{
    mixed retval;

    if (pointerp (retval = terrains[ch]))
	return retval[0];
    return "formless void";
}

string
colorize (string str)
{
    string buf;
    mixed retval;
    int j, k;

    buf = "";

    j = strlen(str);

    for (int i=0;i<j;i++)
    {
	if (pointerp (retval = terrains[str[i..i]])) {

            if (str[i] != str[i+1])
              k = -1;

            if (k>0)
              buf += str[i..i];
            else
              {
                if (i-1 > -1 && str[i-1] == str[i])
                  buf += str[i..i];
                else if (retval[1][2] < 97)
                  buf += retval[1] + str[i..i];
                else
	          buf += "^c0" + retval[1] + str[i..i];

                k++;
              }
        }
	else
	    buf += "^cb~";
    }
    return buf;
}

do_describe ()
{
    int i;
    string result;
    string *arr;

    result = "";

    result += sprintf ("^c0^cW^bb%4s %29s          %4s %29s^c0\n",
      "code", "terrain type",
      "code", "terrain type");

    if (arr = keys (terrains))
    {
	for (i=0;i<sizeof(arr);i++)
	{
	    if (i%2)
		result += "          ";

            if (THIS->query("term") == 2) {
	    result += sprintf ("%s%4s^c0 %29s", terrains[arr[i]][1], arr[i],
	      terrains[arr[i]][0]);
            }
            else
            result += sprintf ("%4s %29s", arr[i], terrains[arr[i]][0]);

	    if (i%2)
		result += "\n";
	}
    }
    message ("0", result + "\n", THIS);
    return 1;
}

init ()
{
    ::init ();

    add_action ("do_describe", "describe");
}
