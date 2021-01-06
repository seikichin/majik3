/*Test object for farmland system
 Coder : Some Fucker
*/


/* available crops going to be:
**  1.  Corn    -      spring, summer, autumn
    2.  Cabbage -      summer, autumn
    3.  Potatoes -     summer
    4.  Wheat    -     autumn, spring            ****** All lower case :)
    5.  Barley   -     autumn, spring      
    6.  Tobacco  -     summer
    7.  Tomatoes -     spring
    8.  Carrots  -     spring, summer
    9.  Green Beans -  autumn
*/

inherit ROOM;
#define pline(x) message("0", x, THIS)
#define room(x) message("0", x, ENV(THIS), THIS)

/*disease arrays for crops*/
string *crops = ({"corn",
               "cabbage",
               "potatoes",
               "wheat",
               "barley",
               "tobacco",
               "tomatoes",
               "carrots",
               "green beans"});
string *disease_type = ({"club root",
                    "late blight",
                    "mildew",
                    "hemilieia vastherix",
                    "fig warts",
                    "peach yellows",
                    "tobacco mosaic",
                    "potato-leaf roll",
                    "curley top",
                    "fire blight",
                    "vegatable cankers",
                    "crown gall",
                    "common scabs",
                    "angular leaf spots", 
                    "black rot"});

/*global variables*/

int irrigate_done;
int original_cstat;
int remedy;
int harvested;
int period1_done;
int period2_done;
int period3_done;
int period4_done;
int period3;
int period4;
int creation_time;
int done_time = 0;
int crop_stat; 
int planted;
int duration;
int done;
int irrigated;
int period1;
int period2;
int skipped = 0;
int water;
string symptom;
string farmer;
string water_stat;
string crop_type;
string crop_cond;
string crop_shape; 
string savefile;
string disease;


/*basic functions*/

int query_farm(){return 1;}
string query_farmer(){return farmer;}
string set_crop_type(string type) {return crop_type = type;}
string set_farmer(string who) {return farmer = who;}
int set_creation_time(int time) {return creation_time = time;}
int set_done_time(int time) {return done_time = time;}
int set_crop_stat(int stat) {return crop_stat = stat;}
string set_save_file(string file){ return savefile = file;}

zero_vars()
{
  remedy = 0;
  planted = 0;
  harvested = 1;
  done = 0;
  crop_stat = 0;
  creation_time = 0;
  done_time = 0;
  disease = "";
  period1_done = 0;
  period2_done = 0;
  skipped = 0;
  irrigated = 0;
  irrigate_done = 0;
}

do_disease()
{
  disease = disease_type[random(sizeof(disease_type))];
  switch(disease)
  {
    case "club root":
      symptom = "large knob like growths on the roots";
      break;
    case "late blight":
      symptom = "large spotty paterns on the leaves";
      break;
    case "mildew":
      symptom = "ulcerous lesions all over the entire plant";      
      break;
    case "hemilieia vastherix":
      symptom = "green moldy growths on the leaves";
      break;
    case "fig warts":
       symptom = "small brown parasitic type creatures on the roots";
       break;
    case "peach yellows":
       symptom = "yellow stains on the root and stem";
       break;
    case "tobacco mosaic":
       symptom = "heavily wilted and brown leaves";
       break;
    case "potato-leaf roll":
       symptom = "brown curley leaves growing from the stem";
       break;
    case "curley top":
       symptom = "woody clumpted crowns on top of the plants";
       break;
    case "fire blight":
       symptom = "blackening of the roots and stem of plant with some yellow"+
               "verticle lines present";
       break;

    case "vegatable cankers":
        symptom = "corky growths on the roots and stems";
        break;
    case "crown gall":
        symptom = "black moldy substance spreading throughout the plant";
        break;
    case "common scabs":
        symptom = "red crusty spots on the leaves";
        break;
    case "angular leaf spots":
        symptom = "small triangle shaped molds forming on the leaves";
        break;
    case "black rot":
        symptom = "stems and roots that are completely enshrouded in black mold "+
        "with extreme wilting in all areas";
        break;
    default:
        symptom = "default symptom";
  }   
  original_cstat = crop_stat;
  crop_stat = crop_stat - random(50);
}
do_diagnose()
{
  if(!disease || disease == "") {
    write("The plants do not seem to be suffering from any disease.\n");
    return;
  }
  else{
    write("The plants seem to be suffering from "+disease+".\n");
    return;
  }
}
do_buy(string who, string crop)
{
  int modifier;
  if(!query_farmer()){
    if(member_array(crop,crops) < 0) {
      pline("Sorry but that is not a valid crop type.\n");
      return 0;
    }
    set_farmer(who);
    crop_type = crop;
    write("You claim the land.\n"); 
    save_object(savefile);
    return 1;
   }
   else {
    write("Someone already owns the land.\n");
    return 0; 
  }
}

