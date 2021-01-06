#include "../path.h/"
inherit ROOM;
mapping followers;
create_room()
{
  restore_object("/data/misc/madrid.o");
  set_area("temple");
  set_short("High up in the heavens, atop a cloud");
  set_light(5);
  set_long("You are floating high up in the sky, in the middle "+
  "of a very dense and think cloud.  The wind is unusually warm "+
  "and comforting.  This is truly as close to heaven as you have "+
  "you shall ever get.\n");
  add_exit("down",ROOM_PATH+"entrance.c");
  add_item(({"cloud","clouds"}),"The clouds are whte and fluffy.  "+
  "You feel as though you should never leave this wonderfuf place.\n");
  set_sounds(40,"A large and fluffy cloud floats through your body"+
  " making you tickle.\n");
  add_sound("A small quartet of angels circle Madrid's head.\n");
  add_sound("Madrid floats around the room.\n");
  add_sound("You can almost see right through Madrid's body.\n");
  add_sound("A warm breeze makes you feel comfortable.\n");
  add_sound("Madrid's eyes glow as bright as gold.\n");
  add_sound("You can feel the strong holy aura surrounding "+
  "Madrid.\n");
  add_sound("Madrid smiles lovingly at you.\n");
}
init()
{
  ::init();
  add_action("do_add","add");
  add_action("do_list","list");
}
do_add(string args)
{
  string arg1;
  string arg2;
  sscanf(args, "%s %s", arg1, arg2); 
  if(!followers)
  {  
     arg1 = capitalize(arg1);
     followers = ([arg1 : arg2]);
     write(arg1+" added to list as "+arg2+"\n");
     save_object("/data/misc/madrid.o");
     return 1;
  }
  else
  {
    arg1 = capitalize(arg1);
    followers += ([arg1 : arg2]);
    write(arg1+" added to list as "+arg2+"\n");
    save_object("/data/misc/madrid.o");
    return 1;
  }
  return 0;
 }
do_list()
{
  int i;
  string *who_list;
  string *title_list;
  if(!followers)
     followers = ([]);
  who_list = keys(followers);
  title_list = values(followers);
  for(i = 0;i<sizeof(who_list);i++)
  {
    write((i+1)+".                      "+who_list[i]+title_list[i]+"\n");
  }
  return 1;
}      
mapping query_followers()
{
  return followers;
}
