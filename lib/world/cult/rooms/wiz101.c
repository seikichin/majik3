inherit "/home/madrid/obj/guild.c";

#include "../path.h"

create_guild()
{
   set_guild("The School of Conjuration");
   set_short("Madrid's room of cocksucking");
   set_long("Madrid comes here when he wants to suck some cock.\n");
   set_levels(({1,2,3,4,5,6,7,8,9,10}));
   set_titles(({"wizard","wizard","wizard","wizard","wizard","wizard","wizard","wizard","wizard","wizard"}));
   set_max_level(10);

   add_avail_skill(1, "make potion", 10);
   add_avail_skill(2, "make potion", 20);
   add_avail_skill(3, "make potion", 30);
   add_avail_skill(4, "make potion", 40);
   add_avail_skill(5, "make potion", 50);
   add_avail_skill(6, "make potion", 60);
   add_avail_skill(7, "make potion", 70);
   add_avail_skill(8, "make potion", 80);
   add_avail_skill(9, "make potion", 90);
   add_avail_skill(10, "make potion", 100);
  
   add_req_skill(1, "make potion", 0);
   add_req_skill(2, "make potion", 10);
   add_req_skill(3, "make potion", 20);
   add_req_skill(4, "make potion", 30);
   add_req_skill(5, "make potion", 40);
   add_req_skill(6, "make potion", 50);
   add_req_skill(7, "make potion", 60);
   add_req_skill(8, "make potion", 70);
   add_req_skill(9, "make potion", 80);
   add_req_skill(10, "make potion", 90);

   set_req_per_level(([ 1 : 1 ]));
}

init_guild()
{
   add_action ("do_info", "info");
   add_action ("do_join","join");
   add_action ("do_advance","advance");
   add_action ("do_members","members");
   add_action ("do_train","train");
}
