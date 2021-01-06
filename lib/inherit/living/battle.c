inherit "/inherit/living/skill_system";

// #define debug(x, y) message ("0", x+": "+y+"\n", find_player("namhas"))
#define debug(x, y) {}
#define emote(x, y) message ("0", y+"\n", x)
#define room(x) message ("0", x+"\n", ENV(THOB), THOB)
#define PREV previous_object()

// limb flags

#define L_HP 0 // hit points
#define L_MX 1 // max hit points
#define L_BL 2 // bleeding flag
#define L_RM 3 // removed flag
#define L_ML 4 // melee size
#define L_DI 5 // distance size
#define L_CH 6 // chopable flag
#define L_E1 7 // effect when useless
#define L_E2 8 // effect when negative

static object *battle = ({ });

static string *physical_damage = ({
                                  "slap",
                                  "shove",
                                  "punch",
                                  "push",
                                  "jab",
                                  "whack",
                                  "sock",
                                  "slam",
                                  "kick",
                                  "drive",
                                  "stomp",
                                  "ram",
                                  "knock",
                                  "thrust",
                                  "shoulder",
                                  "uppercut",
                                  "elbow",
                                  "side kick",
                                  "knee",
                                  "hook",
                                  "headbutt",
                                  "rabbit punch" });

static string *physical_limb = ({ "causing a slight movement",
                                  "making a small bruise",
                                  "causing a bruise",
                                  "making a deep bruise",
                                  "making a small fracture",
                                  "dislocating a joint",
                                  "breaking a bone",
                                  "snapping a large bone",
                                  "crushing many bones",
                                  "rendering it useless" });

mapping location = ([ ]);

static int turn, melee, pending, round, penalty;

int
die (object kill)
{
  object corpse, o, *all;
  int alxm;

  emote (THOB, "You die.");
  room (THOB->query_cap_name()+" dies.");

  if (kill)
    {
      write_file ("/log/kill", ctime(time())+" "+kill->query_name()+
        " "+THOB->query_name()+"\n");

      if (THOB->query_alignx() < 0)
        alxm += -((THOB->query_alignx()/20));
      else if (THOB->query_alignx() > 0)
        alxm -= THOB->query_alignx()/20;

      if (interactive(THOB) && interactive(kill))
        {
          write_file ("/log/pkill", ctime(time())+" "+kill->query_name()+
            " "+THOB->query_name()+"\n");

          alxm = alxm * 2;
        }

      if (THOB->query_race() == kill->query_race())
        alxm = alxm * 2;

      kill->add_alignx(alxm);

      if (THOB->query_race() != "raceless")
        {
          kill->add_kill (THOB->query_race());
        }

      if (kill->query_kills())
        {
          switch (kill->query_kills()[THOB->query_race()])
            {
              case 1:
                emote (kill, "You feel victorious as you killed "+
                  THOB->query_race()+" first time.\n");
                break;
              case 10:
                emote (kill, "You are getting the idea in killing "+
                  pluralize(THOB->query_race())+".\n");
                break;
              case 30:
                emote (kill, "You feel yourself as average "+
                  THOB->query_race()+" killer.\n");
                break;
              case 50:
                emote (kill, "It seems "+pluralize(THOB->query_race())+
                " are getting killed more easily.\n");
                break;
              case 70:
                emote (kill, "You feel yourself as expert "+
                  THOB->query_race()+" killer.\n");
                break;
              case 85:
                emote (kill, "Fuck those "+THOB->query_race()+
                " bastards prove no resistance against you.\n");
                break;
              case 100:
                emote (kill, "You feel like "+pluralize(THOB->query_race())+
                " are far too easy for such great warrior as you.\n");
                break;
            }
        }
    }

  corpse = new ("/obj/corpse");
  corpse->create_corpse (THOB);

  all = all_inventory(THOB);

  foreach (o in all)
      o->move (corpse);

  if (THOB->query_money())
    {
      o = new ("/obj/money");
      o->set_amount (THOB->query_money());
      THOB->add_money (-THOB->query_money());
      o->move (corpse);
    }

  corpse->move (ENV(THOB));
  emote (THOB, "You feel yourself floating away from your body.\n");

  if (!interactive(THOB))
    {
      if (THOB->short() && THOB->short()[0] > 64 && THOB->short()[0] < 91)
        {
          "/daemon/astral"->add_ghost(THOB->query_race(),
            THOB->query_pow());
        }
      else
        {
          "/daemon/astral"->add_ghost(THOB->query_cap_name(),
            THOB->query_pow());
        }

      destruct (THOB);
    }
  else
    {
      o = new ("/world/misc/astral");
      o->set_env (ENV(THOB));

      THOB->move(o);
      THOB->set_ghost(1);
    }

  return 1;
}

