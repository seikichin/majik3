inherit "/inherit/guild";
#include "../path.h"
#define pline(x)  message("0",x,THIS);

create_guild()
{
  set_area("university");
   set_short ("University of Agricultural Mastery");
  set_long ("This is a room made of black obsidian and rich "+
  "white marble.  Its ceiling is a dome with heavenly stained "+
  "glass window surrounding it and sheding light to all who "+
  "enter.  An oak bookshelf lines this rooms perimeter and "+
  "is filled with books of all sizes and shapes.  On the "+
  "northern wall is a tall archway leading into some sort of "+
  "lab\n");
  set_light(1);
  add_exit("north",ROOM_PATH+"unihall1.c");
  add_item(({"bookshelf","bookshelves","shelves","shelf","book","books"}),
  wrap("The book shelves are lined around the room and reach about "+
  "2 meters in height.  Each shelf is made of the most beautiful and "+
  "ancient oak you have ever seen.  The shelves are filled with book "+
  "written in old cryptic lettering.  The only ones that seem to "+
  "represent anything you have ever seen before read:\n"+
  "History, Alchemy of Agriculture, Mastery of Agriculture\n"));
  set_guildmaster("granlin");
  add_exit("out",ROOM_PATH+"road7.c");
  add_item(({"window","windows","stained window","glass window"}),
  wrap("The window is made of the most beautiful stained glass in "+
  "the realm.  It is depicting an open field with Madrid stading in "+
  "its interior.  He has his hands raised up to the blue sunny "+
  "skies and blue bolts of energy are streaming from his fingers."+
  "  The field of wheat he is standing in seems to have a golden "+
  "glow surrounding it.\n"));

  add_object(MONSTER_PATH+"granlin.c");
  set_guild("University of Agricultural Mastery");
  set_guild_desc("A pupil of agricultural mastery becomes specialized "+
  "in the basic skills of planting and gathering plants in addition"+
  " to learning to master plant health and its inner power.\n");
  set_titles(({"master farmer",
               "fundamental agriculturist",
               "agriculturist",
               "advanced agriculturist",
               "shaman of plantlife"}));
  set_default_train_msg("You become a bit more adept at [skill_name].\n");
  set_custom_advance_msg("You feel a bit more wise in the ways of agriculture.\n");
  add_avail_skill("planting",({60,70,80,90,100}));
  add_avail_skill("harvesting",({60,70,80,90,100}));
  add_avail_skill("gathering",({50,75,80,95,100}));
  add_avail_skill("weeding",({50,75,80,95,100}));
  add_avail_skill("sowing",({50,75,80,95,100}));
  add_avail_skill("seed knowledge",({0,60,70,80,100}));
  add_avail_skill("irrigation",({50,75,80,85,100}));
  add_avail_skill("plant diagnosis",({35,60,75,90,100}));
  add_avail_skill("remedy plantlife",({30,50,55,85,95}));
  add_avail_skill("create equanshear",({0,15,30,60,80}));
  add_avail_skill("create galiom",({0,15,30,60,80}));
  add_avail_skill("create shaltaar",({0,15,30,60,80}));
  add_avail_skill("create amrin",({0,15,30,60,80}));
  add_avail_skill("create kappa",({0,15,30,60,80}));
  add_avail_skill("create asthmil",({0,15,30,60,80}));
  add_avail_skill("create takhid",({0,15,30,60,80}));
  add_avail_skill("create sirum",({0,15,30,60,80}));
  add_avail_skill("create tarek",({0,15,30,60,80}));
  add_avail_skill("create tethar",({0,15,30,60,80}));
  add_avail_skill("create zanex",({0,15,30,60,80}));
  add_avail_skill("create pukabase",({0,15,30,60,80}));
  add_avail_skill("create ithallon",({0,15,30,60,80}));
  add_avail_skill("create joelinium",({0,15,30,60,80}));
  add_avail_skill("create draken",({0,15,30,60,80}));
  add_req_skill("planting",({50,55,65,80,85,90}));
  add_req_skill("harvesting",({50,55,65,80,85,90}));
  add_req_skill("gathering",({35,50,60,70,80,90}));
  add_req_skill("weeding",({35,50,60,70,80,90}));
  add_req_skill("sowing",({35,50,60,70,80,90}));
  add_req_skill("seed knowledge",({35,50,60,70,80,90}));
  add_req_skill("irrigation",({20,40,50,60,70,80}));
  add_req_skill("plant diagnosis",({20,40,50,60,70,80}));
  add_req_skill("create draken",({0,0,10,25,55}));
  add_req_skill("create zanex",({0,0,10,25,55}));
  add_req_skill("create pukabase",({0,0,10,25,55}));
  add_req_skill("create ithallon",({0,0,10,25,55}));
  add_req_skill("create joelinium",({0,0,10,25,55}));
  add_req_skill("create equanshear",({0,0,10,25,55}));
  add_req_skill("create galiom",({0,0,10,25,55}));
  add_req_skill("create shaltaar",({0,0,10,25,55}));
  add_req_skill("create amrin",({0,0,10,25,55}));
  add_req_skill("create kappa",({0,0,10,25,55}));
  add_req_skill("create asthmil",({0,0,10,25,55}));
  add_req_skill("create takhid",({0,0,10,25,55}));
  add_req_skill("create sirum",({0,0,10,25,55}));
  add_req_skill("create tarek",({0,0,10,25,55}));
  add_req_skill("create tethar",({0,0,10,25,55}));
  add_req_skill("create zanex",({0,0,10,25,55}));
}

init()
{
  ::init();
  add_action("do_read","read");
  add_action("do_info","info");
  add_action("do_join","join");
  add_action("do_train","train");
  add_action("do_advance","advance");
}


do_read(str)
{
  string buf = "";
  if(!str){
    pline("Read what?\n");
    return 1;
  }
  else {
    pline("You open the book and its pages are completely blank.\n");
    return 1;
  }
 str = capitalize(str);
 if(str == "Book" ||
  str == "Books"){
    pline("Read which book?\n");
    return 1;
  }
  else {
    pline("Read what?\n");
    return 1;
  }   
}

