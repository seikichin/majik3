inherit MONSTER;
mapping followers;
create_monster()
{
  set_name(({"guard","servant","loyal guard"}));
  set_short("A loyal guard of the sun");
  set_long(wrap("This guard is a huge man with bulging muscles.  "+
  "He stands here completely motionless staring off into the "+
  "distance.  He doesn't seem to be focusing on anything.  "+
  "He stands here guarding entrance into the guild.\n"));
  set_talk(({"Choose wisely your path my friend.",
             "We are loyal servants of the sun.",
             "We follow in the path of goodness.",
             "Madrid has shown us the way.",
             "You too can hold the power we do."}));
  set_emote(({"The guard is completely still.",
              "The guard hasn't an expression on his face.",
              "The loyal guard is a wonderful sight.",
              "The guard paces back and forth, guarding the entrance.",
              "The guard walks like a miniture toy soldier."}));
  set_race("celestial dragon");
  set_hp(9999);
}
init()
{
  ::init();
  add_action("do_guild","guild");
}
do_guild()
{
   write("The guard bows to you and allows you to pass.\n");
   return 0;
    /*int i;
   string *who_list;
   followers = "/world/madrid_temple/rooms/cloud.c"->query_followers();
   if(!followers)
     return;
   who_list = keys(followers);
   for(i = 0;i<sizeof(who_list);i++)
   {
     if(capitalize(THIS->query_name()) == who_list[i])
     {
        write(wrap("The guard bows to you and allows you to enter "+
        "the guild room.\n"));
        message("standard",wrap(THIS->query_cap_name()+" bows to the "+
        "the guard and is allowed to enter the guild room.\n"),ENV(THIS),
        THIS);
        return 0;
     }
   }
        write(wrap("The guard snorts, 'Sorry only followers of Madrid"+
        " are allowed into the guild room.'\n"));
        message("standard",wrap(capitalize(THIS->query_name())+" Tries to"+
        " enter the guild room but the guard steps in front and "+
        "snorts, 'Sorry only followers of Madrid are allowed into "+
        "the guild room.'\n"),ENV(THIS),THIS);
        return 1;*/
 }    