object *
query_battle ()
{
  return battle;
}

int
query_agi_turn ()
{
      switch (THOB->query_agi())
        {
          case 0..9:
            return 1;
            break;
          case 10..15:
            return 0;
            break;
          case 16..19:
            return -1;
            break;
          case 20..31:
            return -2;
            break;
          default:
            return -3;
            break;
        }
}

int
add_penalty (int i)
{
  return penalty += i;
}

int
reset_limbs ()
{
  for (int i=0;i<sizeof(keys(location));i++)
    location[keys(location)[i]][0] = 1;

  return 1;
}

int
limb_beat ()
{
  string *k;
 
  k = keys(location);

  for (int i=0;i<sizeof(k);i++)
    {
      if (location[k[i]][2])
      {
        if (!location[k[i]][3])
          {
            if (random(101) > THOB->query_con())
              {
                if (location[k[i]][0] < -THOB->query_max_hp()*location[k[i]][1]/100)
                  {
                    emote (THOB, "Your "+k[i]+" seems to be useless.");
                    location[k[i]][L_RM] = 1;
                  }
                else
                  {
                emote (THOB, "You wish your "+k[i]+" would stop ^cRBLEEDING^c0 so much!");
                message ("3", THOB->query_cap_name() + "'s "+k[i]+" is bleeding.\n", ENV(THOB), THOB);
                location[k[i]][0] -= location[k[i]][2];
                THOB->add_hp (-location[k[i]][2]);
                  }
              }

            if (random(101) < THOB->query_con())
              {
                location[k[i]][2]--;
                if (!location[k[i]][2])
                  emote (THOB, "Your "+k[i]+" bleeds no longer.");
              }
          }
       }
      else
       {
         if (!battle || sizeof(battle) == 0)
           {
             if (!location[k[i]][3] && location[k[i]][0] < THOB->query_max_hp()*location[k[i]][1]/100)
               location[k[i]][0] += THOB->query_con();
           }
       }

     if (!random(5)) /* miss heart beat */
       break;

    }
}

