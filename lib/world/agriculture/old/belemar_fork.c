inherit ITEM;
create_item()
{
  set_name(({"fork","pitch fork","farmer's pitch fork"}));
  set_short("a farmer's pitch-fork");
  set_long(wrap("This is a long, about 1 meter in height, wooden pole with "+
  "a large metal fork attatched to the bottom of it.  Farmer use these "+
  "for tilling soil and planting crops of all kinds.  As you grip this "+
  "particular pitchfork it makes you feel one with nature as if you could "+
  "teleport yourself around the world because of the power you are able "+
  "to harness.  On the handle are two buttons you could press.\n"));
  set_weight(500);
}
init()
{
  add_action("do_press","press");
}
do_press(string what)
{
  if(!what)
  {
    write("Press which button?\n");
    return 1;
  }
  if(what == "button 1" || what == "button one" || what == "1"
  || what == "one") {
    write(wrap("You press the first button on the handle of the pitch "+
    "fork and it begins to shake violently.  Suddenly you are forced "+
    "upon it by unnatural forces.  You ride it like a broom as it "+
    "begins to shake even more violently, still you can't get off of "+
    "it.  With a burst of white light it takes off for the skies with "+ 
    "you upon it and it makes you scream out....\n"));
     message("0",wrap(THIS->query_cap_name()+" runs his hands "+
     "down the shaft of a long pitch-fork.  He finds a button at the "+
     "bottom and presses it.  Suddenly the fork begins to shake violently "+
     "and "+THIS->query_cap_name()+" puts it between his legs like a "+
     "witches broom.  In a burst of white light "+THIS->query_cap_name()+
     " takes off into the stars.\n"),ENV(THIS),THIS);
     THIS->force_us("say YEE HAW!!!");
     THIS->move("/home/madrid/agriculture/guild/rooms/cabin1.c");
     return 1;
   }
   if(what == "button 2" || what == "2" || what == "button two" || 
   what == "two") {
     write(wrap("You press the first button on the handle of the pitch "+
    "fork and it begins to shake violently.  Suddenly you are forced "+
    "upon it by unnatural forces.  You ride it like a broom as it "+
    "begins to shake even more violently, still you can't get off of "+
    "it.  With a burst of white light it takes off for the skies with "+
    "you upon it and it makes you scream out....\n"));
     message("0",wrap(THIS->query_cap_name()+" runs his hands "+
     "down the shaft of a long pitch-fork.  He finds a button at the "+
     "bottom and presses it.  Suddenly the fork begins to shake violently "+
     "and "+THIS->query_cap_name()+" puts it between his legs like a "+
     "witches broom.  In a burst of white light "+THIS->query_cap_name()+
     " takes off into the stars.\n"),ENV(THIS),THIS);
     THIS->force_us("say Hot Dawg!!");
     THIS->move("/world/hilltop/rooms/room13.c");
     return 1;
  }
  return 0;
}   
