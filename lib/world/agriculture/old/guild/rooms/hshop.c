inherit ROOM;
#include "../path.h"

#define room(x)              message("0",wrap(x),ENV(THIS),THIS);
#define say(x)   present("man",ENV(THIS))->force_us("say "+x);

mapping warez_map = (["harvester": ({5,
                             "/home/pook/farms/items/harvester.c",
                             100}),
                     "plow" : ({5,
                                "/home/pook/farms/items/plow.c",
                                50}),
                     "hoe" : ({5,
                              "/home/pook/farms/items/hoe.c",
                              25}),
                     "sickle" : ({5,
                              "/home/pook/farms/items/sicle.c",
                               10}),
                     "jar" : ({10,
                              "/home/pook/farms/items/jar.c",
                              5}),
                     "vial" : ({10,
                               "/home/pook/farms/items/emptyvial.c",
                               5}),
                     "jug" : ({10,
                             "/home/pook/farms/items/jug.c",                   
                             5}),
                     "rusack" : ({10,
                                "/home/pook/farms/items/rusack.c",
                                5}),                   
                     "ownership seal" : ({10,
                     "/home/madrid/agriculture/seal.c",
                     150})]);
create_room()
{
  set_area("farmers");
  set_light(1);
  set_short("Velinax's Supply Store");
  set_long(wrap("This is a small room in which most farmers come "+
  "to buy their items for planting and harvesting crops.  The owner "+
  "of the shop named Velinax Belmonte.  If he is in maybe he will "+
  "sell you a few things.  Other than the sign on the wall there is really "+
  "nothing of interest in this room.\n"));
  add_object(MONSTER_PATH+"man2.c");
  add_item("sign","The sign reads:\n"+
                  "To see what Velinax has in store, type 'list'.\n"+
                  "To buy an item, type 'buy <item name>'.\n");
  add_exit("south",ROOM_PATH+"mill3.c");
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
  seed = keys(warez_map);
  info = values(warez_map);
  place = member_array(what,seed);
  if(!(present("man",ENV(THIS)))){
    write("Sorry but the shopkeeper is out.\n");
    return 1;
  }
  if(place < 0) {
     say("I'm sorry I don't have "+what+" in my inventory at "+
     "the moment.  If you would like to see what I do have in "+
     "inventory look at the sign.");
     return 1;
  }
  else {
    if(THIS->query_money()/10 >= info[place][2]) {
      say("Here is your "+what+" "+THIS->query_cap_name()+ 
      ", have fun.");
      obj = clone_object(info[place][1]);
      obj->move(THIS);
      neg_value = 0 - (info[place][2]*10);
      THIS->add_money(neg_value);
      number = info[place][0];
      number--;
      warez_map[what][0] = number;
      return 1;
    }
    else {
      say("Sorry "+THIS->query_cap_name()+", you don't have enough money "+
      "for that item.");
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
  buf += "\n                           ^cWVelinax's Supply Store:^c0\n\n";
  seeds = keys(warez_map);
  info = values(warez_map);
  
 for(i = 0;i<sizeof(seeds);i++) {
 buf += sprintf("Item Name : %-16s     Quantity: %-3d     Cost : %-3d bronze" 
                   ,seeds[i],info[i][0],info[i][2]);
    buf += "\n";
  }
  write(buf);
  return 1;
}
