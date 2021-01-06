inherit MONSTER;
#include "../path.h"
#define iroom(x)             message("0",wrap(x),ENV(THIS),THIS);
#define pline(x)             message("0",wrap(x),THIS);
#define room(x)              message("0",wrap(x),ENV(THIS));
#define say(x)   THOB->force_us("say "+x);
#define MY_PATH "/home/madrid/agriculture/cure/";
#define POOK_PATH "/home/pook/farms/items/";
mapping crop_map = (["guardiola": ({5,
                "/home/madrid/agriculture/cure/jar_guardiola.c",
                             7}),
                     "red elm bark" : ({5,
               "/home/madrid/agriculture/cure/bark_redelm.c",
                                 7}),
                     "blue mushroom" : ({15,
                "/home/madrid/agriculture/cure/blue_mushroom.c",
                                   8}),
                     "newt eye" : ({2,
                "/home/madrid/agriculture/cure/eye_of_newt.c",
                                      20}),
                     "carvinorax" : ({10,
                "/home/madrid/agriculture/cure/carvinorax.c",
                                 1}),
                 "psylosibin" : ({1,
                 "/home/madrid/agriculture/cure/psylosibin.c",
                                      25}),
                 "astul leaf" : ({15,
                 "/home/pook/farms/items/astul_leaf.c",               
                                     15}),
                 "guyano paste" : ({10, 
                  "/home/pook/farms/items/guyano_paste.c",
                  10}),
                  "pouch of sile" : ({10,
                  "/home/pook/farms/items/sile_pouch.c",
                  12}),
                  "anyhdride vial" : ({8,
                  "/home/pook/farms/items/vial_anhydride.c",
                  6}),
                  "silvergrass" : ({20,
                  "/home/pook/farms/items/silvergrass.c",
                  2}),
                  "morningdew jug" : ({5,
                  "/home/pook/farms/items/jug_morningdew.c",
                  10}),
                  "dog-ear leaf" : ({10,
                  "/home/pook/farms/items/dog-ear_leaf.c",
                  1}),
                  "awnbloom" : ({10,
                  "/home/pook/farms/items/awnbloom.c",
                  5}),
                  "sack of dung" : ({3,
                  "/home/pook/farms/items/rusack_orcdung.c",
                  10}),
                  "dragonroot" : ({30,
                  "/home/pook/farms/items/dragonroot.c",
                  5}),
                  "blue siren" : ({20,
                  "/home/pook/farms/items/bluish_siren.c",
                  5}),
                  "sunburst tulip" : ({10,
                  "/home/pook/farms/items/sunburst_tulip.c",
                  6}),
                  "dawntear jug" : ({7,
                  "/home/pook/farms/items/jug_dawntear.c",
                  4}),
                  "vial of saliva" : ({8,
                  "/home/pook/farms/items/vial_wolfsaliva.c",
                  4}),
                  "pouch of dust" : ({13,
                  "/home/pook/farms/items/pouch_pixiedust.c",
                  12}),
                  "psykmoss" : ({17,
                   "/home/pook/farms/items/psykmoss.c",
                   11}),
                  "wispstone" : ({21,
                  "/home/pook/farms/items/wispstone.c",
                  17}),
                  "brook dust" : ({27,
                  "/home/pook/farms/items/brookdust.c",
                  8}),
                  "faunquartz" : ({10,
                  "/home/madrid/agriculture/cure/faunquartz.c",
                  15}),
                  "frostflower" : ({5,
                  "/home/madrid/agriculture/cure/frostflower.c",
                  8}),
                 "nightwillow" : ({5,
                 "/home/madrid/agriculture/cure/nightwillow.c",
                 25}),
                 "zormroot" : ({10,
                 "/home/madrid/agriculture/cure/zormroot",
                 10}),
                 "wildwool" : ({17,
                 "/home/madrid/agriculture/cure/wildwool.c",
                 15}),
                 "blackrose" : ({3,
                 "/home/madrid/agriculture/cure/blackrose.c",
                 35}),
                 "firefly" : ({50,
                 "/home/madrid/agriculture/cure/firefly.c",
                 1}),
                 "mistflower" : ({20,
                 "/home/madrid/agriculture/cure/mistflower.c",
                 20}),
                 "sorceros root" : ({10,
                 "/home/madrid/agriculture/cure/sorceros_root.c",
                  17}),
                 "unicorn lichen" : ({3,
                 "/home/madrid/agriculture/cure/unicorn_lichen.c",
                 53})]);
   
               
