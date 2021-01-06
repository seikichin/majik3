inherit ROOM;
#include "../path.h"

#define room(x)              message("0",wrap(x),ENV(THIS),THIS);
#define say(x)   present("man",ENV(THIS))->force_us("say "+x);

mapping crop_map = (["corn seeds": ({15,
                             "/home/pook/farms/items/corn_seeds.c",
                             10}),
                     "barley seeds" : ({15,
                                 "/home/shinael/agri/barley_seeds.c",
                                 15}),
                     "cabbage seeds" : ({15,
                                   "/home/shinael/agri/cabbage_seeds.c",
                                   8}),
                     "carrot seeds" : ({15,
                                      "/home/shinael/agri/carrot_seeds.c",
                                      5}),
                     "green bean seeds" : ({15,
                                 "/home/shinael/agri/green_bean_seeds.c",
                                           12}),
                     "tobacco seeds" : ({15,
                                      "/home/shinael/agri/tobacco_seeds.c",
                                      25}),
                     "tomato seeds" : ({15,
                                     "/home/shinael/agri/tomato_seeds.c",                   
                                     15}),
                     "wheat seeds" : ({15,
                                     "/home/shinael/agri/wheat_seeds.c",
                                     8}),
                      "potato seeds" : ({15,
                                  "/home/pook/farms/items/potato_seeds.c",
                                        5})]);
                   
create_room()
{
  set_area("farmers");
  set_short("Bob's Seed Shop");
  set_long(wrap("This is the shop for farmers to buy seeds for farming."+
  "  The wooden walls here have nice green plants growing on them."+
  "  There is a small counter just next to the eastern wall.  There "+
  "are a few small jars of things on the counter.\n"));
  set_light(1);
  add_object(MONSTER_PATH+"man.c");
  add_item("sign","The sign reads:\n"+
                  "To see what Bob has in store, type 'list'.\n"+
                  "To buy a seed, type 'buy <seed name>'.\n");
  add_item(({"counter","jars","jar"}),"A wooden counter which has a "+
  "few ceramic jars on it, which are locked.  On top of the counter "+
  "is a small sign.\n");
  add_exit("north",ROOM_PATH+"mill2.c");
}
init()
{
  ::init();
  add_action("do_list","list");
  add_action("do_buy","buy");
}
do_buy(string what)
{
  int place,neg_value,number;
  object obj;
  mixed info;
  string seed;
  seed = keys(crop_map);
  info = values(crop_map);
  place = member_array(what,seed);

if(!(present("man",ENV(THIS)))){
   write("Sorry, the shopkeeper is out.\n");
   return 1;
 }
 if(place < 0) {
     say("I'm sorry we don't have "+what+" in store.  If you want "+
     "to know what we have in the store, look at the sign.");
     return 1;
  }
  else {
    if(THIS->query_money()/10 >= info[place][2]) {
      say("Here are your "+what+" "+THIS->query_cap_name()+ 
      ", use them wisely.");
      obj = clone_object(info[place][1]);
      obj->move(THIS);
      neg_value = 0 - (info[place][2]*10);
      THIS->add_money(neg_value);
      number = info[place][0];
      number--;
      crop_map[what][0] = number;
      return 1;
    }
    else {
      say("Sorry "+THIS->query_cap_name()+", you don't have enough money "+
      "for those seeds.");
      return 1;
    }
 }
 return 0;
}      
do_list()
{
  int i;
  string buf = "";
  string *seeds;
  mixed *info;
  buf += "\n                              ^cWBob's Seed Shop:^c0\n\n";
  seeds = keys(crop_map);
  info = values(crop_map);
  
 for(i = 0;i<sizeof(seeds);i++) {
 buf += sprintf("Seed Name : %-16s     Quantity: %-3d     Cost : %-3d bronze" 
                   ,seeds[i],info[i][0],info[i][2]);
    buf += "\n";
  }
  write(buf);
  return 1;
}
