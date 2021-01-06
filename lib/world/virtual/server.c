// file name   : /world/virtual/server.c
// description : the virtual room server
// coder       : namhas

inherit "/inherit/virtual";
inherit "/world/virtual/terrain";

string terrain;
int y, x;

object farm;

query_author(){return "namhas";}

extra_long ()
{
    int y1, x1, j;
    string line1, line2, line3, line4, line5, color, *map;

    line1 = read_world_file (y-2, x);
    line2 = read_world_file (y-1, x);
    line3 = read_world_file (y+0, x);
    line4 = read_world_file (y+1, x);
    line5 = read_world_file (y+2, x);

    line3[x] = '@';

    for (int i=0;i<sizeof(users());i++)
    {
	if (environment(users()[i]))
	{
	    if (sscanf (file_name(environment(users()[i])), "/world/y%dx%d", y1, x1) == 2)
	    {
		if (users()[i] != THIS)
		{
		    if (y1 == (y-2))
			line1[x1] = '&';
		    if (y1 == (y-1))
			line2[x1] = '&';
		    if (y1 == (y+0))
			line3[x1] = '&';
		    if (y1 == (y+1))
			line4[x1] = '&';
		    if (y1 == (y+2))
			line5[x1] = '&';
		}
	    }
	}
    }

    if (line3[x] == '&') line3[x] = '@';

    if (query_light_level() < 1)
      color = "^cL";
    else
      color = "^cg";

    map = explode(colorize (line1[x-4..x+4]) + "^c0\n" +
    colorize (line2[x-4..x+4]) + "^c0\n" +
    colorize (line3[x-4..x+4]) + "^c0\n" +
    colorize (line4[x-4..x+4]) + "^c0\n" +
    colorize (line5[x-4..x+4]) + "^c0\n", "\n");

    j = 0;

    if (farm)
      long_desc = farm->query_long();

    long_desc = wrap(long_desc, THIS->query_columns()-15);

    map[j] += "  ";

    for (int k=0;k<strlen(long_desc);k++)
    {
    if (long_desc[k] == '\n') {
      j++;

      if (j==sizeof(map))
        map += ({"         "});
      map[j] += "  ";
    }
    else
    map[j] += "^cg" + long_desc[k..k] + "^c0";
    }

    return implode(map, "\n") + "\n";
}

do_designate (string str)
{
  mixed retval;

  if (THIS->query_name() != "mummel" && THIS->query_security() < 51)
  {
    write ("Sorry you are not godly enough to do that.\n");
    return 1;
  }

  if (!str) {
    write ("Give map symbol as argument or \"designate save\" to save map.\n");
    return 1;
  }

  if (str == "save") {
    WORLD_D->save_map();
    write ("SAVED.\n");
    WORLD_D->query_info();
    return 1;
  }

  if (pointerp (retval = terrains[str]))
  {
    write ("Designated.\n");
    WORLD_D->set_symbol (y, x, str);
    return 1;
  }

  write ("Failed.\n");
  return 1;
}

do_map (string str)
{
    int y1, x1;
    string *lines, buf;
    int radius, z, n, v, i;
    object *u;

    if ((THIS->query_security() || THIS->query_name() == "lane") && str)
      radius = to_int(str);
    else
      radius = 9;

    if (radius<2 || radius>50)
      {
        write ("Radius too small or large.\n");
        return 1;
      }

    lines = allocate(radius);

    for (i=(y-(radius/2));i<(y+(radius/2));i++)
      {
        lines[v] = read_world_file (i, x);
        v++;
      }

    if (radius != v)
      lines[v++] = read_world_file (i++, x);

    n = v;
    u = users();
    z = sizeof(u);
    v = 0;

    for (int j=0;j<z;j++)
    {
      v = 0;

      if (ENV(u[j]) && sscanf (file_name(ENV(u[j])), "/world/y%dx%d", y1, x1) == 2)
        {
          for (int k=y-radius/2;k<y+radius/2;k++,v++)
            {
              if (y1 == k)
                lines[v][x1] = '&';
            }
        }
    }

    buf = "";
    v = 0;

    lines[radius/2][x] = '@';

    for (int l=0;l<n;l++)
      {
        if (THIS->query("term") == 2)
          buf += colorize(lines[l][x-((radius/2)+3)..x+((radius/2)-1+4)])+"\n";
        else
          buf += lines[l][x-((radius/2)+3)..x+((radius/2)-1+4)] + "\n";
    }

    message ("0", buf + "\n^c0Your place is shown as '^c1@^c0'.  Type '^c1describe^c0' to see what the symbols mean.\n", THIS);
    return 1;
}

