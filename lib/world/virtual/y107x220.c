// DATE        : Thu Nov 13 11:02:35 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : pook

config (object ob)
{
  ob->set_short ("The dark forest");
  ob->set_long (
    "You stand in a beautiful, green, deep forest. The forest if very"
  + " dense and you cannot get a clear view of the inside from her"
  + "e. The trees are tall and forboding. Upon closer inspection, "
  + "you notice a faint path before you.");

  ob->add_exit ("path", "/world/forest/rooms/oforest1.c");

  ob->add_item ("forest tree trees woods",
    "The forest is full of tall maples which form a canopy that it "
  + "seems even the sunlight can't penetrate.\n");

  ob->add_item ("path",
    "The path is only sli"
  + "ghtly visible among the overgrown brush.  It looks like it ha"
  + "s not been used in years.\n");

  ob->add_sound ("Feint cries of someone or something in great pain can be heard comming from within the forest. ");
  ob->add_sound ("A chill wind eminates from the direction of the forest. ");

  ob->set_outdoors (4);

}
