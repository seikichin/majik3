/* 
   skill_root
        magical 
          academic
            witchcraft
              ingredient_skills
                animal_extrusion

   Coded by Yorkaturr
*/

inherit "/obj/skill/obj/skill.c";
#include "/home/yorkaturr/guilds/witches/ingredient.h"

string ingredient_str;
object corpse; 

create_skill()
{
 set_skill_name("animal_extrusion");
 set_train_difficulty(7);
 set_base_percent(15);
 add_base_stat("dex",30);
 add_base_stat("str",30);
 add_base_stat("wis",40);
 set_parent_skill("ingredient_skills");
 set_ep_cost(30);
 set_duration(15);
}

do_success(me,target,result)
{
 object ingredient;
 ingredient = clone_object("/home/yorkaturr/ing.c")->move(THIS);
 message("standard","You succesfully extrude "+ingredient_str+" from the corpse.\n",THIS);
 message("standard",query_name(THIS)+" succesfully invokes a "+ingredient_str+" from the corpse.\n",ENV(THIS));
}

query_can_use(me, target)
{
 object knife = present("knife",me);
 string corpse_str, monster_str;
 sscanf(target,"%s in %s", ingredient_str, corpse_str);
  
 /* Start general checking (check if there is both strings) */

 if(!ingredient_str || !corpse_str)
 {
  message("standard","Usage: use 'extrusion' at <ingredient> in <corpse>\n", me);
  return 0;
 }

 /* Start corpse checking:
    o Check if there is a corpse
    o Check if the corpse is in fact a corpse
 */

 corpse = present(corpse_str,ENV(me));
 if(!corpse || !corpse->query_is_corpse())
 {
  message("standard","You can only perform animal extrusions on corpses.\n",me);
  return 0;
 }

 /* Scan the monster race info from the corpse's short desc */

 sscanf(corpse->short(),"of %s", monster_str);
 
 /* Start ingredient checking:
    o Check if the target ingredient is a proper ingredient
    o Check if there is a target ingredient in the type of corpse
 */ 

 check_ingredient(ingredient_str, monster_str);
 
 if(!knife)
 {
  message("standard","You need a knife to perform animal extrusions.\n", me);
  return 0;
 }

 message("standard","You begin extruding "+ingredient_str+" from the corpse...\n", THIS);
 message("standard",THIS+" begins working with "+corpse->short()+"...\n",ENV(THIS));
 return ::query_can_use(me, target);
}

int check_ingredient(string istr, string cstr)
{
 int i,j;
 if(!ingredients[istr])
 {
  message("standard","There is no "+istr+" in this corpse.\n", THIS);
  return 0;
 }
 for(i=0, j=sizeof(ingredients[istr][6]); i<j; i++)
 {
  if(ingredients[istr][6][i] == cstr)
  {
   return 1;
  }
 }
 message("standard","Extruding "+istr+" from this corpse would serve no purpose.\n", THIS);
 return 0;
}

 
 
