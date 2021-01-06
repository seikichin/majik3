/*
 * Example of creating random equipment
 * 
 * */

main()
{
    object weapon, armour;

    /* Create both weapon and armour, with armour forced to be 'leggings' */ 

    weapon = find_object("/daemon/item.c")->create_generic_weapon();
    armour = find_object("/daemon/item.c")->create_generic_armour("leggings");

    /* Now we can do whatever we want with them, so move them to our inventory */

    armour->move(THIS);
    weapon->move(THIS);

    return 1;
}
