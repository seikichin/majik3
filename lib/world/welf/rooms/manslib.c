// DATE        : Tue Feb 24 19:06:26 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Library");
  set_long (
    "You're standing in a small library. A pair of huge bookcases l"
  + "ine the east and west walls. A marble platform lies in front "
  + "of a large colored window on the south wall. A stone pedestal"
  + " has been placed on the platform and on it rests a big ancien"
  + "t tome and two sealed scrolls close together. A painting depi"
  + "cting a beautiful female has been hung above the doorway.");

  add_exit ("north", ROOM_PATH + "mansent.c");

  add_item ("platform pedestal",
    "The platform is made of solid stone, its polished surface glea"
  + "ming in the light. A stone pedestal rests on it, and on the p"
  + "edestal has been placed a big tome and two scrolls.\n");

  add_item ("painting female",
    "It must b"
  + "e an old painting, but the colors are still vivid and lustrou"
  + "s. A beautiful elven lass has been depicted in it. A small pl"
  + "ate below the painting indicates it as a gift from Telwan Moo"
  + "nfall. The painting has been named as Belinda.\n");

  add_item ("window",
    "The colored mo"
  + "saic clearly depicts a great eagle flying above a mountain ra"
  + "nge.\n");

  add_item ("tome book scrolls",
    "On top of the tome reads in golden runes: ^cYThe book of"
  + " creation^c0.\nTwo sealed scrolls have been placed next to the"
  + " book. A faint aura of surrounds the books and the pedestals "
  + "and you think it would be wise not to touch them.\n");

  add_item ("bookcases cases shelves books",
    "Hundreds of"
  + " tomes have been neatly arranged on the shelves. Most of them"
  + " are covered with a thick layer of dust and you guess they ha"
  + "ven't been in use for a long time. What you can tell about th"
  + "e books judging from their covers, these must be very old. Se"
  + "veral of them seem to be about the creation of the realms.\n");

  set_outdoors (1);

}

init_room()
{
add_action ("do_read","read");
add_action ("do_touch","touch");
add_action ("do_get","get");
}

do_read(str)
{
 if (!str || str != "tome")
 { return 0; }
 write ("A searing white light erupts from the tome and engulfs you "
       +"making you fall on your knees from the pain.\n");
        THIS->add_hp(-random(20));
        message("3", THIS->query_cap_name() + " moves closer to touch"
       +" the tome on the pedestal and a searing white light erupts from "
       +"the book making " + THIS->query_objective() + " scream in pain.\n",
       ENV(THIS),THIS);
       return 1;
}
do_touch(str)
{
 if (!str || str != "tome")
 { return 0; }
 write ("A searing white light erupts from the tome and engulfs you "
       +"making you fall on your knees from the pain.\n");
        THIS->add_hp(-random(20));
        message("3", THIS->query_cap_name() + " moves closer to touch"
       +" the tome on the pedestal and a searing white light erupts from "
       +"the book making " + THIS->query_objective() + " scream in pain.\n",
       ENV(THIS),THIS);
       return 1;
}
do_get(str)
{
 if (!str || str != "tome")
 { return 0; }
 write ("A searing white light erupts from the tome and engulfs you "
       +"making you fall on your knees from the pain.\n");
        THIS->add_hp(-random(20));
        message("3", THIS->query_cap_name() + " moves closer to touch"
       +" the tome on the pedestal and a searing white light erupts from "
       +"the book making " + THIS->query_objective() + " scream in pain.\n",
       ENV(THIS),THIS);
       return 1;
}