do_remedy(string cure)
{
  int modifier;
  object object_cure;
  string disese;
  object_cure = present(cure,THIS);
  switch(cure)
  {
    case "pukabase":
      disese = "black rot";
      break;
    case "equanshear":
      disese = "fire blight";
      break;
    case "joelinium":
      disese = "club root";
      break;
    case "amrin":
      disese = "mildew";
      break;
    case "kappa":
      disese = "hemilieia vastherix";
      break;
    case "ithallon":
      disese = "fig warts";
      break;
    case "zanex":
      disese = "peach yellows";
      break;
    case "sirum":
      disese = "tobacco mosaic";
      break;
    case "tarek":
      disese = "potato-leaf roll";
      break;
    case "galiom":
      disese = "curley top";
      break;
    case "shaltaar":
      disese = "vegatable cankers";
      break; 
    case "draken":
      disese = "crown gall";
      break;
    case "tethar":
      disese = "common scabs";
      break;
    case "takhid":
      disese = "angular leaf spots";
      break;
    case "asthmil":
       disese = "late blight";
       break;
}


  if(disease ==  disese)
  {
    disease = "";
    modifier = (THIS->query_skill_chance("remedy_plantlife")/4) +
               (THIS->query_skill_chance("upkeep")/4);
    crop_stat = crop_stat + modifier;
    if(crop_stat > original_cstat)
       crop_stat = original_cstat;
  }
  write("You spread the material on the crops.\n");
  destruct(object_cure);
  return;
}
update_crops()
{
  int blah;
  blah = (200 - crop_stat) / 2;
  if(time() >= period1 && time() < period2 && !period1_done)
  {
      irrigated = irrigated - random(30);
      if(irrigated < 40)
        crop_stat = crop_stat - (random(40));
      if(random(100) < blah)
        do_disease();
      period1_done = 1;
      irrigate_done = 0;
  }
  if(time() >= period2 && !period2_done && period1_done)
  {
      irrigated = irrigated - random(30);
      if(irrigated  < 40)
          crop_stat = crop_stat - random(40);
      if(disease && disease != "")
         crop_stat = crop_stat - random(50);
      if(!disease  || disease == "")
        if(random(100) <  blah)
           do_disease();
        period2_done = 1;
        irrigate_done = 0;
  }
if(time() >= period3 && !period3_done && period2_done && period1_done)
  {
      irrigated = irrigated - random(30);
      if(irrigated  < 40)
          crop_stat = crop_stat - random(40);
      if(disease && disease != "")
         crop_stat = crop_stat - random(50);
      if(!disease  || disease == "")
        if(random(100) <  blah)
           do_disease();
        period3_done = 1;
        irrigate_done = 0;
  }
 if(time() >= period4 && !period4_done && period1_done && period3_done &&
    period2_done)
  {
      irrigated = irrigated - random(30);
      if(irrigated  < 40)
          crop_stat = crop_stat - random(40);
      if(disease && disease != "")
         crop_stat = crop_stat - random(50);
      if(!disease  || disease == "")
        if(random(100) <  blah)
           do_disease();
        period4_done = 1;
        irrigate_done = 0;
  }
  if(time() == done_time + 14400)
    crop_stat = 0;
  if(crop_stat < 0)
     crop_stat = 0;
  if(irrigated < 0)
     irrigated = 0;
  if(irrigated > 100)
     irrigated = 100;
  save_object(savefile);
}


       
debug()
{
  pline("*************DEBUG STATS FOR FARM****************\n");
  pline("Crop_stat = "+crop_stat+"\n");
  pline("Time() = "+time()+"\n");
  pline("Done_time = "+done_time+"\n");
  pline("Difference from done_time - time() = "+(done_time - time())+"\n");
  pline("irrigated = "+irrigated+"\n");
  pline("disease = "+disease+"\n");
  pline("*************************************************\n");
}

