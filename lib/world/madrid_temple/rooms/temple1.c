#include "../path.h"
inherit ROOM;
int i;
create_room()
{
  
  set_area("temple");
  set_short("Inside the Temple");
  set_long("You are just inside the temple.  All the walls and "+
  "ceiling are made of beautiful white marble.  There is a small "+
  "stairway containing about 6 stairs that lead up into the inter-"+
  "sanctum of the temple.  This is just the main meeting area "+
  "for all of its "+
  "visitors and worshipers.  Above the entranceway to the interior "+
  "is a large plaque made of purple marble.  To the north lies a "+
  "beautiful wedding chapeel.\n");
  set_light(5);
  add_item("walkway","A walkway leads up the middle of the inter"+
  "-sanctum and to the altar.\n");
  add_item(({"walls","wall","ceiling"}),"The walls and ceiling are "+
  "made of beautiful white and purple marble.\n");
  add_item("stairs","6 marble stairs lead to the inter-sanctum.\n");
  add_item("plaque","A marvelous purple marble plaque hangs above it "+ 
  "reads:\nYou are about to enter the sacred temple of Madrid.  All "+
  "who enter must obey complete silence.\n");
  add_item("stairway","A marble stairway leads up into the "+
  "inter-sanctum of the temple.\n");
  set_sounds(40,"Low and drowling gregorian chant can be heard comming "+
  "from inside the iter-sanctum.\n");
  add_sound("The chilling sound of a pipe organ can be heard.\n");
  add_sound("You think you can hear the sound of angel's trumpets.\n");
  add_sound("You can hear absolutly no talking or other voices from "+
  "inside.\n");
  add_sound("Your body seems to glow a bit as you get closer to the "+
  "inter-sanctum.\n");
  add_sound("You feel so light and carefree you could almost float.\n");
  add_sound("You are at complete peace.\n");
  add_exit("sanctum",ROOM_PATH+"sanctum1.c");
  add_exit("out",ROOM_PATH+"entrance.c");
  add_exit("chapel",ROOM_PATH+"chapel.c");
  add_exit("guild","/home/madrid/guilds/paladins/rooms/guild.c");
  add_object(MONSTER_PATH+"guard1.c");
  add_object(MONSTER_PATH+"guard.c");
}  
init()
{
  ::init();
  add_action("do_enter","sanctum");
}
do_enter()
{
  if(THIS->query_alignx() <= 0 || THIS->query_aligny() <= 0)
  {  
    write("How dare you try to soil the balance and peacefulness "+
    "of this temple with your impurities and sins."+ 
    "  Suddenly a beam of white light surrounds your body.  "+
    "It begins to take over your mind and feelings.  Finally "+
    "it takes over your entire existence and you are helpless.  "+
    "You open your eyes and find yourself somewhere else.\n");
    message("standard","A beam of pure white light zaps down from "+
    "the ceiling and engulfs "+ capitalize(THIS->query_name())+ ".  "+
    capitalize(THIS->query_name())+" begins to shake violently, "+
   "suddenly the light becomes so ^cb^bw^c4bright^c0 you have "+
   "to close your eyes....when you open them nothing is left "+
   "but thick white smoke.\n", ENV(THIS),THIS);
   THIS->move_player("/world/forest/rooms/entrance.c");
   return 1;
 }
 else 
   {
   write("You feel the a glow of white lite surround your body.  "+
   "Alas, you are at peace with your mind as you continue into the "+
   "inter-sanctum of the temple.\n");
   message("standard", capitalize(THIS->query_name())+" begins to "+
   "glow with the most beautiful and illuminous white ligt you have "+
   "ever seen as he enters the inter-sanctum.\n",ENV(THIS),THIS);
   return 0;
   }
}
