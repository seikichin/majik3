inherit ROOM;
#include "../path.h"

create_room()
{
   set_short ("University of Agricultural Mastery");
  set_long ("This is a room made of black obsidian and rich "+
  "white marble. Its ceiling is a dome with heavenly stained "+
  "glass window surrounding it and sheding light to all who "+
  "enter. An oak bookshelf lines this rooms perimeter and "+
  "is filled with books of all sizes and shapes. On the "+
  "northern wall is a tall archway leading into some sort of "+
  "lab.\n");
  set_light(1);
  add_exit("north",ROOM_PATH+"unihall1.c");
  add_item(({"bookshelf","bookshelves","shelves","shelf","book","books"}),
  wrap("The book shelves are lined around the room and reach about "+
  "2 meters in height.  Each shelf is made of the most beautiful and "+
  "ancient oak you have ever seen.  The shelves are filled with book "+
  "written in old cryptic lettering.  The only ones that seem to "+
  "represent anything you have ever seen before read:\n"+
  "History, Alchemy of Agriculture, Mastery of Agriculture\n"));
  add_exit("out",ROOM_PATH+"road7.c");
  add_item(({"window","windows","stained window","glass window"}),
  wrap("The window is made of the most beautiful stained glass in "+
  "the realm.  It is depicting an open field with Madrid stading in "+
  "its interior.  He has his hands raised up to the blue sunny "+
  "skies and blue bolts of energy are streaming from his fingers."+
  "  The field of wheat he is standing in seems to have a golden "+
  "glow surrounding it.\n"));

  add_object(MONSTER_PATH+"granlin.c");
}

init_room()
{
  add_action("do_read","read");
}


do_read(str)
{
  string buf = "";
  if(!str){
    notify_fail("Read what?\n");
    return 0;
  }
  else {
    write("You open the book and its pages are completely blank.\n");
    return 1;
  }
 str = capitalize(str);
 if(str == "Book" ||
  str == "Books"){
    notify_fail("Read which book?\n");
    return 0;
  }
  else {
    notify_fail("Read what?\n");
    return 0;
  }   
}

