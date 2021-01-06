#include "../path.h/"
#define room(x)   message("3",x,ENV(THIS),THIS);
#define pline(x)  message("0",x,THIS);
inherit ROOM;
mapping sacrificers;
create_room()
{
  restore_object("/data/misc/madrid_sacrifice.o");
  set_area("temple");
  set_short("^cYThe holy altar of ultimate goodness and nobility^c0");
  set_long("^cYYou are standing in front of an ornate golden altar.  "+
  "It emits complete goodness.  You have to squint your eyes in order "+
  "to hide them from the bright heavenly light that shines upon the "+
  "golden book on the altar.  You can see nothing else around "+
  "you because you are covered in a think white haze^c0.\n");
  set_sounds(40,"You have to squint your eyes for the light.\n");
  add_sound("You want to read the book.\n");
  add_sound("Goodness and virtue fill your mind.\n");
  add_sound("Long golden beams of light shine upon the altar.\n");
  add_sound("The altar is the most beautiful thing you have ever"+
  " seen.\n");
  add_sound("You feel as though you should kneel down to worship.\n");
  add_sound("This is a wonderful place to worship a god.\n");
  add_item("altar","An ornately carved golden altar sits here "+
   "for all good to worship at.\n");
  add_item(({"book","golden book"}),"As you strain your eyes to "+
  "look at the book, you can see a beautiful enscription on the "+
  "top of it which reads:\n ^cyThe Loyal Followers of Goodness^c0\n"+
  "As you scan the exterior of the book you can see a small "+
  "latch that keeps the book closed.\n");
  add_item("latch","This old and frail latch looks as though it "+
  "hasn't been touched in years.  A thought immediately comes to "+
  "your mind that you shouldn't touch it.\n");
  add_exit("sanctum",ROOM_PATH+"sanctum1.c");

}
init()
{
  ::init();
  add_action("do_list","list");
  add_action("do_open","open");
  add_action("do_read","read");
  add_action("do_worship","worship");
  add_action("do_pray","pray");
  add_action("do_say","say");
  add_action("do_sacrifice","sacrifice");
  add_action("do_worship","kneel");
}
do_sacrifice(string foo)
{
  object me, ob;
  me = find_player("madrid");
  if(!sacrificers)
    sacrificers = ([]);
  if(!foo)
  {
    pline("Sacrifice what?\n");
    return 1;
  }
  ob = present(foo, THIS);
  if(!ob)
  {
    pline("You don't have that in your inventory.\n");
   return 1;
  }
  if(!me)
  {
     ob->move("/home/madrid/madrid_temple/rooms/treasure_room.c");
     sacrificers += ([THIS->query_cap_name() : ob->query_short()]);      
     save_object("/data/misc/madrid_sacrifice.o");
     pline("Although Madrid is not here to see your sacrifice he "+
     "will be notified.  Thank You for your support.\n");
    room(THIS->query_cap_name()+" glows for a bit as he raises "+
   ob->query_short()+" into the air.  A heavenly image of "+
  "Madrid appears above the altar and takes it away.\n");
  return 1;
  }
  else
  {
    ob->move(me);
   tell_object(me,THIS->query_cap_name()+" sacrificed "+
   ob->query_short()+"\n"); 
   room(THIS->query_cap_name()+" glows for a bit as he raises "+
   ob->query_short()+" into the air.  A heavenly image of "+
  "Madrid appears above the altar and takes it away.\n");
   pline("Madrid has recieved your sacrifice and is very pleased.\n");
    return 1;
  }
}
do_list()
{
  string *who;
  string *what;
  int i;
  who = keys(sacrificers);
  what = values(sacrificers);
  for(i=0;i<sizeof(who);i++)
  {
    write(who[i]+" sacrificed " + what[i]+"\n");
  }
  return 1;
}
do_say(string args)
{
  if(!args)
    return 0;
  else
  {
    pline("How dare you break the code of silence inside this most holy "+
    "of holy places.  You must be punished for this sin.");
   pline("A beam of golden light comes down and surrounds your body."+
   "  It warms your skin until it almost boils.  The pain makes you "+
   "fall unconscious.\n");
   room("A ray of golden light beams down and surrounds "+
   THIS->query_cap_name()+".  The skin seems to boil a bit.  "+
   "It then falls unconscious.\n");
   call_out("do_punish",1); 
    return 1;
  }
}
do_pray()
{
  object me;
  me = find_player("madrid");
  if(!me)
  {
    pline("You bow your head in prayer.\n");
    room(THIS->query_cap_name()+" bows his head in prayer.\n");
    call_out("do_praying",5);
    return 1;
  }
  else
  {
     pline("You bow your head in prayer.\n");
     room(THIS->query_cap_name()+" bows his head in prayer.\n");
     tell_object(me,THIS->query_cap_name()+" begins prayer to you.\n");   
     call_out("do_praying",5);
     return 1;
  }
  return 0;
}