init ()
{
  ::init();

  if (farm)
    farm->update_crops ();

  add_action ("do_map", "map");
  add_action ("do_designate", "designate");
  add_action ("do_look", "look");
  add_action ("do_look", "l");
  add_action ("do_look", "la");
}

// *** farm support kludges are (add any if needed):

do_look (string what) { if (farm) return farm->do_look (what); }
query_farm() { if (farm) return farm->query_farm(); }
query_farmer() { if (farm) return farm->query_farmer(); }
set_crop_type(string type) { if (farm) return farm->set_crop_type(type); }
set_creation_time(int time) { if (farm) return farm->set_creation_time (time); }
set_done_time(int time) { if (farm) return farm->set_done_time (time); }
set_crop_stat(int stat) { if (farm) return farm->set_crop_stat (stat); }
set_save_file(string file) { if (farm) return farm->set_save_file (file); }
zero_vars() { if (farm) return farm->zero_vars(); }
do_disease() { if (farm) return farm->do_disease(); }
do_diagnose() { if (farm) return farm->do_diagnose(); }
do_buy(string who, string crop) { if (farm) return farm->do_buy(who,crop); }
do_remedy(string cure) { if (farm) return farm->do_remedy(cure); }
update_crops() { if (farm) return farm->update_crops(); }
debug() { if (farm) return farm->debug(); }
do_harvest() { if (farm) return farm->do_harvest(); }
do_plant() { if (farm) return farm->do_plant(); }
do_irrigate() { if (farm) return farm->do_irrigate(); }
create_room() { if (farm) return farm->create_room(); }
init_room() { if (farm) return farm->init_room(); }

// ***

create_virtual (string path)
{
    string map_file, terrain_file, save_file;
    object ob;

    set_outdoors (4);

    set_short   ("Virtual object #" + getoid (this_object()));
    set_long ("Virtual object #" + getoid (this_object()) + "\n");

    if (path[0] != '/') path = "/" + path;

    if (path[0..7] == "/world/y")
    {
	if (!sscanf(path, "/world/y%dx%d", y, x) == 2)
            return 0;

        set_area ("world");
	map_file = read_world_file (y, x);
	terrain = get_terrain (map_file[x..x]);

	set_short ("The " + terrain);
        set_long ("You are standing in the "+terrain+".");

        if (terrain == "river")
          set_water (30 + random(50));

        if (terrain == "deep river")
          set_water (150 + random(250));

        if (terrain == "sea")
          set_water (1000 + random(10000));

        if (terrain == "lake")
          set_water (100 + random(500));

        THOB->set_weather_zone (x/103, y/103);

        if (!cache[terrain])
          {
            terrain_file = "/world/virtual/terrain/"+replace_string(terrain, " ", "_") + ".txt";
            if (file_size(terrain_file) > 1)
              cache[terrain] = replace_string(read_file(terrain_file), "\n", " ");
          }

        if (cache[terrain])
          set_long (cache[terrain]);

        add_exit ("north",     "/world/y"+(y-1)+"x"+(x+0));
        add_exit ("west",      "/world/y"+(y+0)+"x"+(x-1));
        add_exit ("south",     "/world/y"+(y+1)+"x"+(x+0));
        add_exit ("east",      "/world/y"+(y+0)+"x"+(x+1));
        add_exit ("northwest", "/world/y"+(y-1)+"x"+(x-1));
        add_exit ("northeast", "/world/y"+(y-1)+"x"+(x+1));
        add_exit ("southwest", "/world/y"+(y+1)+"x"+(x-1));
        add_exit ("southeast", "/world/y"+(y+1)+"x"+(x+1));

        if (map_file[x] == 'y') {
          set_no_clean_up (1);
          farm = clone_object ("/world/agriculture/farm");
          farm->set_save_file ("/world/agriculture/save/y"+y+"x"+x+"");
          farm->restore();
          farm->config(THOB);
          farm->init();
          farm->create_room();
        }
        else if (file_size("/world/virtual/y"+y+"x"+x+".c") > 0) {
          ob = load_object ("/world/virtual/y"+y+"x"+x+"");
          ob->config(THOB);
        }

	map_file[x] = '@';

        return THOB;
    }
    else return 0;
}

string
query_terrain ()
{
    return terrain;
}
