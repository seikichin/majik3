inherit "/inherit/weapon.c";

#include "../path.h"

create_weapon()
{
     set_name(({"longsword"}));
     set_short("An iron longsword");
     set_long("This is your ordinary longsword.  It is made of iron and is rather sharp.  "+
      "The hilt has some cloth wrapping around it that is a little sticky.  It provides for "+
      "better than average grip.\n");

     set_taste("The longsword tastes like stale blood.\n");

     set_dimensions(3, 10, 100);
     set_weight(5000);
     set_hp(150);
     set_max_hp(150);
     set_material("iron");

     set_damage_type("slash", "1d8");
     
}
