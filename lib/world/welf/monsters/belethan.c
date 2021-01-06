inherit MONSTER;


#include "../path.h";
init_monster()
{
    if (THIS->query_name() == "belemar")
    {
	call_out("do_greet", 1);
    }
}
do_greet()
{
    command ("say Father!");
    command ("hug belemar");
}

create_monster ()
{
    set_name (({ "belethan", "elf", "tanir" }));
    set_short ("Belethan the tanir warrior is patrolling here");
    set_long (
      "Belethan is a young warrior and is patrolling the city keeping watch that"
      +" none will break the laws. He has long wavy red hair and keen emerald green"
      +" eyes. He wields his sword with graceful ease.\n");

    set_race ("tanir");
    set_levels (([ "fighter" : 15 ]));
    set_wander (1, random(60) + 60);
    set_gender (1);
    set_language ("alande");
    set_alignx (750);
    set_alignx (600);

    set_talk (({ "Be good, will you?",
	"Sol'daran is peaceful city, better keep it that way....",
	"Enjoy your stay here in Sol'daran."}));

    set_emote (({ "Belethan tightens his grip on his swordhandle.",
	"'I am Belethan, son of Belemar' the elf says "
	+"and bows before you.",
	"The tanir warrior looks at you thoughtfully."}));


    add_weapon (ITEM_PATH + "slongsword.c");
    add_money (random(100));
}
