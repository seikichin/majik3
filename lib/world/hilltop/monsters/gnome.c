inherit MONSTER;

static int money;

#include "../path.h"

#define OFFICE "/world/hilltop/rooms/room3");
#define DEBUG(x)

string me;

create_monster ()
{
  set_name (({ "a gnome", "gnome" }));
  set_short ("a gnome sorting out messages");
  set_long ("You see a very busy looking gnome, sorting out a small piles "
  + "of messages that needs delivering. Do not disturb him.\n");
  me = capitalize(name);
  set_race ("gnome");
  set_gender (1);
  set_levels (([ "fighter" : 3 + random(17), "caster" : 0 + random(3) ]));

  add_object (ITEM_PATH + "key");
  DEBUG ("create_monster");
}

do_alarm(object who)
{
  DEBUG ("do_alarm");
  "/command/mortal/shout"->main("HELP! "+capitalize(who->query_name())+" is robbing my vault!");
  tell_room (environment(), me+" PUUHs angrily.\n");
  return 1;
}

process ()
{
  string msgs,mn;
  object ob, daemon;
  int idx1, idx2, idx3;

  DEBUG ("process");

  msgs = get_dir ("/data/scroll/*");
  daemon = present("daemon", environment());
  if (daemon)
    {
      mn = daemon->query_cap_name();

  if (daemon && daemon->query_number() < 10)
    {
      tell_room (environment(), me+" gives some blank scrolls to "+mn+".\n");
      daemon->add_number (10 - daemon->query_number());
    }

  if (msgs)
    {
      for (int i=0;i<sizeof(msgs);i++)
        {
          for (int j=0;j<sizeof(users());j++)
            {
              if (strsrch(lower_case(msgs[i]), users()[j]->query_name()) > -1)
                {
                  ob = clone_object (ITEM_PATH + "scroll");
                  idx1 = strsrch(msgs[i], "-");
                  idx2 = strsrch(msgs[i], ".");
                  idx3 = msgs[i][idx1+1..idx2-1];
                  ob->restore_scroll (users()[j]->query_name(), idx3);
                  if (daemon)
                    {
                      ob->move (daemon);
                      tell_room (environment(), me+" gives "+ob->short()+" to "+mn+".\n");
                    }
                }
            }
         }
     }
    }
  return 1;
}

int
add_money (int i)
{
  DEBUG ("add_money");
  money = i;
  remove_call_out ("do_vault1");
  call_out ("do_vault1", 2 + random(2));
  return 1;
}

do_vault1 ()
{
  DEBUG ("do_vault1");
  tell_room (environment(), me+" smiles happily.\n");
  remove_call_out ("do_vault2");
  call_out ("do_vault2", 6 + random(2));
  return 1;
}

do_vault2 ()
{
  DEBUG ("do_vault2");
  tell_room(environment(), me+" unlocks door with key.\n");
  tell_room(environment(), me+" opens door.\n");
  move_player("/world/hilltop/rooms/vault", "down");
  "/world/hilltop/rooms/vault"->do_drop(money + " gold");
  move_player("/world/hilltop/rooms/room3", "up");
  tell_room(environment(), me+" closes door.\n");
  tell_room(environment(), me+" locks door with key.\n");
  money = 0;
  /* command ("unlock door with key");
  command ("open door");
  command ("down");
  command ("drop "+money+" gold");
  money = 0;
  command ("up");
  command ("close door");
  command ("lock door with key"); */

  remove_call_out ("do_vault3");
  call_out ("do_vault3", 2);
  return 1;
}

do_vault3 ()
{
  DEBUG ("do_vault3");
  remove_call_out ("do_vault3");
  tell_room (environment(), me+" PUUHs happily.\n");
  return 1;
}