int
init_location (string str)
{
  string *k;

  if (str == "humanoid")
    {
      // hp = hit points
      // mx = max hit points percentage
      // bl = bleeding flag (bleed 1-100 hp/tick)
      // rm = removed/useless flag (1 = useless, 2 = removed)
      // ml = melee size (1-10)
      // di = distance size (1-10)
      // ch = chopable flag
      // e1 = what happens when the limb is useless?
      //      0 = nothing
      //      1 = we go down and can only crawl away
      //      2 = we go down and uncon
      // e2 = what happens when we get negative hit points to the limb?
      //      0 = nothing
      //      1 = we go down and can only crawl away
      //      2 = we go down and uncon

                                  // hp mx bl rm ml di ch e1 e2
      location = ([ "right leg" : ({ 0, 33, 0, 0, 4, 3, 1, 0, 1 }),
                    "left leg"  : ({ 0, 33, 0, 0, 4, 3, 1, 0, 1 }),
                    "stomach"   : ({ 0, 33, 0, 0, 3, 4, 0, 2, 1 }),
                    "chest"     : ({ 0, 40, 0, 0, 1, 5, 0, 2, 1 }),
                    "right arm" : ({ 0, 25, 0, 0, 3, 2, 1, 0, 0 }),
                    "left arm"  : ({ 0, 25, 0, 0, 3, 2, 1, 0, 0 }),
                    "head"      : ({ 0, 34, 0, 0, 2, 1, 1, 2, 2 })
                 ]);
    }
  else if (str == "mammal")
    {
                                       // hp mx bl rm ml di ch e1 e2
      location = ([ "right hind leg" : ({ 0, 27, 0, 0, 2, 2, 1, 0, 1 }), 
                    "left hind leg"  : ({ 0, 27, 0, 0, 2, 2, 1, 0, 1 }),
                    "back part"      : ({ 0, 45, 0, 0, 3, 5, 0, 2, 0 }),
                    "front part"     : ({ 0, 45, 0, 0, 3, 5, 0, 2, 0 }),
                    "right foreleg"  : ({ 0, 27, 0, 0, 3, 2, 1, 0, 1 }), 
                    "left foreleg"   : ({ 0, 27, 0, 0, 3, 2, 1, 0, 1 }),
                    "head"           : ({ 0, 37, 0, 0, 4, 2, 1, 2, 2 })
                 ]);
    }
  else if (str == "dragon" || str == "bird")
    {
                                       // hp mx bl rm ml di ch e1 e2
      location = ([ "tail"           : ({ 0, 26, 0, 0, 2, 1, 1, 0, 0 }),
                    "right hind leg" : ({ 0, 33, 0, 0, 2, 1, 1, 0, 0 }),
                    "left hind leg"  : ({ 0, 33, 0, 0, 2, 1, 1, 0, 0 }),
                    "back part"      : ({ 0, 41, 0, 0, 2, 4, 0, 1, 0 }),
                    "front part"     : ({ 0, 41, 0, 0, 2, 6, 0, 1, 0 }),
                    "right wing"     : ({ 0, 26, 0, 0, 2, 1, 1, 0, 0 }),
                    "left wing"      : ({ 0, 26, 0, 0, 2, 1, 1, 0, 0 }),
                    "right foreleg"  : ({ 0, 33, 0, 0, 2, 1, 1, 0, 1 }),
                    "left foreleg"   : ({ 0, 33, 0, 0, 2, 1, 1, 0, 1 }),
                    "head"           : ({ 0, 34, 0, 0, 2, 2, 1, 2, 2 })
                 ]);
    }
  else if (str == "worm")
    {
                                       // hp mx bl rm ml di ch e1 e2
      location = ([ "tail"           : ({ 0, 33, 0, 0, 6, 6, 1, 0, 0 }),
                    "body"           : ({ 0, 33, 0, 0, 8, 8, 0, 0, 0 }),
                    "head"           : ({ 0, 33, 0, 0, 6, 6, 1, 2, 0 })
                 ]);
    }

  k = keys(location);

  for (int i=0;i<sizeof(k);i++)
    location[k[i]][0] = THOB->query_max_hp()*location[k[i]][1]/100;

  return sizeof(k);
}

mapping
query_limbs ()
{
  return location;
}

string
query_location ()
{
  string *k = ({ }), *l = ({ });

  k = keys(location);

  if (sizeof(k) > 1) {
    l = ({ k[0] });
    location[k[0]][4]--;
  }

  for (int i=0;i<sizeof(k);i++)
    {
      for (int j=0;j<location[k[i]][4];j++)
        l += ({ k[i] });
    }

  return l[random(sizeof(l))];
}

int
init_battle (object ob)
{
  turn = 0;
  pending = 0;
  melee = 0;
  round = 0;

  if (member_array(ob, battle) == -1)
    {
      if (!battle)
        battle = ({ ob });
      else
        battle += ({ ob });

        if(!interactive(THOB))
           THOB->add_aggressive(ob->query_name());
      debug ("init_battle", ob->query_name() + " ok");
      return 1;
    }
  else
    {
      debug ("init_battle", ob->query_name() + " failed");
      return 0;
    }
}

int
end_battle (object ob)
{
  if (!ob)
    {
      battle = ({ });
      return 1;
    }

  if (member_array(ob, battle) == -1)
    {
      debug ("end_battle", ob->query_name() + " failed");
      return 0;
    }
  else
    {
      battle -= ({ ob });
      debug ("end_battle", ob->query_name() + " ok");
      return 1;
    }
}

