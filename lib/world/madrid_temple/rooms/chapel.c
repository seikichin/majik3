/* wedding chapel object
*
*  Coder: Madrid
*
*/
#include "../path.h"
inherit ROOM;
#define room(x)   message("3",x,ENV(THIS),THIS);
#define pline(x)  message("0",x,THIS);
create_room()
{
  set_area("temple");
  set_short("A beautiful wedding chapel");
  set_long("You have entered a small but ornately decorated "+
  "wedding chapel.  There is a large pipe organ on the "+
   "altar that plays the music.  The chapel is completely "+
   "done in white and looks beautiful.  There is going to "+
   "be a wedding today it seems.\n");
  add_exit("out",ROOM_PATH+"temple1.c");
   set_light(5);
 
}
init()
{
  ::init();
  add_action("do_marriage","marry");
}
do_marriage(string who)
{
  object me,ob,them;
  string sex;
  me = find_player("madrid");
  them = find_player(who);
  if(them->query_gender() == 1)
  {
    sex = "his";
  } 
  if(them->query_gender() == 2)
  {
    sex = "her";
  }
  if(them->query_gender() == 0)
  {
    sex = "its";
  }
  if(!(present(who,ENV(THIS))))
  {
    pline("They aren't here.\n");
    return 1; 
 }
  
  if(!me)
  {
     pline("No one is here to do the ceremony, try again later.\n");
     return 1; 
  }
  if(THIS->query_married())
  {
    pline("Sorry but you are married and cannot marry another.\n");
    return 1;
  }
  if(them->query_married())
  {
    pline(capitalize(who)+" is already married and cannot marry "+
    "another.\n");
    return 1;
  }
        tell_object(me,THIS->query_cap_name()+" wants to marry "+
        capitalize(who)+".\n");
        pline("You bow down and ask "+capitalize(who)+" to marry "+
        "you.\n");
        room(THIS->query_cap_name()+" bows down and asks "+ 
        capitalize(who)+" for "+sex+" hand in marriage.\n"); 
       ob = clone_object("/home/madrid/madrid_temple/monsters/image.c")->   
        move(ENV(THIS));
    if(!(present(me,ENV(THIS))))
    {  
      pline("An image of Madrid has come here to oversee the ceremony"+
        " but you must now wait for the real Madrid to arrive and "+
        "then perform the ceremony again.\n");
        return 1;
     }  
     else
     {   
      message("0","Wedding bells begin to chime in the distance.\n",
        users());
        call_out("do_msg1",5);
        call_out("do_msg1",15);
        call_out("do_msg1",25);
        call_out("do_msg1",35);
        call_out("do_msg1",45); 
       call_out("do_msg1",55);
      call_out("do_msg1",65);
      call_out("do_msg1",75);
      call_out("do_msg1",85);
      call_out("do_msg1",95);
     call_out("do_msg1",105);
      call_out("do_msg1",115);
      call_out("do_msg1",125);
      call_out("do_msg1",136);
      message("0","As the final wedding bell tolls you see an image "+
              "of "+THIS->query_cap_name()+" high in the heavens "+
              "kneeling before "+capitalize(who)+" asking for "+
              sex+" hand in marriage.  Suddenly a gentle white light "+
        "begins to surround them.  They bring their mouths together for "+
        "a most beautiful kiss.  As their lips touch they both glow for "+
        "for a moment.  A voice echos 'Let it be known that from this "+
        "day forth "+THIS->query_cap_name()+" and "+capitalize(who)+
        " are one.  Then the sky goes dark.\n",users());
        THIS->set_married(1);
        them->set_married(1);
        THIS->set_spouse(capitalize(who));
        them->set_spouse(capitalize(THIS->query_name()));        
        return 1;
      }
}       
do_msg1()
{
  message("0","Wedding bells are ringing in the distance.\n",
  users());
  return 1;
}