do_praying()
{
  object me;
  me = find_player("madrid");
  if(!me)
  {
    pline("It seems your prayers have gone unheard.\n");
    return 1;
  }
  else
  {
    pline("Your prayer seems to have been heard.\n");  
    room(THIS->query_cap_name()+" seems to glow a bit.\n");
    return 1;
  }
}
do_read(string what)
{
if(!what)
{
   pline("Read what?\n");
   return 1;
}
if(what == "book")
{
   pline("You lean over towards the book and start to open it.\n");
   room(THIS->query_cap_name()+" leans over to take a look at the "+
   "book.\n");
   call_out("do_book",5);
   return 1;
}
}



do_open(string what)
{
if(!what)
{
   pline("Open what?\n");
   return 1;
}
if(what == "book" || what == "latch")
{
   pline("You lean over towards the book and start to open it.\n");
room(THIS->query_cap_name()+" leans over to take a look at the book.\n");
   call_out("do_book",5);
   return 1;
}
}
do_book()
{
  mapping followers;
  string *who_list;
  string *title_list;
  int i;
  int c;
  followers = "/world/madrid_temple/rooms/cloud.c"->query_followers();
  if(!followers)
  {
    followers = ([]);
    pline("The book seems lifeless.\n");
    return 1;
  }
  who_list = keys(followers);
  title_list = values(followers);
  for(i=0;i<sizeof(who_list);i++)
    {
      if(who_list[i] == THIS->query_cap_name())
      {
       pline("Upon touching the book it desplays its contents to you.\n");
       pline("                            BOOK OF HOLY FOLLOWERS\n");
     pline("---------------------------------------------------"+
           "-----------------------------\n");
       for(c = 0;c<sizeof(who_list);c++)
       {
 pline((c+1)+".                          "+who_list[c]+title_list[c]+"\n");  
       }
       
      pline("---------------------------------------------------"+
            "-----------------------------\n");
       return 1;
      } 
    } 
    pline("Despite the obvious warning you stupidly try to open the "+
     "book.  As you reach out your hand to touch it an instant shock "+
     "rivits up your spin.  Your body starts to tingle and you go "+
     "unconscious.\n");
     room(capitalize(THIS->query_name())+" reaches out its hand "+
     "to attempt to lay them upon the book.  Suddenly you seem him "+
     "shake violently and then go completely limp.\n");
     call_out("do_punish",5);
     return 1;
}
do_worship(string what)
{
  
  object me;
  
  me = find_player("madrid");
  if(!what || what == "madrid")
    if(me)
     {  
        
       tell_object(me,THIS->query_cap_name()+" worshiped you.\n");
       pline("You bow your head and begin a prayer.\n");
       call_out("do_join", 5);
       return 1;
     }
     else
     {
        pline("You bow your head and begin a prayer.\n");
        call_out("do_join", 5);
        return 1;
     }
  pline("Who are you trying to worship?\n")
  return 1;
}
do_join()
{
  object me;
  me = find_player("madrid");
  if(me)
  {
    pline("You feel yourself begin to float up into the air.  "+
    "Higher, and higher you begin to rise.  Through the ceiling "+
    "in the temple and into the sky.  You see below the whole "+
    "of all the lands in the world.  Higher, and higher you "+
    "continue to rise, up into the clouds.  Your head is "+
    "enshrouded in think coulds.  Suddenly to stop your ascent "+
    "and are left levitating upon a cloud.\n");
    room(THIS->query_cap_name()+" kneels down and begins to "+
    "pray.  Suddenly his body begins to rise up.  It continues "+
    "to rise until it leaves through a small rift in the "+
    "ceiling and can no longer be seen.\n");
    THIS->move_player(ROOM_PATH+"cloud.c");
    me->move_player(ROOM_PATH+"cloud.c");
    return 1;
  }
  else
  {
    pline("You feel as though there is no one to hear your prayer.\n");
    room(THIS->query_cap_name()+" kneels down and prays.\n");   
    return 1;
  }
}
do_punish()
{
  object me;
  me = find_player("madrid");
  if(me)
  {
    pline("You wake up in a completely different place.\n");
    room(THIS->query_cap_name()+" disappears into thin air.\n");
    THIS->move_player("/world/hilltop/rooms/hut1.c");
    tell_object(me,THIS->query_cap_name()+" talked or touched book.\n");
    return 1;
  }
  else
  {
  pline("You wake up in a completely different place.\n");
    room(THIS->query_cap_name()+" disappears into thin air.\n");
    THIS->move_player("/world/hilltop/rooms/hut1.c");
    return 1;
  }
}
