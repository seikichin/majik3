// DATE        : Thu Dec 25 23:30:06 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Tirithil, the house of healing");
  set_long (
    "Beautiful frescos and paintings decorate the white marble wall"
  + "s of Tirithil. A shining white altar holds a couple of blue c"
  + "andles and a bowl of burning incense on it. The atmosphere he"
  + "re is totally serene and loving and no evil presence could po"
  + "ssibly enter this most sacred place. An arched doorway leads "
  + "west to the city.");

  add_exit ("west", ROOM_PATH + "falan4.c");

  add_item ("frescos paintings walls",
    "The temple walls are full of frescos and beautiful paintings d"
  + "escribing the history of Tirithil, from the days of old to th"
  + "is day. All of the paintings are incredible pieces of art. It"
  + " is said that when tanir artist puts his heart in painting he"
  + " loses a bit of his life in the process, however, they consid"
  + "er it a small sacrifice and you can't but agree. You'd more t"
  + "han eagerly own one of these artpieces.\n");

  add_item ("altar candles candle bowl incense",
    "The altar is also mad"
  + "e of the same white marble which catches the light in most as"
  + "tonishing way making the stone sparkle and glow faintly. On t"
  + "he altar are laid two blue candles and a bowl of burning ince"
  + "nse which fills the air with a strong herbal scent.\n");

  add_sound ("The wind tingles some bells outside.");
  add_sound ("The scent of incense fills your nostrils.");
  add_sound ("Watching the celestial frescos leaves you gaping in awe.");

  set_outdoors (1);
  set_light (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
