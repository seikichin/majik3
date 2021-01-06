#include "../path.h/"
inherit ROOM;
create_room()
{
  set_area("temple");
  set_short("^cYThe Inter-Sanctum^c0");
  set_long("^cYYou are standing it what seems to be the most "+
  "well constructed and maticiously made chapel in the entire "+
  "world.  The walls and ceiling are made of complete white "+
  "and purple marble.  There are large 20 foot stain glass "+
  "windows high above the with unatural beams of golden light "+
  "shinning through.  There is a main walkway up the middle of "+
  "the pews.  Up at the end of the walkway is an elaboratly "+
  "carved and decorated golden altar.^c0\n");
  set_light(5);
  set_sounds(40,"Warm beams of unatural golden light shine through "+
  "the windows and engulf your body.\n");
  add_sound("You feel as if you aren't touching the ground, almost "+
  "floating.\n");
  add_sound("You have never been so calm nor at peace before in "+
  "your life.\n");
  add_sound("You reach out your hand to look at your body and realize"+
  " you can see through yourself, you have become completely "+
  "ethereal.\n");
  add_sound("It is completely silent inside, you can't even hear "+
  "yourself move or breathe.\n");
  add_sound("You are drawn to the altar by super-natural forces.\n");
  add_sound("You feel like your life is complete and whole.\n");
  add_sound("Above you spy other ethereal forms of angels "+
  "circling the altar.\n");
  add_sound("The aura of this place draws you in, making you never want "+
  "to leave.\n");
  add_item(({"carving","carvings","painting","paintings"})," Above "+
  "the altar are many paintings and carvings of holy beings of the "+
  "past.\n");
  add_item("book","You can't tell anything more about the book except "+
  "that it is made of gold and lies upon the altar.\n");
  add_item("altar","The altar is made completely of carved gold.  Upon "+
  "it sits a single golden book, you can't make out what is inscribed "+
  "on it from here.  Above the altar are various carvings of what seem "+
  "to be angels of days past, and paintings of heavenly beings.\n");
  add_item(({"window","windows"}),"These beautiful stained glass "+
  "windows have beams of golden light filling the room with "+
  "unatural light.\n");
  add_item(({"walls","wall","ceiling"}),"The walls and ceiling are made "+
  "of ornatly carved white and purple marble.\n");
  add_exit("leave",ROOM_PATH+"temple1.c");
  add_exit("altar",ROOM_PATH+"altar.c");
}