create_monster()
{
  set_short("Gnar Rendarth, an ancient Thari");
  set_name(({"Gnar","gnar","ancient Thari"}));
  set_long(wrap("Gnar is an extremely old and tatered man.  He "+
  "is wearing extremely torn pants and no shirt.  Over "+
  "his sweaty and dirty body is a large bag filled with "+
  "odd shapes of all kinds.  The bag is buldging at "+
  "its sides and looks extremely heavy.\n"));
  set_race("thari");
  set_language("sartog");
  set_talk_delay(20);
  set_talk(({"I have this bag filled with things I carry with me.",
             "This bag is heavy.",
             "If you want to see a list of items in my bag ask me.",
             "I can write a list of the items in my bag very fast.",
             "I have many things in my bag, ask me to list them for you.",
             "I love this bag of tricks i have colleted today.",
             "Today i spent almost three hours in the fields.",
             "I found alot of nice items today.",
             "I just got a new item in my bag today, its lovely.",
             "I carry my bag with me everywhere I go."}));
  set_emote_delay(15);
  set_wander(3,13,({"w","w","s","l books","l window",
             "n","w","e","e","e"}));
  set_emote(({"Gnar adjusts the bag on his shoulder.",
              "Gnar bends down for a second.",
              "The Thari sharpens his pencil.",
              "The old man scibbles something on some paper.",
              "Gnar looks at his bag and writes something down."}));
}
init()
{
  ::init();
  add_action("do_ask","ask");
  add_action("do_buy","buy");
}
do_ask(string what)
{
  if(!what) {
    say("What did you want to ask me about "+THIS->query_cap_name()+
    "?");
     return 1;
  }
  what = capitalize(what);
  if(what == "Gnar for list" ||
  what == "Gnar list" ||
  what == "Gnar for the list" ||
  what == "List" ||
  what == "For the list" ||
  what == "For list" ||
  what == "Gnar about list" ||
  what == "About list" || 
  what == "Gnar to list" ||
  what == "Gnar to list bag" ||
  what == "Gnar to list items" ||
  what == "Gnar for a list of items in his bag" ||
  what == "Gnar for a list of the bag" ||
  what == "For a list of the bag" ||
  what == "For a list of items in the bag" ||
  what == "For a list of items") {
    say("Ah, so you would like to see the list of what i carry in "+
    "this here bag, eh?");
    say("One second "+THIS->query_cap_name()+", let me check my "+
    "bag.");
    room("Gnar searches through his bag and scratches his head for "+
    "a second.  He begins to scribble something down on a piece of paper.\n");
    call_out("do_l",random(15));
    return 1;
  }
  else {
    say("What did you want to ask me about "+THIS->query_cap_name()+
    "?");
    return 1;
  }
}
do_l()
{
  if(ENV(THIS) == ENV(THOB)) {
  room("Gnar finishes writing on the paper and lifts his head.\n");
  say("Here you are "+THIS->query_cap_name()+", this is what I have "+
  "in my little bag of tricks.");
  iroom("Gnar shows a piece of paper to "+THIS->query_cap_name()+
  ".\n");
  pline("Gnar stretches out the piece of paper and lets you read.\n");      
  call_out("do_list",5);
  return 1;
  }
  else 
    return 0;
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
  if(place < 0) {
     say("Sorry "+THIS->query_cap_name()+", I don't carry a "+
     what+" with me usually.");
     return 1;
  }
  else {
   if(!info[place][0]) {
     say("Sorry "+THIS->query_cap_name()+", I don't have a "+
     what+" with me right now.  Check back later please.");
     return 1;
   } 
   if(THIS->query_money()/10 >= info[place][2]) {
      say("Here is your "+what+" "+THIS->query_cap_name()+ 
      ".  I hope it comes in handy.");
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
      say("Sorry "+THIS->query_cap_name()+", you don't have enough for "+
      "a "+what+".");
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
  if(ENV(THIS) != ENV(THOB))
    return 1;
  buf += "\n                        ^cWGnar's Bag of Tricks:^c0\n\n";
  seeds = keys(crop_map);
  info = values(crop_map);
  
 for(i = 0;i<sizeof(seeds);i++) {
 buf += sprintf("Item : %-16s     Quantity: %-3d     Cost : %-3d bronze" 
                   ,seeds[i],info[i][0],info[i][2]);
    buf += "\n";
  }
  pline(buf);
  return 1;
}