int
battle_beat ()
{
  object vict;
  string loc;
  int dam, how, chance, attack, n, t, suc, fail, crit, special, fumble;

  if (!battle || sizeof(battle) == 0)
    {
      // debug ("battle_beat", "failed");
      return 0;
    }
  else
    {

      vict = battle[random(sizeof(battle))];

      if (!vict || ENV(vict) != ENV(THOB)) {
        if (vict)
          {
        vict->end_battle (THOB);
        THOB->end_battle (vict);
          }
        else
        THOB->end_battle (0);
        return 0;
      }

      attack = query_agi_turn();

      switch (THOB->query_siz())
        {
          case 0..9:
            attack += 0;
            break;
          case 10..15:
            attack += -1;
            break;
          case 16..19:
            attack += -2;
            break;
          default:
            attack += -3;
            break;
        }

      attack += random(2);
      attack -= (THOB->query_ep()*100/THOB->query_max_ep())/50;

      if (attack > 9)
        attack = 9;

      if (attack < 2)
        attack = 2;

      n = 0;
      t = 0;

      n += attack;

      if (!round)
        round = 1;

      turn++;
      melee++;

      if (melee>10) {
        emote (THOB, "*** new round ***");
        round++;
        pending = 0;
        melee = 1;

        if (penalty == 1)
          {
            emote (THOB, vict->query_cap_name() + " seems to be ready to strike back!");
            emote (vict, "You are now able to fight!");
          }

        if (penalty)
          penalty--;

        THOB->add_ep (-1);
      }

      if (pending == 0 || pending>10)
        pending = attack;

      // emote (THOB, sprintf ("turn: %3d melee: %3d pending: %3d round: %3d",
      // turn, melee, pending, round));

      while (1)
        {
          t++;

          if (penalty)
            break;

          if (t==2) {
            // THOB->add_ep (-1);
            break;
          }

          // tell_object (THOB, ""+t+" (pending "+n+"):\n");

          // if (t!=n)
          //  continue;
          // else
          //  n += attack;

          if (melee != pending) {
            break;
          }

          pending += attack;

      debug ("battle_beat", "new round");
      
      chance = random(100) + 1;
      dam = random(6)+3;

      switch (THOB->query_siz() + THOB->query_str())
        {
          case 0..12:
            dam -= random(4);
            break;
          case 13..24:
            dam += 0;
            break;
          case 25..32:
            dam += random(4);
            break;
          case 33..40:
            dam += random(6);
            break;
          case 41..56:
            dam += random(6)+random(6);
            break;
          case 57..73:
            dam += random(6)+random(6)+random(6);
            break;
          case 74..90:
            dam += random(6)+random(6)+random(6)+random(6);
            break;
          case 91..99:
            dam += random(6)+random(6)+random(6)+random(6)+random(6);
            break;
          default:
            dam += (THOB->query_str()+THOB->query_siz())/3;
            break;
        }

      if (present("uncon", vict)) {
        chance = 1;
        dam++;
      }

      suc  = THOB->query_dex() + THOB->query_agi();
      fail = 100 - suc;

      if (chance < 1)
        chance = 1;

      crit = 0;
      special = 0;
      fumble = 0;

      if (chance*100/suc < 6)
      {
        crit = 1;
      }
      else if (chance*100/suc < 21)
      {
        special = 1;
      }
      else if (chance > 96)
      {
        fumble = 1;
      }

      if (crit) {
        emote (THOB, "^cGYou score a CRITICAL hit!^c0");
        dam += 10;
      }        

      if (fumble) {
        emote (THOB, "You fumble your attack.");
        continue;
      }

      if (dam > 40)
        dam = 40;

      if (dam < 1)
        dam = 1;

      if (vict->query_resting())
        vict->force_us("stand");

      if (random(202) < vict->query_skill_chance("dodge"))
      {
        if (crit)
          {
            emote (vict, vict->query_cap_name() + " tries foolishly dodge your critical strike!");
            emote (THOB, "You try foolishly dodge "+vict->query_cap_name()+"'s critical strike.");
          }
        else
          {
            emote (THOB, vict->query_cap_name() + " dodges your attack.");
            emote (vict, "You dodge "+THOB->query_cap_name()+"'s attack.");

        message ("0", vict->query_cap_name()+" dodges "+
          THOB->query_cap_name()+"'s attack.\n", ENV(THOB), ({THOB,vict}));
            continue;
          }
      }

      if (THOB->query_kills()) {
        chance -= (THOB->query_kills()[vict->query_race()]/3);
        dam += (THOB->query_kills()[vict->query_race()]/20);
      }

      if (crit || (dam && chance < (THOB->query_dex() + THOB->query_agi())))
        {
          loc = vict->query_location(random(20));

          if (vict->query_limbs()[loc] && vict->query_limbs()[loc][0] == 0)
            how = 9;
          else if ((dam*100/vict->query_limbs()[loc][0]) == 0)
            how = 0;
          else
            how = (dam*100/vict->query_limbs()[loc][0])/10;

          if (how > 9)
            how = 9;

          if (how < 0)
            how = 0;

          emote (THOB, "You "+physical_damage[dam/2]+" "+
            vict->query_cap_name()+"'s "+loc+" "+physical_limb[how]+".");

          emote (vict, THOB->query_cap_name()+" "+
            pluralize(physical_damage[dam/2])+
            " your "+loc+" "+physical_limb[how]+".");

          message ("0", THOB->query_cap_name()+" "+
            pluralize(physical_damage[dam/2])+" "+vict->query_cap_name()+"'s "+
            loc+" "+physical_limb[how]+".\n", ENV(THOB), ({THOB,vict}));

/* this for skill
          if ((dam>vict->query_siz())%5 && random(100) < vict->query_agi())
            {
              emote (vict, "You are knocked "+
                ((dam-vict->query_siz())%5)+" meters back by the force of "+
                THOB->query_cap_name()+"'s furious attack!");
              vict->add_penalty((dam-vict->query_siz())%5);

              emote (THOB, "You knock "+vict->query_cap_name()+" down for "+((dam-vict->query_siz())%5)+" rounds.");

              t = 0;
            }
*/

          vict->damage_me (dam, 0, loc);
        }
      else
        {
          emote (THOB, "You miss "+vict->query_cap_name()+".");
          emote (vict, THOB->query_cap_name()+" misses you.");

          message ("0", THOB->query_cap_name()+" misses "+
            vict->query_cap_name()+".\n", ENV(THOB), ({THOB,vict}));
        }
      }

      return 1;
    }
}