string
query_long()
{
  string buf = "";  
  update_crops();
  switch(irrigated)
  {
    case 0..10:
	  water_stat = "completely dehydrated";
	  break;
    case 11..20:
	  water_stat = "very dry";
	  break;
	case 21..30:
	  water_stat = "rather dry";
	  break;
    case 31..40:
	  water_stat = "dry";
	  break;
    case 41..60:
	  water_stat = "in need of water";
	  break;
	case 61..70:
	  water_stat = "in need of a little water";
	  break;
	case 71..90:
	  water_stat = "in no need of water";
	  break;
	case 91..100:
	  water_stat = "perfectly hydrated";
	  break;
	default:
	  water_stat = "completely un-hydrated";
   }
  switch (crop_stat)
  {
    case 1..10:
      crop_shape = "in unrepairable shape";
      break;
    case 11..20:
      crop_shape = "in terrible shape";
      break;
    case 21..40:
      crop_shape = "in dire shape";
      break;
    case 41..60:
      crop_shape = "in bad shape";
      break;
    case 61..80:
      crop_shape = "in fair shape";
      break;
    case 81..100:
      crop_shape = "in average shape";
      break;
    case 101..120:
      crop_shape = "in good shape";
      break;
    case 121..140:
      crop_shape = "in excellent shape";
      break;
    case 141..160:
      crop_shape = "in unearthly shape";
      break;
    case 161..180:
      crop_shape = "in ungodly shape";
      break;
    case 181..300:
      crop_shape = "in the best shape";
      break;
    default:
      crop_shape = "completely rotten";
  }
  //debug();  
  if(crop_type) {
    buf += "You are standing in a vast farmland for a crop of ";
    buf += crop_type;
    buf += ".  ";
  }
  else {
    buf += "You are standing in a vast open farmland, free for planting";
    buf += ".  ";
  }
  /*if(farmer)
    buf += farmer;
  else
    buf += "nobody";
  buf += "\n"; */
  if(planted)
  {
    buf += "The crops here are ";
    buf += crop_shape;
    buf += ", ";
    buf += water_stat;
    buf += ", and ";
    if(time() >= done_time)
       buf += "are ready to be harvested.\n";
    else
      buf += "are not ready to be harvesteed.\n";
    if(disease && !(disease == ""))
    {
        buf += "You notice that the crops seem to have ";
        buf += symptom;
        buf += ".  ";
    }
   }
   else
     buf += "There are no crops planted here.\n";
     //buf += savefile;
     buf += "A small sign is stuck into the dirt at the front of the"+
     " plot.\n";  
     return buf;
   
}

restore()
{
  if (savefile)
    restore_object(savefile);
}

save()
{
  if (savefile)
    save_object(savefile);
}

create_room()
{
  THOB->create_farm();  
  set_outdoors(4);
}

init()
{
  ::init();
  THOB->init_farm();
  add_action("do_look","look");
  add_action("do_look","l"); 
  add_action("do_look","la");
  update_crops();
  //debug();
}
do_look(string what)
{
  if(!what)
    return 0;
  if(what == "sign" || what == "at sign"){
    if(farmer) {
      pline("The sign reads:\nThis plot is owned by "+farmer+".\n");
      return 1;
    }
    else {
      pline("The sign reads:\nThis plot is for sale.\n");
      return 1;
    }
  }
  return 0;
}


