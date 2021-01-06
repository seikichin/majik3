inherit MONSTER;

#include "../path.h";

create_monster()
{
     set_name(({"Filonius", "filonius", "mage" "elf"}));
     set_short("Filonius, the elf mage is bleeding from severe wounds");
     set_long(wrap("Filonius is a very old elf, even for their lifespan. He looks very haggard "+
      "and is bleeding from several wounds. His white robe, which covered most of his body, "+
      "has been torn to shreds. His long, grey hair is a mess and his eyes look a little "+
      "glazed.\n"));

     set_language("alande");

     set_gender (1);
     set_talk(({"I will never bow down to the wretched goblins or anyone who serves them."}));

     set_race ("tanir");
     set_levels(([ "caster" : 45 + random(30) ]));
     
     call_out ("drain_hp", 0);

     add_object(ITEM_PATH + "fring.c");
}

drain_hp ()
{
  /* Bleeding elf in excellent shape? Let's fix it. */

  THOB->damage_me (random(50) + 10);
}
