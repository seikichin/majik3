// file name   : /daemon/world.c
// description : world daemon for virtual world map system, saves memory
// coder       : namhas

static string *world;

static int max_y, max_x;

void
create ()
{
  int lines;

  write ("The world seems quickly materialize under your feet as you step on the void.\n");

  lines = file_length ("/world/virtual/MAP");

  world = allocate (lines);
  world = explode(read_file ("/world/virtual/MAP"), "\n");

  max_y = sizeof (world);
  max_x = strlen (world[0]);
}

string
query_world (int x, int y)
{
  if (y<=0 || y>=max_y)
    return repeat_string("~", max_x*2);
  else

    return world[y];
}

set_symbol (int y, int x, string s)
{
  world[y][x] = s[0];
}

save_map ()
{
  cp ("/world/virtual/MAP", "/world/virtual/MAP~");  
  rm ("/world/virtual/MAP");
  write_file ("/world/virtual/MAP", implode(world, "\n"));
}

int
query_max_y ()
{
  return max_y;
}

int
query_max_x ()
{
  return max_x;
}

info ()
{
  write ("/world/virtual/MAP: "+max_y+"x"+max_x+" ("+(file_size("/world/virtual/MAP")/1024)+" kB, "+(max_y*max_x)+" rooms)\n");
  return 1;
}