do_harvest()
{
  int num,bundle_num;
  object obj;
  int i = 0;
  string crop_file;
  update_crops();  
  num = (crop_stat/4)+(random(25)+(THIS->query_skill_chance("harvesting")/2));
  if(THIS->query_cap_name() != farmer && THIS->query_name() != farmer)
  {
    pline("You cannot harvest on land that isn't yours.\n");
    return 1;
  } 
  switch(crop_type)
  {
    case "corn":
      crop_file = "/home/shinael/agri/corn_bundle.c";
      break;
   case "potatoes":
      crop_file = "/home/pook/farms/items/potato_bundle.c";
      break; 
   case "barley":
      crop_file = "/home/shinael/agri/barley_bundle.c";
      break;
   case "cabbage":
      crop_file = "/home/shinael/agri/cabbage_bundle.c";
      break;
   case "carrots":
      crop_file = "/home/shinael/agri/carrot_bundle.c";
      break;
   case "green beans":
      crop_file = "/home/shinael/agri/green_bean_bundle.c";
      break;
   case "tobacco":
      crop_file = "/home/shinael/agri/tobacco_bundle.c";
      break;
   case "tomatoes":
      crop_file = "/home/shinael/agri/tomato_bundle.c";
      break;
   case "wheat":
      crop_file = "/home/shinael/agri/crop_bundle.c";
      break;
   default:
      crop_file = "/home/madrid/bull.c";
  }
  if(planted && time() >= done_time)
  {
    if(!(present("harvester",THIS)) && !(present("sicle",THIS))){
      pline("You don't have any tools to harvest the crops with.\n");
      return 1;
    }
    if(disease && disease != ""){
      bundle_num = random((num/5))+1;
      pline("Because of the diseased plants you were only able to get "+
      bundle_num+" good bundles of crops.\n");
      num = bundle_num;
      room(THIS->query_cap_name()+" gets a sad look on his face as he "+
      "harvests his diseased crops.\n");
    }
    else {
      pline("You harvest the "+crop_type+"\n");
      pline("And recieve "+num+" bundles.\n");
      room(THIS->query_cap_name()+" harvests some "+crop_type+".\n");
    }
    //debug();
    for(i = 0;i<num;i++)
    {
       obj = clone_object(crop_file);
       obj->move(ENV(THIS));
    }
    zero_vars(); 
  }
  else
  {
    if(!planted)
    {
      pline("There are no crops here.\n");
      return 1;
    }
    else
    {
      pline("The crops are not ready to be harvested yet.\n");
      return 1;
    }
  }
  zero_vars();
  save_object(savefile);
  return 0;
}
do_plant()
{
  object seed_obj;
  string seed_name, season;
  string *avail_crops;
  int plow_modifier;
  if(present("hoe",THIS))
      plow_modifier = -10;
  if(present("plow",THIS))
      plow_modifier = 10;
  if(!(present("hoe",THIS)) && !(present("plow",THIS)))
  {
    write("You don't have the proper tools for planting.\n");
    return 1;
  }
  if(!THIS->query_skill_chance("planting"))
  {
    pline("You don't have the skills to plant things.\n");
    return 1;
  }
  season = TIME_D->query_season();
  switch(season)
  {
    case "autumn": {
      avail_crops = ({"corn","cabbage","wheat","barley","green beans"});
      break;
    }
    case "spring": {
      avail_crops = ({"corn","wheat","barley","tomatoes","carrots"});
      break;
    }
    case "winter": {
      avail_crops = ({});
      break;
    }
    case "summer": {
      avail_crops = ({"corn","cabbage","potatoes","tobacco","carrots"});
      break;
    }
    default :
      avail_crops = ({});
  }  
  switch(crop_type)
  {
    case "corn": {
      seed_name = "corn seeds";
      duration = 86400;
      break;
   } 
   case "potatoes": {
      seed_name = "potato seeds";
      duration = 21600;
      break;
    }
   case "carrots": {
      seed_name = "carrot seeds";
      duration = 7200;
      break;
   }
   case "wheat": {
      seed_name = "wheat seeds";
      duration = 57600;
      break;
   }
   case "barley": {
      seed_name = "barley seeds";
      duration = 57600;
      break;
   }
   case "tobacco": {
      seed_name = "tobacco seeds";
      duration = 28800;
      break;
   }
   case "tomatoes": {
      seed_name = "tomato seeds";
      duration = 14400;
      break;
   }
   case "green beans":{
      seed_name = "green bean seeds";
      duration = 7200;
      break;
   }  
   case "cabbage":{
      seed_name = "cabbage seeds";
      duration = 43200;
      break;
   }
}
   
  
  //write("seed name = "+seed_name+" croop_type = "+crop_type+"\n");
  if(!(seed_obj = present(seed_name,THIS)))
  {
    pline("You don't have any seeds for planting.\n");
    return 1;
  }
  if(THIS->query_cap_name() != farmer && THIS->query_name() != farmer)
  {
    pline("You cannot plant seeds in farms you don't own.\n");
    return 1;
  }
  if(planted){
    pline("There are already crops planted here.\n");
    return 1;
  }
  if(member_array(crop_type,avail_crops) < 0) {
    pline("You cannot plant that crop during this season.\n");
    return 1;
  }
  pline("You planted some seeds.\n");
  room(THIS->query_cap_name()+" plants some seeds.\n");
  crop_stat = (THIS->query_skill_chance("sowing")/2) +
              (THIS->query_skill_chance("seed_knowledge")/2) + 
              (THIS->query_skill_chance("planting")/4) + 
              (THIS->query_skill_chance("farming")/4) + 
              random(30) + plow_modifier;
  creation_time = time();
  done_time = time()+duration;
  period1 = ((done_time - creation_time) / 20) + creation_time;
  period2 = ((done_time - creation_time) / 40) + creation_time;
  period3 = ((done_time - creation_time) / 60) + creation_time;
  period4 = ((done_time - creation_time) / 80) + creation_time;
  destruct(seed_obj);
  planted = 1;
  irrigated = 0;
  return 1;
  save_object(savefile);
}


do_irrigate()
{
  
  if(!planted)
  {
  	 pline("There are no crops here to irrigate.\n");
	 return 1;
  }
  if(time() >= done_time && !harvested)
  {
    pline("The crops are ready to be harvested.\n");
	return 1;
  }
  if(irrigate_done)
  {
    pline("No water flows from the drill at this time.\n");
    return 1;
  }
  if(THIS->query_cap_name() != farmer)
  {
      pline("You cannot water other peoples crops.\n");
      return 1;
  }
     pline("Water rushes from the drill onto the crops.\n");
     room(THIS->query_cap_name()+" begins to water the crops.\n");
     //pline("Irrigated before water = "+irrigated+"\n");
     irrigated += (THIS->query_skill_chance("farming")/20) +
	              (THIS->query_skill_chance("upkeep")/10)	+
		      (THIS->query_skill_chance("irrigation")/10) +
		      random(50);
     //debug();
     irrigate_done = 1;
     save_object(savefile);
     return 1;
}
