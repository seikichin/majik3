inherit "/inherit/guild";
#include "../path.h"
#define pline(x)  message("0",x,THIS);

create_guild()
{
  set_area("farmers");
   set_short ("School of Elementary Agriculture");
  set_long (
    "You are inside a small log cabin. On the south side of the room"
  + " there is a large bookshelf cluttered with a few thick books.  "+
    "The interior of the room is filled with desks for students to "+
    "sit in and a podium at the front of the room.  There is nothing "+
    "else of interest in the room.\n");
  add_exit ("out", ROOM_PATH + "road10.c");
  set_light(1);
  add_item ("podium",
  "The podium is very slim with a flat surface on top for books a"
  + "nd papers. It is a little over a meter high.\n");
  add_item(({"desk","desks"}),"The desks are just pieces of wood "+
  "elevated above a small wooden chair.\n");
  add_item (({"bookshelf","bookshelves","shelves","shelf","book","books"}),
   wrap("The bookshelf is about 5 meters high and is "+
  "cluttered with books.  The books are labled: Barley, Cabbage, Carrots, "+
  "Corn, Green beans, Potatoes, Tobacco, Tomatoes, Wheat and History.\n"));
  add_object(MONSTER_PATH + "farmer.c");
  set_guild("School of Elementary Agriculture");
  set_guildmaster("jerry");
  set_guild_desc("A student of elementary agriculture becomes fluent "+
  "in the basic skills of planting and gathering plants.\n");
  set_titles(({"hillbilly","redneck","gatherer","sower","farmer"}));
  set_default_train_msg("You become a bit more adept at [skill_name].\n");
  set_custom_advance_msg("You feel a bit more wise in the ways of agriculture.\n");
  add_avail_skill("planting",({10,15,25,45,50}));
  add_avail_skill("harvesting",({10,15,25,45,50}));
  add_avail_skill("gathering",({0,5,20,30,45}));
  add_avail_skill("weeding",({0,5,20,30,45}));
  add_avail_skill("sowing",({0,5,20,30,45}));
  add_avail_skill("seed knowledge",({0,5,20,30,45}));
  add_avail_skill("irrigation",({0,0,10,15,20}));
  add_avail_skill("plant diagnosis",({0,0,0,10,25}));
  add_req_skill("planting",({0,7,12,15,25,40}));
  add_req_skill("harvesting",({0,8,12,15,25,40}));
  add_req_skill("gathering",({0,0,3,14,25,35}));
  add_req_skill("weeding",({0,0,3,14,25,35}));
  add_req_skill("sowing",({0,0,3,14,25,35}));
  add_req_skill("seed knowledge",({0,0,3,14,25,35}));
  add_req_skill("irrigation",({0,0,0,7,10,14}));
  add_req_skill("plant diagnosis",({0,0,0,0,7,10}));
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
  str = capitalize(str);
  if(str == "History") {
  buf="You open the book labled 'History' and begin to read:\n\n";
  buf+=wrap("                  ^cWA Historical Account of Agriculture (Vol. 1)^c0\n\n"+
  "     The history of agriculture dates back to the creation of this "+
  "world.  Soil, the basis of all agriculture, was created when a diabolic "+
  " tempest summoned by Sinister to drown out the infinate light of Aluna"+ 
  " fell upon this world.  This tempest of ice, snow, and rain completely "+
  "enshrouded our plane.  As it melted into the ground it began to add "+
  "nutrients and valuable fuel for growth to its compsure.  Soon after, "+
  "small green substances began to grow from the new soil.  Sinister "+
  "became enraged to see that what he had intended to drown out light "+
  "and life as we know it, only brought about a new form of life that "+
  "grew from the ground.  This phenomenon "+
  " brought about a new power into this realm.  A power which could "+
  "be harnessed and controled.  A wise old human soon began to harvest "+
  "this new material and wonder what it could be used for.  In his "+
  "sleep an aparition of Madrid appeared to him and said this new material "+
  "can now be used as a fuel for your life.  The man awoke the next morning "+
  "with a complete knowledge of planting and reaping this new material.  "+
  "This man, to us know as Jerry Garcia, opened a school of knowledge and "+
  "deemed it beneficial to the realm if he would share his knowledge.  "+
  "This school of knowledge became to be known as the Elementary School "+
  "of Agriculture.  All of its students become fluent in the knowledge "+
  "of agriculture.  It is Jerry's hope that one day all would know how "+
  "to make plants and how to conserve this worlds resources.  This is "+
  "his mission, and all who are his students.\n"); 
  buf+="\n\nYou can do the following things here:\n"
  + "Join - Join the School of Elementary Agriculture\n"
  + "Advance - Advance your knowledge of agriculture\n"
  + "Train - Train the skills that Jerry teaches\n"
  + "Info - Information on the school\n";
  pline(buf);
  return 1;
  }
  if(str == "Barley") {
    buf="You open the book labled 'Barley' and begin to read:\n";
    buf += wrap("                                    ^cWBarley^c0\n\n"+
    "     Barley is a tall brown grain crop.  This "+
    "grain is much like its brother plant, wheat.  They both take "+
    "nearly the same amount of time to mature.  Unlike wheat, however"+
    ", it is better planted at the begining of a spring or autumn season."+
    "  Once harvested it produces a rich grain that is the basis of many "+
    "foods and drinks.\n");
    pline(buf);
    return 1;
   }
  if(str == "Wheat")
  {
    buf="You open the book labled 'Wheat' and begin to read:\n";
    buf += wrap("                                    ^cWWheat^c0\n\n"+
    "     Wheat is a tall yellow grain crop.  This grain is "+
    "much like its sister plant barley.  It takes a rather long time "+
    "to harvest this plant.  It is best planted during the end of a "+
    "spring or autumn season.  If harvested properly, it produces a "+
    "thick nutritious grain.  This grain acts a a corner stone in almost "+
    "all of our foods today.\n");
    pline(buf);
    return 1;
  }
  if(str == "Tobacco") {
    buf="You open the book labled 'Tobacco' and begin to read:\n";
    buf += wrap("                                    ^cWTobacco^c0\n\n"+
    "     Tobacco is a short black and extremely leafy plant."+
    "  It stands about 1 meter in height and has short and stocky black "+
    "leaves.  It is able to be planted during the warmest periods of "+
    "the summer.  It takes a moderate amount of time for this plant "+
    "to ripen.  When harvested, its leaves are striped from their bases "+
    "and dried.  This new dried tobacco is smoked and chewed by people "+
    "throughout the realm.  It is a very valuable and rare crop.\n");
    pline(buf);
    return 1;
  }
if(str == "Carrots") {
  buf="You open the book labled 'Carrots' and begin to read:\n";
  buf += wrap("                                     ^cWCarrots^c0\n\n"+
  "     Carrots are a small tuber plant.  Tubers are plants in which "+
  "their end product, or meat, grows into the soil instead of above "+
  "the soil like many other plants.  Carrots can be planted anytime "+
  "during the spring and summer seasons.  When ripe and pulled from "+
  "the ground a short and sometimes fat tuber is discovered.  The "+
  "carrot can then be cooked or eaten raw.  It is used in many dishes "+
  "around the world and is also frequently eaten on its own.\n");
  pline(buf);
  return 1;
}
if(str == "Cabbage") {
  buf="You open the book labled 'Cabbage' and begin to read:\n";      
  buf += wrap("                                     ^cWCabbage^c0\n\n"+
  "     Cabbage is a green extremely round and small plant.  It "+
  "can be planted during the late summer and early autumn seasons.  "+
  "Cabbage grows into a small head type crop with thickly bound green "+
  "leaves.  Once harvested, it is usually cooked and its leaves are "+
  "seperated and boiled.  It can then be eaten as is or served with a "+
  "wide variety of other foods.\n");
  pline(buf);
  return 1;
 }
 if(str == "Potatoes") {
  buf="You open the book labled 'Potatoes' and begin to read:\n";
  buf += wrap("                                     ^cWPotatoes^c0\n\n"+
  "     Potatoes are a round and small tuber plant.  It is planted "+
  "solely during the summer months.  While growing it forms a tight "+
  "web of vines that lead to each individual potato that is growing "+
  "below the ground.  After this crop is reaped from the soil and "+
  "detatched form its vines, it is usually boiled and eaten in many "+
  "differnt ways.  Potatoes are the basis of many tribes diets because "+
  "of their rich nutritional value.\n");
  pline(buf);
  return 1;
}
if(str == "Tomatoes") {
  buf="You open the book labled 'Tomatoes' and begin to read:\n";
  buf += wrap("                                    ^cWTomatoes^c0\n\n"+
  "     Tomatoes are small round red and delicate plants.  They are "+
  "only planted during spring months of the year.  Once planted the "+
  "begin to grow a think net of vines that grow about 1 meter tall.  "+
  "Soon the vines produce a small red juicy fruit called the tomato.  "+
  "It has been the despute many of agriculturists if a tomato was a fruit "+
  "or a vegetable.  The writers of this book believe it to be a fruit.  "+
  "When ripe, this fruit is picked and eaten raw or cooked.  It is an "+
  "extremely refreshing plant because it is filled with juice.\n");
  pline(buf);
  return 1;
 }
if(str == "Corn") {
buf = "You open the book labled 'Corn' and begin to read:\n";
buf += wrap("                                       ^cWCorn^c0\n\n"+
"    Corn is a tall slim plant which grows straight up from the ground and "+
" not out to either side.  They have been know to grow as high as two "+
"meters.  The edible part grows onthe top portion and is known as an ear."+ 
"  After being unwrapped from its skin like covering, the ear may be cooked"+
" and then eaten. Corn, being a fairly enduring crop, will grow in "+
"all seasons, except winter. It is also know as quite a nourishing"+ 
" healthy food source.\n");
  pline(buf);
  return 1;
 }
 if(str == "Green beans") {
   buf = "You begin to open the book labled 'Green beans' and begin to read:\n";
   buf +=wrap("                                     ^cWGreen Beans^c0\n\n"+
   "     A good source of vitamins, green beans are a popular crop "+
   "among farmers. The plant grows in a wide, flat pattern and tends"+
   " to almost completly cover the area in which it is growing.  The "+
   "beans themselves, are slim green vegatables which are pretty "+
   "small, but are produced in large numbers by each plant. The plants "+
   "also commonly have large, flimsy leaves and short, thick stems.  "+ 
   "Being a tempermental and fairly fragile plant it only grows "+
   "well late in the year. Autumn is the only time a farmer can"+
   " harvest them in adequate numbers.\n");
   pline(buf);
   return 1;
 }

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

