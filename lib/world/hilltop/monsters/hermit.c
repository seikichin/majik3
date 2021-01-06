/*
 * Application hermit
 * */

inherit MONSTER;

#include "../path.h"

string *receivers;

#define SAY(x) "/command/mortal/say"->main(x)
#define room(x) message("3", x, environment(THIS), THIS);
#define pline(x) message("0", x, THIS);

create_monster()
{
    set_name(({ "old hermit", "hermit", "an old hermit", "thari", "human" }));
    set_short("an old hermit muttering to his beard");
    set_long("He looks like he has been here for ages. He has a long " +
      "beard which reaches down to his waist. He's trying to fill " +
      "somekind of application with an old feather. It seems he has " +
      "ran out of ink long long time ago. Next to him there is a stack " +
      "of papers.\n");
    set_race ("thari");
    set_gender (1);

    set_talk(({
	"Someday I will be a wizard!", 
	"Just after I have filled this application!", 
	"I know it!!",
	"Maybe I'll soon be greater than Namhas itself!",
	"I wish I already were a wizard.", 
	"If I would just get this application filled.",
	"This application shouldn't have any errors on it!",
	"I hope I get this right before I run out of applications."     }));
    set_emote(({
	"Hermit growls and crumples the application form and throws it into the corner.",
	"Hermit starts filling a new application.",
	"The hermit curses something about ink.",
	"Old hermit glances up and quietly whispers something." }));

    receivers = ({ });
}

init_monster()
{
  add_action("do_ask", "ask");
}

do_ask(string args)
{
    object ob;

    if (args == "hermit for application" ||
      args == "hermit for form" ||
      args == "application from hermit" ||
      args == "form from hermit" ||
      args == "for application" ||
      args == "for form" ||
      args == "form" ||
      args == "application")
    {
	if (member_array(THIS->query_name(), receivers) != -1)
	{
	    SAY("But I already gave you one!\n");
	    return 1;
	}

        SAY ("Here you are, " + capitalize(THIS->query_name()) + "!");
        pline ("Hermit gives you an application.\n");
        room ("Hermit gives " + capitalize(THIS->query_name()) + " an application.\n");
	ob = clone_object(ITEM_PATH + "wizapp.c");
	ob->move(THIS);
	receivers += ({ THIS->query_name() });
    }
    else {
        SAY ("What do you want, " + capitalize(THIS->query_name()) + "?");
    }
    return 1;
}