int
damage_me (int dam, int type, string loc)
{
  int i, n;
  string *k;
  // object ob;

  debug ("damage_me", "" + dam + " " + type + " " + loc + "");

  k = keys(location);
  i = member_array(loc, k);

  if (!loc || i == -1)
    {
      n = random(sizeof(k));
      location[k[n]][0] -= dam;
      if (location[k[n]][0] == 0)
        location[k[n]][0] -= 1;

      if (location[k[n]][0] < 0) {
        tell_area (THOB, "You hear a sound of a bloody slash and a "+
          "scream right after.\n", all_inventory(ENV(THOB)));
        emote (THOB, "A large amount of ^cRBLOOD^c0 pours from your "+k[n]+".");
        location[k[n]][2]++;
        location[k[n]][0] -= random(5);
        THOB->add_hp (-random(5));
      }
    }
  else
    {
      location[k[i]][0] -= dam;
      if (location[k[i]][0] == 0)
        location[k[n]][0] -= 1;

      if (dam*2 > THOB->query_max_hp()*location[k[i]][1]/100 &&
          location[k[i]][0]<0 && !location[k[i]][3])
      {
        if (location[k[i]][L_CH])
          {
            emote (THOB, "Your "+k[i]+" is choped off.");
            emote (PREV, THOB->query_cap_name()+"'s "+k[i]+" drops down by the force of your attack.");
            location[k[i]][L_RM] = 2;
          }
      }
      else
      if (!location[k[i]][L_RM] && location[k[i]][0] < 0) {
        tell_area (THOB, "You hear a sound of a bloody slash and a "+
          "scream right after.\n", all_inventory(ENV(THOB)));
        emote (THOB, "A large amount of ^cRBLOOD^c0 pours from your "+k[i]+".");
        ENV(THOB)->add_blood (1);
        location[k[i]][2]++;
        location[k[i]][0] -= random(5);
        THOB->add_hp (-random(5));
      }
    }

  THOB->add_hp(-dam);

  if (dam > (THOB->query_hp() / 2))
    {
      if (!present("uncon", THOB))
        emote(PREV, THOB->query_cap_name()+" whimpers in pain.");

      emote(THOB, "^cWThat really ^cRHURT!^c0");
    }

  if (THOB->query_hp() < 0 && !present("uncon", THOB))
    {
      message("0", THOB->query_cap_name()+" falls into unconsciousness.\n", ENV(THOB), THOB);
      emote(THOB, "The world goes dark.");

      THOB->die (PREV);

      // ob = clone_object ("/obj/uncon_ob");
      // ob->set_victim (THOB);
      // ob->set_killer (PREV);
      // ob->move (THOB);

      // if (THOB->query_alignx() < 0)
      //  PREV->add_alignx (THOB->query_alignx() / 10);
      // else
      //  PREV->add_alignx (-THOB->query_alignx() / 10);

      // for (int j=0;j<sizeof(battle);j++)
      //  battle[j]->end_battle(THOB);

      battle = ({ });
    }

  return dam;
}
