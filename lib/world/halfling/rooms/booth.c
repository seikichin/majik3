// DATE        : Sun Dec  7 22:46:10 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

#include "../path.h"

inherit ROOM;

string *check_array = "/world/halfling/items/regbook.c"->query_members();
string *vote_a_array = ({});
string *vote_b_array = ({});

create_room ()
{
  restore_object("/world/halfling/items/vote_a.o");
  restore_object("/world/halfling/items/vote_b.o");

  set_short ("Voting Booth");
  set_long (
    "You are in the offical voting booth of the Shire. On the far "
  + "side of the room is a counter with two boxes and some paper o"
  + "n it. Above the counter is a sign and a poster.\n");

  add_exit ("north", ROOM_PATH + "road5.c");

  add_item ("sign",
    "This is the voting booth for the citizens of the Shire. You mu"
  + "st be a registered citizen to cast a vote. The current topic, "
  + "if there is one, is on the poster.\n");

  add_item ("poster",
    "The current topic up for a vote is:\n"
  + "Does the Shire need more merchants?\n"
  + "Type 'vote a' for yes or 'vote b' for no.\n");

  set_light (1);

}

init_room()
{
  add_action("do_vote","vote");
  add_action("do_list","list");
}

do_vote(string what)
{
  if(member_array(THIS->query_cap_name(),check_array) > -1)
  { 
    if(what == "a")
    {
     write(wrap("You vote for choice -A- on the current ballot.\n"));
     add_member_a(THIS->query_cap_name());
     save_object("/world/halfling/items/vote_a.o");
     return 1;
    }
    if(what == "b")
    {
     write(wrap("You vote for choice -B- on the current ballot.\n"));
     add_member_b(THIS->query_cap_name());
     save_object("/world/halfling/items/vote_b.o");
     return 1;
    }
    if(what != "a" && what != "b")
    {
     write(wrap("You have not entered a vaild choice for your vote.\n"));
     return 1;
    }
  }
  else
   {
    write(wrap("You must be a registered citizen to vote.\n"));
    return 1;
   }
}

add_member_a(string member) 
{ 
 if(!vote_a_array) 
   {vote_a_array = ({member});}
 else 
   {vote_a_array += ({member});}
}    

add_member_b(string member) 
{ 
 if(!vote_b_array) 
   {vote_b_array = ({member});}
 else 
   {vote_b_array += ({member});}
}    

do_list(string letter)
{
if(THIS->query_cap_name() == "Pook")
{
   if(letter == "a")
   {
    int i;
    for(i = 0;i<sizeof(vote_a_array);i++)
     {
      write(vote_a_array[i]+"\n");
     }
    write(wrap("Total Votes = "+i+"\n"));
    return 1;
   }


  if(letter == "b")
   {
    int i;
    for(i = 0;i<sizeof(vote_b_array);i++)
     {
      write(vote_b_array[i]+"\n");
     }
    write(wrap("Total Votes = "+i+"\n"));
    return 1;
   }
}
}




// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

