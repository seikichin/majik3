inherit "/inherit/armour.c";

#include "../path.h"

create_item()
{
     set_name(({"moon shield","shield"}));
     set_short("a moon shield");
     set_long(wrap("It is a shield of marvalous design. It's smooth polished surface could "
      + "deflect many blows. It is a pale white color with no special features except the "
      + "engraving of a full moon on the front side.\n"));


     set_material("steel");
     set_dimensions(3, 10, 100);

     set_armour_type("shield");
     set_armour_slots("hand");    
}
