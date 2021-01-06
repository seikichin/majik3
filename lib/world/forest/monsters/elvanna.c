inherit MONSTER;

#include "../path.h";
#define say(x) "/command/mortal/say"->main(x)

string *quest_array = ({});

create_monster()
{
     restore_object(MONSTER_PATH + "elvanna_quest.o");

     set_name(({"elvanna", "queen", "elvanna" }));
     set_short("Elvanna, queen of the Tanir elves, sits here in despair");
     set_long(wrap("Elvanna's beauty leaves you unable to move. You stand there, staring at "+
      "her. Her eyes are bright green and her hair is silver. She is wearing a long green "+
      "robe which covers her completly. On her head is a golden crown with a symbol of a moon "+
      "set in the front.\n"));

     set_emote(({"Elvanna stares blankly into the forest.", 
                 "Elvanna sighs, a deep hopeless sigh."}));

     set_gender (2);

     set_language("alande");

     set_talk_delay(15);

     set_talk(({"We must get into the tower and save Filonius.",
                "If anyone wants to voluteer for the quest just ask me about it.",
                "We need someone to enter the tower and help Filonius."}));     

     set_race ("tanir");
     set_levels(([ "caster" : 40 + random(10), "fighter" : 15 + random(5) ]));
     add_money (0 + random(10));

     add_answer("quest",
       "The goblins are trying to take our beloved tower, and the forest along with "
     + "it, away from us. We need a brave adventurer, such as yourself, to enter "
     + "the tower and help Filonius defeat whatever is holding him there. If he is "
     + "freed from his captor, we could surely drive the goblins from the forest. "
     + "If you wish to attempt his rescue just type 'accept quest'");

     add_answer("porthios",
       "You must find Porthios as your first step to save Filonius. He holds vital "
     + "information, which you will need. He is currently in one of the treehouse "
     + "lookouts, above the forest floor. You can reach them by climbing some of "
     + "larger trees in the forest.");
}

init()
{
   ::init();
   add_action("do_accept","accept");
}

do_accept(string thing)
{
  if(!thing)
  {return 0;}

  if(thing != "quest")
  {
    notify_fail ("Accept what?\n");
    return 0;
  }

  if(thing == "quest")
  {
    int i;
    for(i = 0;i<sizeof(quest_array);i++)
    {
      if(quest_array[i] ==  THIS->query_cap_name())
       {
        say(THIS->query_cap_name()+", I have already given you all the help I can.");
        return 1;
       }
     }
   say("Thank you for accepting such a perilous quest. First, you must find my son, Porthios. "
   + "He is in one of the treehouse look outs. I have given you a pendant. You must show "
   + "that to him so he will known that I sent you. He will then give you something to help "
   + "complete the quest. If you want some more information about Porthios, just ask.");
   add_member(THIS->query_cap_name());
   save_object(MONSTER_PATH + "elvanna_quest.o");
   clone_object(ITEM_PATH+"pendant.c")->move(THIS);
   return 1;
  }
}

string *query_members() {return quest_array;}
add_member(string member) 
{ 
 if(!quest_array) 
   {quest_array = ({member});}
 else 
   {quest_array += ({member});}
}    

