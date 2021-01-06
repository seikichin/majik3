inherit "/inherit/weapon.c";
create_weapon()
{
  set_short ("a slender elven longsword");
  set_long ("The blade is very well balanced and easy to handle. It is "
         +"perfect for the purpose it was made, killing. The deadly shine "
         +"of the blade fascinates you in a queer way and gripping the "
         +"handle makes you feel more comfortable about the waiting "
         +"dangers.\n");
  set_name (({"longsword","sword","blade"}));
  set_material ("silver");
  set_property("agility", 3);
  set_dimensions(2,4,140);
  set_damage_type("slash","1d10");
}
